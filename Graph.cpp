#include "Graph.h"
#include <fstream>
#include "Helpers.h"
/*zwraca liczbe wierzcholków*/
int Graph::getN() const {
    return n;
}
/*zwraca liczbe krawedzi*/
int Graph::getM() const{
    return m;
}
/*inicjowanie ilości wierzchołków*/
void Graph::init(int n) {
    this->n = n;
}


/*Stworzenie losowych krawędzi,gdzie dentisy to prawdopodobieństwo,a maxEdgeVal maksymalna waga krawędzi*/
void Graph::createRandomEdges(double density, int maxEdgeVal) {
    for (int p = 0; p < n; p++) {
        for (int v = 0; v < n; v++) {
            if (randBool(density)) {
                Edge edge(p, v, randInt(1, maxEdgeVal));//stworzenie krawędzi o losowej wadze
                addEdge(edge);//dodanie stworzonej krawędzi do grafu
            }
        }
    }
}

/*zwiekzenie liczby krawedzi*/
void Graph::addEdge(Edge edge) {
    m++;
}
/*ustawienie wierzcholka startoweego*/
void Graph::setStart(int start) {
    this->start = start;
}
/*zwrócenie wierzcholka startowego*/
int Graph::getStart() const{
    return start;
}
/*wczytanie grafu z pliku*/
/// Zakładamy że dany graf jest skierowany
/// Jeżeli jest nieskierowany nalezy dodać w pliku krawędzie w obie strony
void Graph::load(const char *path) {
    std::ifstream stream(path);//plik do odczytu
    int tmp_m;//zmienna pomocnicza
    stream >> tmp_m >> n >> start;//wczytanie ilości krawedzi,wierzchołków i wartość wierzchołka startowego
    this->init(n);
    m = 0;
    for (int i = 0; i < tmp_m; i++) {
        Edge newEdge;
        stream >> newEdge.from >> newEdge.to >> newEdge.weight;//wczytanie wierzchołka początkowego,końcowegoi wagi krawędzi
        this->addEdge(newEdge);//dodanie krawędzi do grafu
    }
    stream.close();//zamkniecie pliku
}
/*zapisanie grafu do pliku*/
void Graph::save(const char *path) const {
    std::ofstream stream(path);//otwarcie pliku do zapisu
    stream << m << " " << n  << " " << start << "\n";//zapisanie ilości krawedzi,wierzchołków i wierzchołka startowego
    for(int from = 0; from<n; from++){
        auto edges = getEdges(from);//stworzenie wektora krawędzi wychodzących z danego wierzcholka
        for(int i = 0; i<edges.size(); i++){//przechodzenie po kolejnych krawędziach ktore zaczynają się w tym samym wierzchołku
            Edge edge = edges[i];
            stream << edge.from << " " << edge.to << " " << edge.weight << "\n";//zapisanie wierzchołka początkowego,końcowegoi wagi krawędzi
    }}
    stream.close();//zamkniecie pliku
}
/*kopiowanie grafa*/
void Graph::copyFrom(Graph &g) {
    init(g.n);//zainicjowanie krawędzi
    for(int i = 0; i<n; i++){
        auto edges = g.getEdges(i);//stworzenie wektora krawędzi wychodzących z danego wierzchołka
        for(int j = 0; j<edges.size(); j++){
            auto edge = edges[j];
            this->addEdge(edge);//dodawanie kolejnych krawędzi
        }
    }
}


