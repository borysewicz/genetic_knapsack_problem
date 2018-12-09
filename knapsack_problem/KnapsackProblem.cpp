
#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem(std::vector<Item> loadedItems, int knap_size) {
    this->items = loadedItems;
    knapsack_size = knap_size;
}

int KnapsackProblem::measure_fitness(std::vector<int> &toMeasure) {
    int value = 0;
    int size = 0;
    for(int i = 0; i < toMeasure.size();i++){
        if (toMeasure.at(i) == 1){
            value += items.at(i).getValue();
            value+= items.at(i).getSize();
        }
    }
    if (size <= knapsack_size) return value;
    else return 0;
}


