#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int population_size,double crossover, double mutation, int iter) {
    cross_prob = crossover;
    mut_prob = mutation;
    iterations = iter;
    if (population_size > 0){
        population = new std::vector<Individual>(population_size); // TODO: data validation
    }
}

int GeneticAlgorithm::get_result() {
    return 0;
}

void GeneticAlgorithm::run_algorithm() {

    spawn_population();
    for (int i = 0;i<iterations;i++){

    }
}

GeneticAlgorithm::GeneticAlgorithm() : GeneticAlgorithm(def_population_size,def_cross_prob,def_mut_prob,def_iterations) {
}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete population;
}

int GeneticAlgorithm::get_population_size() {
    return 0;
}

void GeneticAlgorithm::spawn_population() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for (int i  = 0;i<population->size();i++){
        std::vector<int> *new_genotype = new std::vector<int>(problem->get_indivudal_length());
        for (int index = 0;index<new_genotype->size();index++){
            int gene = dis(gen);
            new_genotype->at(index) = gene;
        }
        population->push_back(new Individual(*new_genotype));
    }
}

