#include "GraphAdjMatrix.h"
#include "Graph.h"
/*zainicjowanie grafu o n wierzchołkach*/
void GraphAdjMatrix::init(int n) {
    Graph::init(n);
    g = new int*[n];//tworzymy tablice wskaźników
    for(int i = 0; i<n; i++){
        g[i] = new int[n];//tworzymy poszczególne wiersze
        for(int j = 0; j<n; j++)
            g[i][j] = NO_CONNECTION;
    }
}
/*Dodawanie krawędzi*/
void GraphAdjMatrix::addEdge(Edge edge) {
    Graph::addEdge(edge);//zwiekszenie ilośći krawędzi
    g[edge.from][edge.to] = edge.weight;//wpisujemy wage krawedzi w odpowiednią komórkę
}
/*zwrócenie krawędzi grafu wychodzących z danego wierzchołka*/
DynamicArray<struct Edge> GraphAdjMatrix::getEdges(int from) const {
    DynamicArray<Edge> res;//vector
    res.resize(getN());//zmiana długości vectora
    for(int i = 0; i<n; i++){
        if(g[from][i] != NO_CONNECTION)//sprawdzenie czy krawedź istnieje
            res.push(Edge(from, i, g[from][i]));//Dodanie krawędzi
    }
    return res;//zwrócenie wektora
}
/*usuwanie grafu*/
GraphAdjMatrix::~GraphAdjMatrix() {
    if(g != nullptr){
        for(int i = 0; i<n; i++){
            delete[] g[i];//usuinięcie wierszy
        }
        delete[] g;//usunięcie tablicy
        g = nullptr;
    }
}
