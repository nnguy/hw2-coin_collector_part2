#ifndef WORLD_H
#define WORLD_H

#include "point.h";
const int MAX_POINTS = 3; 

class World{
private:
  Point points[MAX_POINTS]; 
public: 
  World(); 
  void print() const; 
  void set(int, int, int); //parameter 1 is the index, parameter 2 is the x coordinate, parameter 3 is the y coordinate 
};

#endif
