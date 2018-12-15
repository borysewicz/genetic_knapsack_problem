#ifndef LISTA4_INDIVIDUAL_H
#define LISTA4_INDIVIDUAL_H

#include  <vector>
#include <random>
#include "Problem.h"

class Individual {
public:
    Individual(std::vector<int> &new_genotype, Problem *to_solve);
    Individual(Problem *to_solve);
    Individual(Individual &other);
    void mutate(double mut_prob);
    std::vector<Individual*> crossover(Individual &other);
    //void crossover(Individual &other, Individual*& child1, Individual*& child2);
    void measure_fitness();
    int get_fitness();
    std::vector<int> get_genotype();
    ~Individual();


private:
    void generate_genotype();
    void initialize_rnd_engine();
    void swap_at(int first, int second);
    std::vector<int> *genotype;
    Problem *problem;
    std::mt19937 rand;
    int fitness;
};


#endif //LISTA4_INDIVIDUAL_H
