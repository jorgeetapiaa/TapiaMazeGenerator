#ifndef MYMAZEGENERATOR_HPP
#define MYMAZEGENERATOR_HPP

#include "MazeGenerator.hpp"
#include <vector>
#include <iostream>


class myMazeGenerator: public MazeGenerator
{
public:
    myMazeGenerator();



    // generateMaze() is given a reference to a Maze object.  Its job is
    // to generate a new maze within that Maze object.  
    void generateMaze(Maze& maze) override;

    bool checkVisitedCells(int, int);

    void recursiveMaze(Maze& maze, int, int);

private:
    int rows;
    int columns;
    int currentRow;
    int currentColumn;
    bool* visitedCells;

};

#endif 
