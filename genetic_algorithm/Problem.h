
#ifndef LISTA4_PROBLEM_H
#define LISTA4_PROBLEM_H


#include <vector>

class Problem {
public:
    virtual int  measure_fitness(std::vector<int> &toMeasure) = 0;
    int get_indivudal_length(){return individual_length;};
private:
   int individual_length;
};


#endif //LISTA4_PROBLEM_H
