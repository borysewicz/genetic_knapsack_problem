cmake_minimum_required(VERSION 3.12)
project(Lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista4 main.cpp KnapsackProblem.cpp KnapsackProblem.h Individual.cpp Individual.h GeneticAlgorithm.cpp GeneticAlgorithm.h Item.cpp Item.h Problem.cpp Problem.h)