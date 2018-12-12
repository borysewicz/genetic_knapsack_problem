
#ifndef LISTA4_PROBLEM_H
#define LISTA4_PROBLEM_H


#include <vector>

class Problem {
public:
    Problem(int ind_length){individual_length = ind_length;}
    virtual int  measure_fitness(std::vector<int> *toMeasure) = 0;
    int get_individual_length(){return individual_length;};
    virtual ~Problem();
private:
   int individual_length;
};


#endif //LISTA4_PROBLEM_H
