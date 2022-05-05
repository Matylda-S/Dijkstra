#ifndef DIJKSTRAANALYSER_GRAPHADJMATRIX_H
#define DIJKSTRAANALYSER_GRAPHADJMATRIX_H

#include "Graph.h"

class GraphAdjMatrix : public Graph {
    /// jeżeli nie ma połaczenia nałożona będzie ta waga:
    static const int NO_CONNECTION = -(1e9);
    int **g = nullptr;
public:
    void init(int n) override;

    void addEdge(Edge edge) override;

    DynamicArray<struct Edge> getEdges(int from) const override;

    virtual ~GraphAdjMatrix();
};


#endif //DIJKSTRAANALYSER_GRAPHADJMATRIX_H
