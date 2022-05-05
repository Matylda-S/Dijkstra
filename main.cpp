#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GraphAdjList.h"
#include "GraphAdjMatrix.h"
#include "Dijkstra.h"
#include "TimeMeasure.h"

int MAX_EDGE_VAL = 1000;
/*Znalezienie najkrótszej drogi dla danej liczby grafów */
void genAndSolveMany(int amountOfTests, int graphSizes, double density, TimeMeasure &timerAdjList, TimeMeasure &timerMatrix){
    for(int i = 0; i<amountOfTests; i++){
        GraphAdjList gAdjList;//graf na liście
        gAdjList.init(graphSizes);//zainicjowanie grafa na liście
        gAdjList.createRandomEdges(density, MAX_EDGE_VAL);//wylosowanie krawędxi

        GraphAdjMatrix gMatrix;//graf na macierzy
        gMatrix.copyFrom(gAdjList); /// skopiowanie z grafu na liści, by grafy byly takie same
/*znalezienie najkrótszej drogi grafu na macierzy*/
        Dijkstra dijkstra1(gMatrix);
        timerMatrix.start();
        dijkstra1.run();
        timerMatrix.pause();
/*znalezienie najkrótszej drogi grafu na macierzy*/
        Dijkstra dijkstra2(gAdjList);
        timerAdjList.start();
        dijkstra2.run();
        timerAdjList.pause();
    }
}
/*Testy*/
void coputeTests(){
    const int DENSITIES_CNT = 4;
    double densities[] {0.25, 0.5, 0.75, 1};//tablica gęstości

    const int VERTICES_CNT = 5;
    const int vertices[]{  // tablica ilosci wierzcholkow
        25, 50, 100, 500, 1000
    };

    const int AMOUNT_OF_TESTS = 100;
    cout << "n \t density \t timeAdjList \t timeMatrix \n";
    for(int j = 0; j < VERTICES_CNT; j++){
        for(int i = 0; i<DENSITIES_CNT; i++){
            double density = densities[i];
            int n = vertices[j];
            TimeMeasure timerAdjList, timerMatrix;
            genAndSolveMany(AMOUNT_OF_TESTS, n, density, timerAdjList, timerMatrix);//szukamy najkrótszej drogi dla poszczególnych grafów
            float totalTime1 = (float)timerAdjList.elapsed(); /// czas działania algorytmu dla 100 grafów na liście w milisekundach
            float totalTime2 = (float)timerMatrix.elapsed();//czas działania algorytmu dla 100 grafów na macierzy w milisekundach
            cout << n << " \t" << density << "\t\t" << totalTime1 <<"\t\t" << totalTime2 <<endl;
        }
    } /// DLACZEGO DLA PELNEGO GRAFU WERSJA MATRIX JEST WOLNIEJSZA???
}
/*czytanie z pliku i zapis garaf*/
void loadAndSaveGraphExample(const char* inPath, const char* outPath){
    GraphAdjList graph;
    graph.load(inPath);//czytanie z pliku
    graph.save(outPath);//zapis grafa do pliku
}
/*generowanie losowego grafa i zapis do pliku*/
void genAndSaveGraphExample(const char* outPath){
    GraphAdjList graph;
    graph.init(10);//inicjowanie wierzchołków
    graph.createRandomEdges(0.2,10);//losowanie krawędzi
    graph.save(outPath);//zapis do pliku
}
/*szukanie najkrkótszej drogi grafa z pliku i zapisanie wyników do pliku*/
/// Zakładamy że dany graf jest skierowany
/// Jeżeli jest nieskierowany nalezy dodać w pliku krawędzie w obie strony
void loadAndSolveToFileExample(const char *inFilename, const char *outFilename){
    GraphAdjList graph;
    graph.load(inFilename);//czytanie z pliku

    Dijkstra dijkstra(graph);
    dijkstra.run();//szukanie najkrótszej drogi
    dijkstra.saveAllPaths(outFilename);//zapis wyników do pliku
}

int main() {
    srand (time(nullptr));

   //genAndSaveGraphExample("graph.txt");
    //loadAndSaveGraphExample("graph.txt", "graph2.txt");
    loadAndSolveToFileExample("graph.txt", "paths.txt");
    coputeTests();
    return 0;
}

