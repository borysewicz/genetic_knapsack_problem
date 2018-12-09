cmake_minimum_required(VERSION 3.12)
project(Lista4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lista4 main.cpp knapsack_problem/KnapsackProblem.cpp knapsack_problem/KnapsackProblem.h genetic_algorithm/Individual.cpp genetic_algorithm/Individual.h genetic_algorithm/GeneticAlgorithm.cpp genetic_algorithm/GeneticAlgorithm.h knapsack_problem/Item.cpp knapsack_problem/Item.h genetic_algorithm/Problem.cpp genetic_algorithm/Problem.h file_parser/FileParser.cpp file_parser/FileParser.h)