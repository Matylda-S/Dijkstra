#ifndef DIJKSTRAANALYSER_TIMEMEASURE_H
#define DIJKSTRAANALYSER_TIMEMEASURE_H

#include <chrono>
#include <unistd.h>
using namespace std;
class TimeMeasure {
    std::chrono::steady_clock::time_point startPoint;
    long long elapsedTime = 0; /// in microseconds
public:
    void start();
    void pause();
    void reset();
    double elapsed() const; /// in miliseconds
};


#endif //DIJKSTRAANALYSER_TIMEMEASURE_H
