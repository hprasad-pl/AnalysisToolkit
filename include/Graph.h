// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "AnalysisToolkit.h"


class Graph {
public:
    enum class Type {
        TGraph,
        TGraphErrors,
        TGraphAsymmErrors
    };

    Graph(const std::vector<double>& x, const std::vector<double>& y);

    Graph(const std::vector<double>& x, const std::vector<double>& y,
          const std::vector<double>& ex, const std::vector<double>& ey);

    Graph(const std::vector<double>& x, const std::vector<double>& y,
          const std::vector<double>& exl, const std::vector<double>& exh,
          const std::vector<double>& eyl, const std::vector<double>& eyh);

    Graph(const Graph& other);
    Graph& operator=(const Graph& other);
    Graph(Graph&& other) noexcept;
    Graph& operator=(Graph&& other) noexcept;

    ~Graph() = default;

    TGraph* GetGraph() const;

    void SetTitle(const std::string& title);
    void SetAxisTitles(const std::string& xTitle, const std::string& yTitle);
    void SetLine(int color, int style, int width);
    void SetMarker(int color, int style, double size);
    void Draw(const std::string& option = "APL") const;
    void SaveToFile(const std::string& filename, const std::string& option = "RECREATE") const;
    void AddToMultiGraph(TMultiGraph* mg, const std::string& option = "") const;
    void Fit(const std::string& formula, const std::string& option = "");

private:
    void CreateGraph();
    void CopyStyle(const Graph& other);

    Type m_type;
    std::vector<double> m_x;
    std::vector<double> m_y;
    std::vector<double> m_ex;
    std::vector<double> m_ey;
    std::vector<double> m_exl;
    std::vector<double> m_exh;
    std::vector<double> m_eyl;
    std::vector<double> m_eyh;
    std::string m_title;
    std::string m_xTitle = "X Axis";
    std::string m_yTitle = "Y Axis";
    std::unique_ptr<TGraph> m_graph;
};


#endif // GRAPH_H
