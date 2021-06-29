#include <ics46/factory/DynamicFactory.hpp>
#include "Maze.hpp"
#include "myMazeGenerator.hpp"
#include <random>


ICS46_DYNAMIC_FACTORY_REGISTER(
    MazeGenerator, myMazeGenerator, 
    "Tapia Maze Generator (Required)"
)

std::random_device device;
std::default_random_engine engine{device()};
std::uniform_int_distribution<int> distribution{0,3};

myMazeGenerator::myMazeGenerator()
{
}

void myMazeGenerator::recursiveMaze(Maze& maze, int row, int column)
{
    visitedCells[row * columns + column] = true;   
    
    if (row == 0) //cannot check up
    {
        while (checkVisitedCells(row+1,column)==false||(column!=0 && checkVisitedCells(row,column-1)==false)||(column!=columns-1 && checkVisitedCells(row,column+1)==false))
        {
            int randomInt = distribution(engine);
            
            if (randomInt == 1 && checkVisitedCells(row+1, column) == false) //down
            {
                maze.removeWall(column, row, Direction::down);
                recursiveMaze(maze, row+1, column);
            }
            if (randomInt == 2 && column != 0 && checkVisitedCells(row, column-1) == false) //left
            {
                maze.removeWall(column, row, Direction::left);
                recursiveMaze(maze, row, column-1);
            }
            if (randomInt == 3 && column != columns-1 && checkVisitedCells(row, column+1) == false) //right
            {
                maze.removeWall(column, row, Direction::right);
                recursiveMaze(maze, row, column+1);
            }
        }

    }

    if (row == rows-1) //cannot go down
    {
        while (checkVisitedCells(row-1,column)==false||(column!=0 && checkVisitedCells(row,column-1)==false)||(column!=columns-1 && checkVisitedCells(row,column+1)==false))
        {
            int randomInt = distribution(engine);

            if (randomInt == 1 && checkVisitedCells(row-1, column) == false) //up
            {
                maze.removeWall(column, row, Direction::up);
                recursiveMaze(maze, row-1, column);
            }
            if (randomInt == 2 && column != 0 && checkVisitedCells(row, column-1) == false) //left
            {
                maze.removeWall(column, row, Direction::left);
                recursiveMaze(maze, row, column-1);
            }
            if (randomInt == 3 && column != columns-1 && checkVisitedCells(row, column+1) == false) //right
            {
                maze.removeWall(column, row, Direction::right);
                recursiveMaze(maze, row, column+1);
            }
        }
    }
    
    if (column == 0) //cannot move left
    {
        while ((row!=0 && checkVisitedCells(row-1,column)==false)||(row!=rows-1 && checkVisitedCells(row+1,column)==false)||checkVisitedCells(row,column+1)==false)
        {
            int randomInt = distribution(engine);

            if (randomInt == 1 && row != 0 && checkVisitedCells(row-1, column) == false) //up
            {
                maze.removeWall(column, row, Direction::up);
                recursiveMaze(maze, row-1, column);
            }
            if (randomInt == 2 && row != rows-1 && checkVisitedCells(row+1, column) == false) //down
            {
                maze.removeWall(column, row, Direction::down);
                recursiveMaze(maze, row+1, column);
            }
            if (randomInt == 3 && checkVisitedCells(row, column+1) == false) //right
            {
                maze.removeWall(column, row, Direction::right);
                recursiveMaze(maze, row, column+1);
            }
        }
    }

    if (column == columns-1) //cannot move right
    {
        while ((row!=0 && checkVisitedCells(row-1,column)==false)||(row!=rows-1 && checkVisitedCells(row+1,column)==false)||checkVisitedCells(row,column-1)==false)
        {
            int randomInt = distribution(engine);

            if (randomInt == 1 && row != 0 && checkVisitedCells(row-1, column) == false) //up
            {
                maze.removeWall(column, row, Direction::up);
                recursiveMaze(maze, row-1, column);
            }
            if (randomInt == 2 && row != rows-1 && checkVisitedCells(row+1, column) == false) //down
            {
                maze.removeWall(column, row, Direction::down);
                recursiveMaze(maze, row+1, column);
            }
            if (randomInt == 3 && checkVisitedCells(row, column-1) == false) //left
            {
                maze.removeWall(column, row, Direction::left);
                recursiveMaze(maze, row, column-1);
            }
        }
    }
    
    if (row!=0 && row!=rows-1 && column!=0 && column!=columns-1)
    {
        while (checkVisitedCells(row-1,column)==false||checkVisitedCells(row+1,column)==false||checkVisitedCells(row,column-1)==false||checkVisitedCells(row,column+1)==false)
        {
            int randomInt = distribution(engine);

            if (randomInt == 1 && checkVisitedCells(row-1, column) == false) //up
            {
                maze.removeWall(column, row, Direction::up);
                recursiveMaze(maze, row-1, column);
            }
            if (randomInt == 2 && checkVisitedCells(row+1, column) == false) //down
            {
                maze.removeWall(column, row, Direction::down);
                recursiveMaze(maze, row+1, column);
            }
            if (randomInt == 3 && checkVisitedCells(row, column-1) == false) //left
            {
                maze.removeWall(column, row, Direction::left);
                recursiveMaze(maze, row, column-1);
            }
            if (randomInt == 0 && checkVisitedCells(row, column+1) == false) //right
            {
                maze.removeWall(column, row, Direction::right);
                recursiveMaze(maze, row, column+1);
            }
        }   
    }
}

void myMazeGenerator::generateMaze(Maze& maze)
{
    this->columns = maze.getWidth();
    this->rows = maze.getHeight();

    visitedCells = new bool[rows * columns];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            visitedCells[i * columns + j] = false;
        }
    }

    maze.addAllWalls();
    currentRow = 0;
    currentColumn = 0;
    
    recursiveMaze(maze, currentRow, currentColumn);
    delete[] visitedCells; 
}


bool myMazeGenerator::checkVisitedCells(int givenRow, int givenColumn)
{
    return visitedCells[givenRow * columns + givenColumn];
}
