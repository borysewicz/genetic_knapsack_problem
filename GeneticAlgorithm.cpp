#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(double crossover, double mutation, int iter) {
    cross_prob = crossover;
    mut_prob = mutation;
    iterations = iter;
}

int GeneticAlgorithm::get_result() {
    return 0;
}

void GeneticAlgorithm::run_algorithm() {

}

