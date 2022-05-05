#include "Dijkstra.h"
#include "Graph.h"
#include "Heap.h"
#include "Helpers.h"
/*zwraca prawde jesli waga krawędzi a jest mniejsza od wagi krawędzi b*/
bool Dijkstra::compEdge(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

Dijkstra::Dijkstra(Graph &g) : g(g), pathsHeap(compEdge) {
    d = new long long[g.getN()];//tworzymy tablice dystansów
    from = new int[g.getN()];//tworzy tablice poprzedników
    for (int i = 0; i < g.getN(); i++) {
        d[i] = INF_PATH;//wszystkim elementom tablicy przypisujemy nieskończoność
        from[i] = -1;//wszytskim elementom tablicy przypisujemy wartość ktora nie oznacza wierzchołka (-1)
    }
}

void Dijkstra::run() {
    pathsHeap.push(Edge(-1, g.getStart(), 0));//Dodajemy element do Heapa
    bool *isDone = new bool[g.getN()];//tworzymy tablice n-elementową 
    fill(isDone, g.getN(), false);//Wypełniamy tablice fałszami

    d[g.getStart()] = 0;//Droga od wierzchołka startowego do niego to zawsze 0
    while (!pathsHeap.empty()) {//sprawdzamy czy Heap jest pusty
        Edge path = pathsHeap.pop();//zdejmujemy korzeń Heap
        if (isDone[path.to]) /// jezeli wierzcholek byl juz przetworzony
            continue;
        isDone[path.to] = true;//przypisujemy mu prawde

        DynamicArray<Edge> adj = g.getEdges(path.to);//tworzymy wektor krawędzi wychodzących z danego wierzchołka
        for (int i = 0; i < adj.size(); i++) {
            Edge e = adj[i];
            long long newDist = d[e.from] + e.weight;//przypisujemy dystansowi suma dojścia do wierzchołka początkowego krawędzi i wage tej krawędzi
            if(newDist >= d[e.to]) /// jezeli rozpatrywana sciezka nie jest krotsza niż wcześniejza odległość do wierzchołka końcowego krawędzi
                continue;

            d[e.to] = newDist;//przypisujemy nowy dystans
            from[e.to] = e.from;//do poprzedników dodajemy wierzcholek poczatkowy krawędzi
            pathsHeap.push(Edge(e.from, e.to, newDist));//dodajemy krawędź do Heapa
        }
    }

    delete[] isDone;//usuwamy tablice
}

/*zwracanie ścieżki do wierzcholka końcowego endV*/
DynamicArray<int> Dijkstra::restorePath(int endV) const{
    if(d[endV] == INF_PATH) /// sciezka nie istnieje
        return DynamicArray<int>();

    int v = endV;//
    DynamicArray<int> res;//vector
    while (v != -1) {
        res.push(v);//Dodajemy wierzcholek do wektora
        v = from[v];//przypisujemy v numer jego poprzednika
    }
    reverse(res.begin(), res.end());//odwrócenie vectora
    return res;
}
/*zwraca dystans*/
long long Dijkstra::getDistance(int v) const {
    return d[v];
}
/*usuwanie*/
Dijkstra::~Dijkstra() {
    delete[] d;//usuniecie tablicy dystansow
    delete[] from;//usuniecie tablicy poprzedników
}
/*zapisanie rozwiązania do pliku*/
void Dijkstra::saveAllPaths(const char *filename) const{
    std::ofstream stream(filename);//otwarcie pliku
    for(int to = 0; to<g.getN(); to++){
        auto path = restorePath(to);//ścieżki dojścia do kolejnych wierzchołków
        long long dist = getDistance(to);//dystans do kolejnych wierzchołków
        if(dist != INF_PATH){ /// jezeli istnieje sciezka do wierzcholka
            stream << g.getStart() << " ---> " << to
                        << "\t dystans: "<<dist<<"\t ścieżka: ";//zapis do pliku
            for(int i = 0; i<path.size(); i++){
                auto v = path[i];
                stream << v << " ";//zapis kolejnych wierzchołków na ścieżce
            }
            stream << "\n";
        }
    }
    stream.close();//zamkniecie pliku
}



