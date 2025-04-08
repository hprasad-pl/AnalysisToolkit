#include "Histogram.h"
#include "Graph.h"

#include <iostream>

int main() {

    try {
        // Create a 1D histogram and fill it
        Histogram h1(Histogram::Type::TH1, "h1", "Sample Histogram", 50, 0, 10);
        for (int i = 0; i < 100; ++i)
            h1.Fill(static_cast<double>(i) / 10.0);

        h1.SaveToFile("hist.root");

        // Create a basic graph
        std::vector<double> x = {1, 2, 3, 4, 5};
        std::vector<double> y = {2, 4, 6, 8, 10};

        Graph g(x, y);
        g.SetTitle("Linear Graph");
        g.SetAxisTitles("X", "Y");
        g.SaveToFile("graph.root");

        std::cout << "Histogram and Graph saved successfully.\n";

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
