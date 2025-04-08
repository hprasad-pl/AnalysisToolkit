#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "AnalysisToolkit.h"


class Histogram {
public:
    enum class Type { TH1, TH2 };

    Histogram(Type type, const std::string& name, const std::string& title,
              int nbinsX, double xmin, double xmax,
              int nbinsY = 0, double ymin = 0, double ymax = 0);

    Histogram(const Histogram& other);
    Histogram& operator=(const Histogram& other);

    Histogram(Histogram&& other) noexcept;
    Histogram& operator=(Histogram&& other) noexcept;

    ~Histogram();

    void SaveToFile(const std::string& filename, const std::string& option = "RECREATE") const;
    void LoadFromFile(const std::string& filename, const std::string& histname);

    TH1* GetHistogram() const;

    void SetName(const std::string& name);
    void SetTitle(const std::string& title);
    void SetXRange(double xmin, double xmax);
    void SetYRange(double ymin, double ymax);

    void Fill(double x, double y = 0);

private:
    void CreateHistogram();

    Type m_type;
    std::string m_name;
    std::string m_title;
    int m_nbinsX;
    double m_xmin, m_xmax;
    int m_nbinsY;
    double m_ymin, m_ymax;
    TH1* m_hist = nullptr;
};

#endif // HISTOGRAM_H
