#ifndef LISTA4_GENETICALGORITHM_H
#define LISTA4_GENETICALGORITHM_H


#include "Problem.h"
#include "Individual.h"
#include <iostream>
#include <random>

static const int def_population_size = 100;
static const int def_iterations = 100;
static const double def_cross_prob = 0.6;
static const double def_mut_prob = 0.1;

static int const CODE_OK = 0;
static int const CODE_NEG_POP = -1;
static int const CODE_WNG_CROSS_PROB = -2;
static int const CODE_WNG_MUT_ERR = -3;
static int const CODE_NEG_ITER_ERR = -4;


class GeneticAlgorithm {

public:
    GeneticAlgorithm();
    GeneticAlgorithm(int population_size,double crossover,double mutation,int iter);
    void assign_problem(Problem *to_solve);
    int run_algorithm();
    std::vector<int> get_result();
    ~GeneticAlgorithm();
private:
    int validate_data();
    void spawn_population();
    void measure_fitness();
    void crossover();
    void mutate();
    void kill_pop();
    Individual* choose_parent();

    std::mt19937 rand;
    double cross_prob;
    double mut_prob;
    int iterations;
    int pop_size;
    Problem *problem;
    std::vector<Individual*> population;

};


#endif //LISTA4_GENETICALGORITHM_H
