#include <iostream> 
#include "point.h"
#include "world.h"
#include "robot.h"

using namespace std; 

World::World(){
  cout << "world constructor called" << endl; 
  for (int i = 0; i < MAX_POINTS; i++){
    points[i] = new Point; 
  }
  
}

World::~World(){
  for (int i = 0; i < 3; i++){
    delete points[i]; 
    points[i] = nullptr; 
  } 
}
void World::print() const{
  for (int i = 0; i < MAX_POINTS; i++){
    cout << "Coordinate " << i+1 <<" : (" << points[i]->getX() << ", " << points[i]->getY() << ")" << endl; 
  }
}

void World::set(int i, int x, int y){
  if (i > MAX_POINTS-1){
    cout << "Error, i must be " << MAX_POINTS << " or less " << endl; 
  }
  else if (x < 0 || x > 9){
    cout << "Error, x must be between 0 and 9" << endl; 
  }
  else if (y > 0 || y < -9){
    cout << "Error, y must be between -9 and 0" << endl; 
  }
  
  else{
    points[i]->set(x,y); 
  }
}

Point World::getPoint(int i){
  return *(points[i]); 
}

void World::releasePoint(int i){
  delete points[i];
  points[i] = nullptr; 
}
bool World::isPointExistent(int i){
  return (points[i] != nullptr) ? true : false; 
}

bool World::isPointExistent(int x, int y){
  for (int i = 0; i < MAX_POINTS; i++){
    if (x == points[i]->getX() && y == points[i]->getY()){
      return true; 
    }
    else
      return false; 
  }
}