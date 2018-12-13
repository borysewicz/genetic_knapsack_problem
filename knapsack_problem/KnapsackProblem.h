#ifndef LISTA4_KNAPSACKPROBLEM_H
#define LISTA4_KNAPSACKPROBLEM_H



#include <vector>
#include <string>
#include "../genetic_algorithm/Problem.h"
#include "Item.h"
#include <iostream>


static int const CODE_NULL_ITEMS = -5;
static int const CODE_NEG_KNAP_SIZE = -6;

class KnapsackProblem : public Problem{
public:
    KnapsackProblem(std::vector<Item> *loadedItems,int knap_size);
    int measure_fitness(std::vector<int> *toMeasure);
    int validate_data();
    ~KnapsackProblem();

private:
    std::vector<Item> *items;
    int knapsack_size;
};


#endif //LISTA4_KNAPSACKPROBLEM_H
