cmake_minimum_required(VERSION 3.29)
project(myFirstProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(myFirstProject main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitBoard.cpp
        Solver/BFSSolver.h
        Solver/DFSSolver.h
        Solver/IDDFSSolver.h
)
