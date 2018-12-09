#ifndef LISTA4_GENETICALGORITHM_H
#define LISTA4_GENETICALGORITHM_H


#include "Problem.h"
#include "Individual.h"
#include <cstdlib>
#include <random>

static int def_population_size = 4;
static int def_iterations = 100;
static double def_cross_prob = 0.6;
static double def_mut_prob = 0.1;


class GeneticAlgorithm {

public:
    GeneticAlgorithm();
    GeneticAlgorithm(int population_size,double crossover,double mutation,int iter);
    void run_algorithm();
    int get_result();
    int get_population_size();
    ~GeneticAlgorithm();
private:
    void spawn_population();

    double cross_prob;
    double mut_prob;
    int iterations;
    Problem *problem;
    std::vector<Individual*> *population;

};


#endif //LISTA4_GENETICALGORITHM_H
