#ifndef WORLD_H
#define WORLD_H

#include "point.h";
const int MAX_POINTS = 3; 

class World{
private:
  Point points[MAX_POINTS]; 
public: 
  World(); 
  void print(); 
  void set(int, int, int); //parameter 1 is 
};

#endif
