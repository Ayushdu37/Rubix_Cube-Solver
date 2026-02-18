//
// Created by Abdulla Khan on 17-10-2025.
//

#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
//#include "Model/RubiksCube1dArray.cpp"
// #include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
//#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {
    // RubiksCube3dArray object3DArray;
//    RubiksCube1dArray object1dArray;
//    RubiksCubeBitboard objectBitboard;
//
    // object3DArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";


//
//    objectBitboard.u();
//    object3DArray.u();
//    object1dArray.u();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.l();
//    object3DArray.l();
//    object1dArray.l();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.f();
//    object3DArray.f();
//    object1dArray.f();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.r();
    // object3DArray.r();
//    object1dArray.r();
//    objectBitboard.print();
    // object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.b();
//    object3DArray.b();
//    object1dArray.b();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.d();
//    object3DArray.d();
//    object1dArray.d();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    objectBitboard.dPrime();
//    object3DArray.dPrime();
//    object1dArray.dPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.bPrime();
//    object3DArray.bPrime();
//    object1dArray.bPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.rPrime();
//    object3DArray.rPrime();
//    object1dArray.rPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.fPrime();
//    object3DArray.fPrime();
//    object1dArray.fPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.lPrime();
//    object3DArray.lPrime();
//    object1dArray.lPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.uPrime();
//    object3DArray.uPrime();
//    object1dArray.uPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";

    // Create two Cubes ------------------------------------------------------------------------------------------

//    RubiksCube3dArray cube1;
//    RubiksCube3dArray cube2;

//    RubiksCube1dArray cube1;
//    RubiksCube1dArray cube2;

//    RubiksCubeBitboard cube1;
//    RubiksCubeBitboard cube2;


//  Equality and assignment of cubes --------------------------------------------------------------------------

//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube1.randomShuffleCube(1);
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube2 = cube1;
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";


//  Unordered_map of Cubes  ------------------------------------------------------------------------------------


//    unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

//    unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

//    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
//
//    mp1[cube1] = true;
//    cube2.randomShuffleCube(8);
//    if (mp1[cube1]) cout << "Cube1 is present\n";
//    else cout << "Cube1 is not present\n";
//
//    if (mp1[cube2]) cout << "Cube2 is present\n";
//    else cout << "Cube2 is not present\n";
//

// DFS Solver Testing __________________________________________________________________________________________
    RubiksCube3dArray cube;
    // cube.print();

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    auto start = chrono::high_resolution_clock::now();
    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 5);
    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    auto end = chrono::high_resolution_clock::now();
    double dfs_time = chrono::duration<double, milli>(end - start).count();

    long long dfs_space = dfsSolver.getSpaceUsed();

    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    dfsSolver.rubiksCube.print();




//BFS Solver -----------------------------------------------------------------------------------------------------
     RubiksCubeBitboard cube1;
     // cube.print();
     vector<RubiksCube::MOVE> shuff_moves = cube1.randomShuffleCube(7);
     for(auto move: shuff_moves) cout << cube1.getMove(move) << " ";
     cout << "\n";
     cube1.print();
     auto start2 = chrono::high_resolution_clock::now();
     BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube1);
     vector<RubiksCube::MOVE> solved_moves = bfsSolver.solve();
     auto end2 = chrono::high_resolution_clock::now();

     cout << "Ok The Cube is Solved these are the steps to perform" << "\n";

    double bfs_time = chrono::duration<double, milli>(end2 - start2).count();
    long long bfs_space = bfsSolver.getSpaceUsed();

     for(auto move: solved_moves) cout << cube1.getMove(move) << " ";
     cout << "\n";
     bfsSolver.rubiksCube.print();



// IDDFS Solver ----------------------------------------------------------------------------------------------------
    RubiksCubeBitboard cube3;
    // cube3.print();

    vector<RubiksCube::MOVE> shuffle_moves3 = cube3.randomShuffleCube(7);
    for (auto move: shuffle_moves3) cout << cube3.getMove(move) << " ";
    cout << "\n";
    cube3.print();

    auto start3 = chrono::high_resolution_clock::now();
    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube3, 7);
    vector<RubiksCube::MOVE> solve_moves3 = iddfsSolver.solve();
    auto end3 = chrono::high_resolution_clock::now();

    double iddfs_time = chrono::duration<double, milli>(end3 - start3).count();
    long long iddfs_space = iddfsSolver.getSpaceUsed();

    for (auto move: solve_moves3) cout << cube3.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();

    cout << "DFS JUMBLED DEPTH " << 7 << endl;
    cout << "DFS TIME : " << dfs_time << "ms" << endl;
    cout << "NODES EXPLORED " << dfs_space << endl;
    cout << endl;

    cout << "BFS JUMBLED DEPTH " << 7 << endl;
    cout << "BFS TIME : " << bfs_time << "ms" << endl;
    cout << "NODES EXPLORED " << bfs_space << endl;
    cout << endl;

    cout << "IDDFS JUMBLED DEPTH " << 7 << endl;
    cout << "IDDFS TIME : " << iddfs_time << "ms" << endl;
    cout << "NODES EXPLORED " << iddfs_space << endl;


// CornerPatternDatabase Testing ---------------------------------------------------------------------------------

//    CornerPatternDatabase cornerDB;
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 5);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cube.randomShuffleCube(1);
//    cube.print();
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 6);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";


// CornerDBMaker Testing --------------------------------------------------------------------------


//    Code to create Corner Database
    string fileName = "C:\\Users\\DELL\\CLionProjects\\myFirstProject\\Databases\\mySolver.txt";


    // try {
    //     // Code to create Corner Database
    //     CornerDBMaker dbMaker(fileName, 0x99);
    //     dbMaker.bfsAndStore();
    // } catch (const std::bad_alloc& e) {
    //     std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    //     return EXIT_FAILURE; // Indicate failure
    // } catch (const std::exception& e) {
    //     std::cerr << "An error occurred: " << e.what() << std::endl;
    //     return EXIT_FAILURE; // Indicate failure
    // } catch (...) {
    //     std::cerr << "An unknown error occurred." << std::endl;
    //     return EXIT_FAILURE; // Indicate failure
    // }



    // cout << "----------------------------------------------" << endl;
    // cout << "Master I have solved the cube on your command " << "\n";
    // cout << "----------------------------------------------" << endl;

    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    // try {
    //     string fileName = "C:\\Users\\DELL\\CLionProjects\\myFirstProject\\Databases\\cornerDepth5V1.txt";
    //
    //     // Code to create and use the CornerPatternDatabase and IDAstarSolver
    //     RubiksCubeBitboard cube;
    //     auto shuffleMoves = cube.randomShuffleCube(13);
    //     cube.print();
    //     cout << "Shuffle moves are -> ";
    //     for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    //     cout << "\n";

    //     cout << endl << "----------------------------------------------" << endl;
    //     cout << "Master I have solved the cube on your command " << "\n";
    //     cout << "----------------------------------------------" << endl << endl;
    //
    //     cout << "The moves to solve are -> ";
    //     for (auto move: moves) cout << cube.getMove(move) << " ";
    //     cout << "\n";
    //     cout << endl << "------------------------------------------------" << endl;
    //     cout << "The Solved cube is" << endl;
    //     idaStarSolver.rubiksCube.print();
    //
    // } catch (const std::exception& e) {
    //     std::cerr << "Standard exception: " << e.what() << std::endl;
    // } catch (const char* msg) {
    //     std::cerr << "Caught an exception: " << msg << std::endl;
    // } catch (...) {
    //     std::cerr << "Caught an unknown exception!" << std::endl;
    // }


    return 0;
}