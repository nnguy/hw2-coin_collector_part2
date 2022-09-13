#include <iostream> 
#include "point.h"
#include "world.h"

using namespace std; 

const int MAX_POINTS = 3; 

World::World(){
  points[0].set(0,0);  
  points[1].set(0,0);
  points[2].set(0,0);
}

void World::print() const{
  for (i = 0; i < MAX_POINTS; i++){
    cout << "Coordinate " << i <<" : (" << points[i].getX() << ", " << points[i].getY() << ")" << endl; 
  }
}