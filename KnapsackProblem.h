#ifndef LISTA4_KNAPSACKPROBLEM_H
#define LISTA4_KNAPSACKPROBLEM_H


#include <vector>
#include "Problem.h"
#include "Item.h"

class KnapsackProblem : Problem{
public:
    KnapsackProblem(std::vector<Item> loadedItems,int loadedSize);
    int measureGenotypeFitness(std::vector<int> &toMeasure);

private:
    std::vector<Item> items;
    int knapsackSize;
};


#endif //LISTA4_KNAPSACKPROBLEM_H
