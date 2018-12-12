#include <iostream>
#include "genetic_algorithm/Problem.h"
#include "knapsack_problem/KnapsackProblem.h"
#include "genetic_algorithm/GeneticAlgorithm.h"
#include "knapsack_problem/Item.h"

std::vector<Item> *load_items(){
    std::vector<Item> *loaded_items = new std::vector<Item>;
    loaded_items->push_back(Item(5,4));
    loaded_items->push_back(Item(1,1));
    loaded_items->push_back( Item(4,3));
    loaded_items->push_back( Item(3,2));
    return loaded_items;
}


int main() {
    std::vector<Item> *items = load_items();
    Problem *problem = new KnapsackProblem(items,5);
    GeneticAlgorithm alg;
    alg.assign_problem(problem);
    alg.run_algorithm();
    std::vector<int> result = alg.get_result();
    for (int i = 0; i < result.size(); i++) {
        std::cout << result.at(i) << " ";
    }
}


