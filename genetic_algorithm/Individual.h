#ifndef LISTA4_INDIVIDUAL_H
#define LISTA4_INDIVIDUAL_H

#include  <vector>;
#include "Problem.h"

class Individual {
public:
    Individual(std::vector<int> &new_genotype);
    void mutate();
    std::vector<Individual> crossover(Individual &other);


private:
    std::vector<int> *genotype;
    Problem *problem;
};


#endif //LISTA4_INDIVIDUAL_H
