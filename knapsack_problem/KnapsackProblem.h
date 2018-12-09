#ifndef LISTA4_KNAPSACKPROBLEM_H
#define LISTA4_KNAPSACKPROBLEM_H

static int def_knap_size = 10;


#include <vector>
#include "../genetic_algorithm/Problem.h"
#include "Item.h"

class KnapsackProblem : Problem{
public:
    KnapsackProblem(std::vector<Item> loadedItems,int knap_size);
    int measure_fitness(std::vector<int> &toMeasure);

private:
    std::vector<Item> items;
    int knapsack_size;
};


#endif //LISTA4_KNAPSACKPROBLEM_H
