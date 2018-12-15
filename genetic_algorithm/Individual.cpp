#include "Individual.h"

Individual::Individual(std::vector<int> &new_genotype, Problem *to_solve) {
    initialize_rnd_engine();
    genotype = &new_genotype;
    fitness = 0;
    problem = to_solve;
}

Individual::Individual(Problem *to_solve) {
    initialize_rnd_engine();
    problem = to_solve;
    fitness = 0;
    generate_genotype();
}

Individual::Individual(Individual &other) {
    initialize_rnd_engine();
    fitness = other.fitness;
    problem = other.problem;
    std::vector<int> *temp = other.genotype;
    genotype = new std::vector<int>(*temp);
}

void Individual::initialize_rnd_engine(){
    std::random_device rd;
    rand = std::mt19937(rd());
}

void Individual::mutate(double mut_prob) {
    std::uniform_real_distribution<double> mut_dis(0, mut_prob);
    std::uniform_int_distribution<int> inv_dis(1,genotype->size()-2);
    if (mut_dis(rand) <= mut_prob){
        int first = inv_dis(rand);
        int second = inv_dis(rand);
        while (first == second){
            second = inv_dis(rand);
        }
        if (first > second){
            int temp = first;
            first = second;
            second = temp;
        }
        while (first < second){
            swap_at(first,second);
            first++;
            second--;
        }
    }
}

void Individual::swap_at(int first, int second) {
    int temp = genotype->at(first);
    genotype->at(first) = genotype->at(second);
    genotype->at(second) = temp;
}



std::vector<Individual*> Individual::crossover(Individual &other) {
    std::uniform_int_distribution<> dis(0, genotype->size()-1);
    std::vector<int> *fst_genotype = new std::vector<int>(genotype->size());
    std::vector<int> *snd_genotype = new std::vector<int>(genotype->size());
    int div_point = dis(rand);
    for (int i = 0;i<div_point;i++) {
        fst_genotype->at(i) = this->genotype->at(i);
        snd_genotype->at(i) = other.genotype->at(i);
    }
    for (int j = div_point;j<genotype->size();j++){
        fst_genotype->at(j) = other.genotype->at(j);
        fst_genotype->at(j) = this->genotype->at(j);
    }
    return  std::vector<Individual*> {new Individual(*fst_genotype,problem),
                                      new Individual(*snd_genotype,problem)};
}

Individual::~Individual() {
    delete genotype;
}

void Individual::measure_fitness() {
    fitness = problem->measure_fitness(genotype);
}

void Individual::generate_genotype() {
    std::uniform_int_distribution<> dis(0,1);
    genotype = new std::vector<int>(problem->get_individual_length());
    for (int index = 0;index<genotype->size();index++){
        int gene = dis(rand);
        genotype->at(index) = gene;
    }
}

std::vector<int> Individual::get_genotype() {
    return *genotype;
}

int Individual::get_fitness() {
    return fitness;
}

