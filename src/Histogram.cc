#include "Histogram.h"

Histogram::Histogram(Type type, const std::string& name, const std::string& title,
                     int nbinsX, double xmin, double xmax,
                     int nbinsY, double ymin, double ymax)
    : m_type(type), m_name(name), m_title(title),
      m_nbinsX(nbinsX), m_xmin(xmin), m_xmax(xmax),
      m_nbinsY(nbinsY), m_ymin(ymin), m_ymax(ymax) {
    CreateHistogram();
}

Histogram::Histogram(const Histogram& other)
    : m_type(other.m_type),
      m_name(other.m_name + "_copy"),
      m_title(other.m_title),
      m_nbinsX(other.m_nbinsX),
      m_xmin(other.m_xmin),
      m_xmax(other.m_xmax),
      m_nbinsY(other.m_nbinsY),
      m_ymin(other.m_ymin),
      m_ymax(other.m_ymax) {
    CreateHistogram();
    if (other.m_hist && m_hist) {
        m_hist->Add(other.m_hist);
    }
}

Histogram& Histogram::operator=(const Histogram& other) {
    if (this != &other) {
        m_type = other.m_type;
        m_name = other.m_name + "_copy";
        m_title = other.m_title;
        m_nbinsX = other.m_nbinsX;
        m_xmin = other.m_xmin;
        m_xmax = other.m_xmax;
        m_nbinsY = other.m_nbinsY;
        m_ymin = other.m_ymin;
        m_ymax = other.m_ymax;
        CreateHistogram();
        if (other.m_hist && m_hist) {
            m_hist->Add(other.m_hist);
        }
    }
    return *this;
}

Histogram::Histogram(Histogram&& other) noexcept
    : m_type(other.m_type),
      m_name(std::move(other.m_name)),
      m_title(std::move(other.m_title)),
      m_nbinsX(other.m_nbinsX),
      m_xmin(other.m_xmin),
      m_xmax(other.m_xmax),
      m_nbinsY(other.m_nbinsY),
      m_ymin(other.m_ymin),
      m_ymax(other.m_ymax),
      m_hist(other.m_hist) {
    other.m_hist = nullptr;
}

Histogram& Histogram::operator=(Histogram&& other) noexcept {
    if (this != &other) {
        if (m_hist) delete m_hist;
        m_type = other.m_type;
        m_name = std::move(other.m_name);
        m_title = std::move(other.m_title);
        m_nbinsX = other.m_nbinsX;
        m_xmin = other.m_xmin;
        m_xmax = other.m_xmax;
        m_nbinsY = other.m_nbinsY;
        m_ymin = other.m_ymin;
        m_ymax = other.m_ymax;
        m_hist = other.m_hist;
        other.m_hist = nullptr;
    }
    return *this;
}

Histogram::~Histogram() {
    if (m_hist) delete m_hist;
}

void Histogram::CreateHistogram() {
    if (m_hist) delete m_hist;

    if (m_type == Type::TH1) {
        m_hist = new TH1F(m_name.c_str(), m_title.c_str(),
                          m_nbinsX, m_xmin, m_xmax);
    } else if (m_type == Type::TH2) {
        if (m_nbinsY <= 0) {
            throw std::runtime_error("Number of Y bins must be positive for TH2 histogram");
        }
        m_hist = new TH2F(m_name.c_str(), m_title.c_str(),
                          m_nbinsX, m_xmin, m_xmax,
                          m_nbinsY, m_ymin, m_ymax);
    }

    m_hist->GetXaxis()->SetTitle("X Axis");
    if (m_type == Type::TH2) {
        m_hist->GetYaxis()->SetTitle("Y Axis");
    }

    m_hist->SetDirectory(nullptr);
}

void Histogram::SaveToFile(const std::string& filename, const std::string& option) const {
    if (!m_hist) return;

    std::unique_ptr<TFile> file(TFile::Open(filename.c_str(), option.c_str()));
    if (!file || file->IsZombie()) {
        throw std::runtime_error("Could not create file: " + filename);
    }

    m_hist->Write();
    file->Close();
}

void Histogram::LoadFromFile(const std::string& filename, const std::string& histname) {
    std::unique_ptr<TFile> file(TFile::Open(filename.c_str(), "READ"));
    if (!file || file->IsZombie()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    TH1* loadedHist = nullptr;
    file->GetObject(histname.c_str(), loadedHist);
    if (!loadedHist) {
        throw std::runtime_error("Histogram " + histname + " not found in file");
    }

    if (dynamic_cast<TH2*>(loadedHist)) {
        m_type = Type::TH2;
    } else {
        m_type = Type::TH1;
    }

    m_name = loadedHist->GetName();
    m_title = loadedHist->GetTitle();

    TAxis* xaxis = loadedHist->GetXaxis();
    m_nbinsX = xaxis->GetNbins();
    m_xmin = xaxis->GetXmin();
    m_xmax = xaxis->GetXmax();

    if (m_type == Type::TH2) {
        TAxis* yaxis = static_cast<TH2*>(loadedHist)->GetYaxis();
        m_nbinsY = yaxis->GetNbins();
        m_ymin = yaxis->GetXmin();
        m_ymax = yaxis->GetXmax();
    }

    if (m_hist) delete m_hist;
    m_hist = static_cast<TH1*>(loadedHist->Clone());
    m_hist->SetDirectory(nullptr);

    file->Close();
}

TH1* Histogram::GetHistogram() const {
    return m_hist;
}

void Histogram::SetName(const std::string& name) {
    m_name = name;
    if (m_hist) m_hist->SetName(name.c_str());
}

void Histogram::SetTitle(const std::string& title) {
    m_title = title;
    if (m_hist) m_hist->SetTitle(title.c_str());
}

void Histogram::SetXRange(double xmin, double xmax) {
    m_xmin = xmin;
    m_xmax = xmax;
    if (m_hist) m_hist->GetXaxis()->SetRangeUser(xmin, xmax);
}

void Histogram::SetYRange(double ymin, double ymax) {
    if (m_type != Type::TH2) {
        throw std::runtime_error("Y-axis range can only be set for TH2 histograms");
    }
    m_ymin = ymin;
    m_ymax = ymax;
    if (m_hist) {
        static_cast<TH2*>(m_hist)->GetYaxis()->SetRangeUser(ymin, ymax);
    }
}

void Histogram::Fill(double x, double y) {
    if (!m_hist) return;
    if (m_type == Type::TH1) {
        static_cast<TH1*>(m_hist)->Fill(x);
    } else {
        static_cast<TH2*>(m_hist)->Fill(x, y);
    }
}
