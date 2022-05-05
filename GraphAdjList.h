#ifndef DIJKSTRAANALYSER_GRAPHADJLIST_H
#define DIJKSTRAANALYSER_GRAPHADJLIST_H

#include "Graph.h"
class GraphAdjList : public Graph {
    DynamicArray<Edge> *g = NULL;
public:
    void addEdge(Edge edge) override;

    void init(int n) override;

    DynamicArray<Edge> getEdges(int from) const override;

    ~GraphAdjList();
};


#endif //DIJKSTRAANALYSER_GRAPHADJLIST_H
