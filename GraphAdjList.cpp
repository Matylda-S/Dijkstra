#include "GraphAdjList.h"

/*zainicjowanie grafu*/
void GraphAdjList::init(int n) {
    Graph::init(n);//inicjowanie ilościwierzhcołków
    g = new DynamicArray<Edge>[n];//stworzenie tablicy list
}
/*Dodawanie krawędzi*/
void GraphAdjList::addEdge(Edge edge) {
    Graph::addEdge(edge);//zwiekszenie liczby krawędzi
    g[edge.from].push(edge);//zapisujemy krawedz w odpowiednie miejsce
}
/*uzyskanie krawędzi wychozących z danego wierzchołka*/
DynamicArray<Edge> GraphAdjList::getEdges(int from) const {
   return g[from];
}
/*usuwanie grafu*/
GraphAdjList::~GraphAdjList() {
    if(g!=nullptr){
        delete[] g;//usuniecie g
        g = nullptr;//przypisanie g wskaźnika pustego
    }
}
