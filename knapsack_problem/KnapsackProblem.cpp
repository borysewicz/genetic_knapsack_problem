#include <iostream>
#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem(std::vector<Item> *loadedItems, int knap_size)  : Problem(loadedItems->size()) {
    items = loadedItems;
    knapsack_size = knap_size;
}

bool KnapsackProblem::validate_data() {
    bool valid = true;
    if (items == nullptr){
        valid = false;
        std::cout << NULL_ITEMS << std::endl;
    }
    if (knapsack_size < 0){
        valid = false;
        std::cout << NEG_KNAP_SIZE << knapsack_size << std::endl;
    }
    return valid;
}

int KnapsackProblem::measure_fitness(std::vector<int> *toMeasure) {
    int value = 0;
    int size = 0;
    for(int i = 0; i < toMeasure->size();i++){
        if (toMeasure->at(i) == 1){
            value += items->at(i).getValue();
            size+= items->at(i).getSize();
        }
    }
    if (size <= knapsack_size) return value;
    else return 0;
}

KnapsackProblem::~KnapsackProblem() {
    delete items;
}


