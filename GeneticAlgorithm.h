#ifndef LISTA4_GENETICALGORITHM_H
#define LISTA4_GENETICALGORITHM_H


#include "Problem.h"
#include "Individual.h"

class GeneticAlgorithm {

public:
    GeneticAlgorithm(double crossover,double mutation,int iter);
    void run_algorithm();
    int get_result();
    int get_population;
private:
    double cross_prob;
    double mut_prob;
    int iterations;
    Problem *problem;
    std::vector<Individual> population;
};


#endif //LISTA4_GENETICALGORITHM_H
