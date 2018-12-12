#ifndef LISTA4_KNAPSACKPROBLEM_H
#define LISTA4_KNAPSACKPROBLEM_H



#include <vector>
#include <string>
#include "../genetic_algorithm/Problem.h"
#include "Item.h"

static std::string NULL_ITEMS = "Null vector has been passed to knapsack.";
static std::string NEG_KNAP_SIZE = "Negative knapsack size: ";

class KnapsackProblem : public Problem{
public:
    KnapsackProblem(std::vector<Item> *loadedItems,int knap_size);
    int measure_fitness(std::vector<int> *toMeasure);
    bool validate_data();
    ~KnapsackProblem();

private:
    std::vector<Item> *items;
    int knapsack_size;
};


#endif //LISTA4_KNAPSACKPROBLEM_H
