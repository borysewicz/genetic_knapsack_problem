#ifndef LISTA4_GENETICALGORITHM_H
#define LISTA4_GENETICALGORITHM_H


#include "Problem.h"
#include "Individual.h"
#include <cstdlib>
#include <random>

static int def_population_size = 10;
static int def_iterations = 100;
static double def_cross_prob = 0.6;
static double def_mut_prob = 0.1;

static std::string NEG_POP_ERR = "Negative population: ";
static std::string WNG_CROSS_ERR = "Wrong crossover probability (has to be between 0 and 1: ";
static std::string WNG_MUT_ERR = "Wrong mutation probability (has to be be between 0 and 1: ";
static std::string NEG_ITER_ERR = "Negative number of iterations: ";


class GeneticAlgorithm {

public:
    GeneticAlgorithm();
    GeneticAlgorithm(int population_size,double crossover,double mutation,int iter);
    void assign_problem(Problem *to_solve);
    void run_algorithm();
    std::vector<int> get_result();
    ~GeneticAlgorithm();
private:
    bool validate_data();
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
