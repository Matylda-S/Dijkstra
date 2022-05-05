#ifndef DIJKSTRAANALYSER_GRAPH_H
#define DIJKSTRAANALYSER_GRAPH_H
#include <fstream>
#include "DynamicArray.h"
#include "Helpers.h"
/*krawędź*/
struct Edge{
    int from;//wierzcholek startowy
    int to;//wierzcholek koncowy
    long long weight;//waga
    Edge(){};
    Edge(int from, int to, long long weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
/*Graf*/
class Graph {
protected:
    int n = 0;//liczab wierzcholkow
    int m = 0;//liczba krawedzi
    int start = 0;//wierzcholek stratowy
public:
    int getN() const;
    int getM() const;
    virtual void init(int n);
    void setStart(int start);
    int getStart() const;
    virtual void addEdge(Edge edge);
    virtual DynamicArray<struct Edge> getEdges(int from) const = 0;
    void copyFrom(Graph &g);

    void createRandomEdges(double density, int maxEdgeVal);

    void load(const char *path);
    void save(const char *path) const;
};


#endif //DIJKSTRAANALYSER_GRAPH_H
