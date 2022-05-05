#include "TimeMeasure.h"
/*start zegara*/
void TimeMeasure::start() {
    startPoint = std::chrono::steady_clock::now();
}
//zatrzymanie zegaru i zliczenie czasu
void TimeMeasure::pause() {
    auto endPoint = std::chrono::steady_clock::now();
    auto elaps = chrono::duration_cast<chrono::microseconds>(endPoint - startPoint).count();//obliczenie czasu między punktem startowym a końcowym zegara
    elapsedTime += elaps;//Dodanie czasu do sumy czasów
}

double TimeMeasure::elapsed() const {
    return elapsedTime/1000.0;
}
/*reset zegara*/
void TimeMeasure::reset() {
    startPoint = std::chrono::steady_clock::now();//nowy start zegara
    elapsedTime = 0;//wyzerowanie dotychczasowego czasu
}




