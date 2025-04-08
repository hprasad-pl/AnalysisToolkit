// Graph.cc
#include "Graph.h"


Graph::Graph(const std::vector<double>& x, const std::vector<double>& y)
    : m_type(Type::TGraph), m_x(x), m_y(y) {
    CreateGraph();
}

Graph::Graph(const std::vector<double>& x, const std::vector<double>& y,
             const std::vector<double>& ex, const std::vector<double>& ey)
    : m_type(Type::TGraphErrors), m_x(x), m_y(y), m_ex(ex), m_ey(ey) {
    CreateGraph();
}

Graph::Graph(const std::vector<double>& x, const std::vector<double>& y,
             const std::vector<double>& exl, const std::vector<double>& exh,
             const std::vector<double>& eyl, const std::vector<double>& eyh)
    : m_type(Type::TGraphAsymmErrors), m_x(x), m_y(y),
      m_exl(exl), m_exh(exh), m_eyl(eyl), m_eyh(eyh) {
    CreateGraph();
}

Graph::Graph(const Graph& other)
    : m_type(other.m_type), m_x(other.m_x), m_y(other.m_y),
      m_ex(other.m_ex), m_ey(other.m_ey),
      m_exl(other.m_exl), m_exh(other.m_exh),
      m_eyl(other.m_eyl), m_eyh(other.m_eyh),
      m_title(other.m_title),
      m_xTitle(other.m_xTitle), m_yTitle(other.m_yTitle) {
    CreateGraph();
    CopyStyle(other);
}

Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        m_type = other.m_type;
        m_x = other.m_x;
        m_y = other.m_y;
        m_ex = other.m_ex;
        m_ey = other.m_ey;
        m_exl = other.m_exl;
        m_exh = other.m_exh;
        m_eyl = other.m_eyl;
        m_eyh = other.m_eyh;
        m_title = other.m_title;
        m_xTitle = other.m_xTitle;
        m_yTitle = other.m_yTitle;
        CreateGraph();
        CopyStyle(other);
    }
    return *this;
}

Graph::Graph(Graph&& other) noexcept = default;
Graph& Graph::operator=(Graph&& other) noexcept = default;

TGraph* Graph::GetGraph() const {
    return m_graph.get();
}

void Graph::SetTitle(const std::string& title) {
    m_title = title;
    if (m_graph) m_graph->SetTitle(title.c_str());
}

void Graph::SetAxisTitles(const std::string& xTitle, const std::string& yTitle) {
    m_xTitle = xTitle;
    m_yTitle = yTitle;
    if (m_graph) {
        m_graph->GetXaxis()->SetTitle(xTitle.c_str());
        m_graph->GetYaxis()->SetTitle(yTitle.c_str());
    }
}

void Graph::SetLine(int color, int style, int width) {
    if (m_graph) {
        m_graph->SetLineColor(color);
        m_graph->SetLineStyle(style);
        m_graph->SetLineWidth(width);
    }
}

void Graph::SetMarker(int color, int style, double size) {
    if (m_graph) {
        m_graph->SetMarkerColor(color);
        m_graph->SetMarkerStyle(style);
        m_graph->SetMarkerSize(size);
    }
}

void Graph::Draw(const std::string& option) const {
    if (m_graph) {
        m_graph->Draw(option.c_str());
    }
}

void Graph::SaveToFile(const std::string& filename, const std::string& option) const {
    if (!m_graph) return;
    std::unique_ptr<TFile> file(TFile::Open(filename.c_str(), option.c_str()));
    if (!file || file->IsZombie()) {
        throw std::runtime_error("Could not create file: " + filename);
    }
    m_graph->Write();
    file->Close();
}

void Graph::AddToMultiGraph(TMultiGraph* mg, const std::string& option) const {
    if (m_graph && mg) {
        mg->Add(m_graph.get(), option.c_str());
    }
}

void Graph::Fit(const std::string& formula, const std::string& option) {
    if (m_graph) {
        m_graph->Fit(formula.c_str(), option.c_str());
    }
}

void Graph::CreateGraph() {
    switch (m_type) {
        case Type::TGraph:
            m_graph = std::make_unique<TGraph>(m_x.size(), m_x.data(), m_y.data());
            break;
        case Type::TGraphErrors:
            if (m_ex.size() != m_x.size() || m_ey.size() != m_y.size()) {
                throw std::runtime_error("Error array sizes must match data array sizes");
            }
            m_graph = std::make_unique<TGraphErrors>(
                m_x.size(), m_x.data(), m_y.data(), m_ex.data(), m_ey.data());
            break;
        case Type::TGraphAsymmErrors:
            if (m_exl.size() != m_x.size() || m_exh.size() != m_x.size() ||
                m_eyl.size() != m_y.size() || m_eyh.size() != m_y.size()) {
                throw std::runtime_error("Error array sizes must match data array sizes");
            }
            m_graph = std::make_unique<TGraphAsymmErrors>(
                m_x.size(), m_x.data(), m_y.data(),
                m_exl.data(), m_exh.data(), m_eyl.data(), m_eyh.data());
            break;
    }

    if (m_graph) {
        m_graph->SetTitle(m_title.c_str());
        m_graph->GetXaxis()->SetTitle(m_xTitle.c_str());
        m_graph->GetYaxis()->SetTitle(m_yTitle.c_str());
        m_graph->SetMarkerStyle(20);
        m_graph->SetLineWidth(2);
    }
}

void Graph::CopyStyle(const Graph& other) {
    if (!m_graph || !other.m_graph) return;

    m_graph->SetLineColor(other.m_graph->GetLineColor());
    m_graph->SetLineStyle(other.m_graph->GetLineStyle());
    m_graph->SetLineWidth(other.m_graph->GetLineWidth());
    m_graph->SetMarkerColor(other.m_graph->GetMarkerColor());
    m_graph->SetMarkerStyle(other.m_graph->GetMarkerStyle());
    m_graph->SetMarkerSize(other.m_graph->GetMarkerSize());

    if (other.m_graph->GetHistogram()) {
        m_graph->GetXaxis()->SetRangeUser(
            other.m_graph->GetXaxis()->GetXmin(),
            other.m_graph->GetXaxis()->GetXmax());
        m_graph->GetYaxis()->SetRangeUser(
            other.m_graph->GetYaxis()->GetXmin(),
            other.m_graph->GetYaxis()->GetXmax());
    }
}


