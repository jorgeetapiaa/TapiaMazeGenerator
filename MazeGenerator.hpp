// MazeGenerator.hpp
//

#ifndef MAZEGENERATOR_HPP
#define MAZEGENERATOR_HPP



class Maze;



class MazeGenerator
{
public:
    // Because it is an abstract base class, we give this class a virtual
    // destructor.
    virtual ~MazeGenerator() = default;


    // generateMaze() is given a reference to a Maze object.  Its job is
    // to generate a new maze within that Maze object.  
    virtual void generateMaze(Maze& maze) = 0;
};



#endif // MAZEGENERATOR_HPP
