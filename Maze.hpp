// Maze.hpp
//
// Declares an abstract base class for Maze implementations.  
//


#ifndef MAZE_HPP
#define MAZE_HPP

#include <ics46/observable/Observable.hpp>
#include "Direction.hpp"



class MazeListener;



class Maze : public ics46::observable::Observable<MazeListener>
{
public:
    // Because we'll be inheriting from this class, we'll declare the
    // destructor to be virtual
    virtual ~Maze() = default;


    // getWidth() returns the maze's width (i.e., how many cells across
    // is it?)
    virtual unsigned int getWidth() const noexcept = 0;


    // getHeight() returns the maze's height (i.e., how many cells tall
    // is it?)
    virtual unsigned int getHeight() const noexcept = 0;


    // wallExists() takes a cell's (x, y) coordinate and a Direction,
    // returning true if you would see a wall when standing in the cell
    // (x, y) and looking in the given direction, false otherwise.
    // For example, if you had a Maze m and you wanted to know whether
    // there was a wall to the left of cell (3, 4), you would do this:
    //
    //     m.wallExists(3, 4, Direction::left)
    virtual bool wallExists(int x, int y, Direction direction) const = 0;


    // addWall() takes a cell's (x, y) coordinate and a Direction and
    // adds a wall to the maze above, below, to the left, or to the
    // right of the given cell.  If there is already a wall there, this
    // function has no effect.  For example, if you wanted to add a wall
    // to the left of cell (4, 2) in a Maze m, you would do this:
    //
    //     m.addWall(4, 2, Direction::left)
    virtual void addWall(int x, int y, Direction direction) = 0;


    // removeWall() takes a cell's (x, y) coordinate and a Direction
    // and removes a wall from the maze above, below, to the left, or
    // to the right of the given cell.  If there is no wall there
    // already, this function has no effect.  For example, if you wanted
    // to remove a wall to the right of cell (2, 9) in a Maze m, you
    // would do this:
    //
    //     m.removeWall(2, 9, Direction::right)
    virtual void removeWall(int x, int y, Direction direction) = 0;


    // addAllWalls() adds all of the possible walls to a maze, so it
    // has walls surrounding every cell.
    virtual void addAllWalls() = 0;


    // removeAllWalls() removes all of the possible walls from a maze,
    // so it has no walls around any of its cells.
    virtual void removeAllWalls() = 0;


    // clone() returns a dynamically-allocated copy of a Maze object.
    // The copy will be an object of the same type as the object you
    // call it on, though the pointer's type will be Maze.
    virtual std::unique_ptr<Maze> clone() const = 0;
};



#endif // MAZE_HPP

