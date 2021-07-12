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
    // to generate a new maze within that Maze object.  It is unwise to
    // assume that the Maze object will be in a particular state when
    // passed in, so it's not a bad idea to start by either removing all
    // walls or adding all walls (depending on the algorithm).
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
