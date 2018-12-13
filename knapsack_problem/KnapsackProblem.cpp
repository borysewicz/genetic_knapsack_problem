#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem(std::vector<Item> *loadedItems, int knap_size)   {
    items = loadedItems;
    knapsack_size = knap_size;
    if(loadedItems != nullptr){
        individual_length = loadedItems->size();
    }
}

int KnapsackProblem::validate_data() {
    if (items == nullptr){
       return CODE_NULL_ITEMS;
    }
    if (knapsack_size < 0){
        return CODE_NEG_KNAP_SIZE;
    }
    return 0;
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


