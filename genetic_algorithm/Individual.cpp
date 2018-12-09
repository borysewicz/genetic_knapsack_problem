

#include "Individual.h"

Individual::Individual(std::vector<int> &new_genotype) {
    genotype = &new_genotype;
}

void Individual::mutate() {

}

std::vector<Individual> Individual::crossover(Individual &other) {
    return std::vector<Individual>();
}
