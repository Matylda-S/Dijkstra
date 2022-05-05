#ifndef DIJKSTRAANALYSER_DIJKSTRA_H
#define DIJKSTRAANALYSER_DIJKSTRA_H

#include "Graph.h"
#include "Heap.h"

class Dijkstra {
    static bool compEdge(const Edge &a, const Edge &b);
public:
    Graph& g;
    Heap<Edge> pathsHeap;
    long long *d;//koszt
    int *from;//wierzcholek od ktorego szukamy najkrótszej drogi

    Dijkstra(Graph& g);
    void run();

    ///ZWRÓCI PUSTĄ LISTE JEŻELI SCIEŻKA NIE ISTNIEJE (GRAF MOŻE NIE BYC SPÓJNY)
    DynamicArray<int> restorePath(int endV) const;
    /// zwroci INF_PATH jezeli sciezka nie istnieje
    long long getDistance(int v) const;

    void saveAllPaths(const char* filename) const;

    ~Dijkstra();
};


#endif //DIJKSTRAANALYSER_DIJKSTRA_H
