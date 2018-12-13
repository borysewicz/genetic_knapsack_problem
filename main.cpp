#include <iostream>
#include "genetic_algorithm/Problem.h"
#include "knapsack_problem/KnapsackProblem.h"
#include "genetic_algorithm/GeneticAlgorithm.h"
#include "knapsack_problem/Item.h"

static std::string NEG_POP_ERR = "Negative, too small or odd population: ";
static std::string WNG_CROSS_ERR = "Wrong crossover probability (has to be between 0 and 1: ";
static std::string WNG_MUT_ERR = "Wrong mutation probability (has to be be between 0 and 1: ";
static std::string NEG_ITER_ERR = "Negative number of iterations: ";
static std::string NULL_ITEMS = "Null vector has been passed to knapsack.";
static std::string NEG_KNAP_SIZE = "Negative knapsack size: ";
static std::string RUN_OK = "Correct data passed, algorithm returned results";

std::vector<Item> *load_items(){
    std::vector<Item> *loaded_items = new std::vector<Item>;
    loaded_items->push_back(Item(5,4));
    loaded_items->push_back(Item(1,1));
    loaded_items->push_back( Item(4,3));
    loaded_items->push_back( Item(3,2));
    return loaded_items;
}

std::vector<Item> *load_items2(){
    std::vector<Item> *loaded_items = new std::vector<Item>;
    loaded_items->push_back(Item(5,1));
    loaded_items->push_back(Item(3,2));
    loaded_items->push_back( Item(5,4));
    loaded_items->push_back( Item(3,2));
    loaded_items->push_back(Item(2,5));
    return loaded_items;
}

std::string run_info(int err_code){
    std::string msg;
    switch (err_code){
        case CODE_OK: msg = RUN_OK;
            break;
        case CODE_NEG_POP: msg = NEG_POP_ERR;
            break;
        case CODE_WNG_CROSS_PROB: msg = WNG_CROSS_ERR;
            break;
        case CODE_WNG_MUT_ERR: msg = WNG_MUT_ERR;
            break;
        case CODE_NEG_KNAP_SIZE: msg = NEG_KNAP_SIZE;
            break;
        case CODE_NEG_ITER_ERR: msg = NEG_ITER_ERR;
            break;
        case CODE_NULL_ITEMS: msg = NULL_ITEMS;
            break;
    }
    return msg;
}


int main() {
    std::vector<Item> *items = load_items2();
    Problem *problem = new KnapsackProblem(items,10);
    GeneticAlgorithm alg(100,0.6,0.1,100);
    alg.assign_problem(problem);
    int code = alg.run_algorithm();
    std::cout << run_info(code) << std::endl;
    std::vector<int> result = alg.get_result();

    for (int i = 0; i < result.size(); i++) {
        std::cout << result.at(i) << " ";
    }
}


