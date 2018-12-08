

#ifndef LISTA4_PROBLEM_H
#define LISTA4_PROBLEM_H


#include <vector>

class Problem {
public:
    virtual int measureGenotypeFitness(std::vector<int> &toMeasure) = 0;
};


#endif //LISTA4_PROBLEM_H
