#include <iostream> 
#include "point.h"
#include "world.h"

using namespace std; 


World::World(){
}

void World::print() const{
  for (int i = 0; i < MAX_POINTS; i++){
    cout << "Coordinate " << i <<" : (" << points[i].getX() << ", " << points[i].getY() << ")" << endl; 
  }
}

void World::set(int i, int x, int y){
  if (i > MAX_POINTS-1){
    cout << "Error, i must be " << MAX_POINTS << " or less " << endl; 
  }
  else{
    points[i].set(x,y); 
  }
}