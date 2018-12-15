#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int population_size,double crossover, double mutation, int iter) {
    std::random_device rd;
    rand = std::mt19937(rd());
    cross_prob = crossover;
    mut_prob = mutation;
    iterations = iter;
    pop_size = population_size;
    if (population_size > 0){
        population =   std::vector<Individual*>(population_size);
    }
    problem = nullptr;
}

GeneticAlgorithm::GeneticAlgorithm() : GeneticAlgorithm(def_population_size,def_cross_prob,def_mut_prob,def_iterations) {
}

int GeneticAlgorithm::validate_data() {
    if (pop_size < 2 || pop_size%2 != 0){
        return CODE_NEG_POP;
    }
    if (cross_prob < 0 || 1 < cross_prob ){
        return CODE_WNG_CROSS_PROB;
    }
    if (mut_prob < 0 || 1 < mut_prob ){
        return CODE_WNG_MUT_ERR;
    }
    if (iterations < 0){
        return CODE_NEG_ITER_ERR;
    }
    return problem->validate_data();
}


int GeneticAlgorithm::run_algorithm() {
    int data_status = validate_data();
    if (data_status != CODE_OK){
        return data_status;
    }
    kill_pop();
    spawn_population();
    for (int i = 0;i<iterations;i++){
        measure_fitness();
        crossover();
        mutate();
    }
    measure_fitness();
    return CODE_OK;
}

void GeneticAlgorithm::spawn_population() {
    for (int i = 0;i<pop_size;i++){
        population.at(i) = (new Individual(problem));
    }
}

void GeneticAlgorithm::measure_fitness() {
    for (int i = 0; i < population.size();i++){
        population.at(i)->measure_fitness();
    }
}

void GeneticAlgorithm::crossover() {
    std::vector<Individual*> new_population(pop_size);
    int added = 0;
    std::uniform_real_distribution<double> dis(0, cross_prob);
    while (added < pop_size){
        Individual *first_parent = choose_parent();
        Individual *second_parent = choose_parent();
        if (dis(rand) < cross_prob){
           std::vector<Individual*> children =  first_parent->crossover(*second_parent);
           new_population.at(added) = children.at(0);
           new_population.at(added+1) = children.at(1);
        }
        else {
            new_population.at(added) = new Individual(*first_parent);
            new_population.at(added+1) =  new Individual(*second_parent);
        }
        added += 2;
    }
    kill_pop();
    population = new_population;
}


void GeneticAlgorithm::mutate() {
    for (int i = 0;i<pop_size;i++){
        population.at(i)->mutate(mut_prob);
    }
}


void GeneticAlgorithm::assign_problem(Problem *to_solve) {
    delete problem;
    problem = to_solve;
}

Individual* GeneticAlgorithm::choose_parent() {
    std::uniform_int_distribution<> dis(0, pop_size-1);
    Individual *first = population.at(dis(rand));
    Individual *second = population.at(dis(rand));
    return (first->get_fitness() > second->get_fitness() ? first : second);
}

std::vector<int> GeneticAlgorithm::get_result() {
    if (validate_data() != CODE_OK){
        return std::vector<int>();
    }

    int index_best = 0;
    int best_fitness = 0;
    for (int i = 0;i<pop_size;i++){
        if (population.at(i)->get_fitness() > best_fitness){
            index_best = i;
            best_fitness = population.at(i)->get_fitness();
        }
    }
    return population.at(index_best)->get_genotype();
}

GeneticAlgorithm::~GeneticAlgorithm() {
    kill_pop();
    delete problem;
}

void GeneticAlgorithm::kill_pop() {
    for (int i = 0;i<pop_size;i++){
        delete population.at(i);
    }
}

