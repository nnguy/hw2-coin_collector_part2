#include "robot.h"
#include "point.h"
#include "world.h"
#include <iostream>
using namespace std;

Robot::Robot() {
  location.set(0, 0);
  orientation = EAST;
  coinsFound = 0; 
}

Robot::~Robot() {
  //...
}

void Robot::setLocation(int x, int y){
  if (x > 9 || x < 0){
    cout << "Invalid X location" << endl; 
  }
  else if (y > 0 || y < -9){
    cout << "Invalid Y location" << endl; 
  }
  else{
    location.set(x,y); 
  }
}
void Robot::init() {
  location.set(0, 0);
  orientation = EAST;
  coinsFound = 0;
}

int Robot::getX(){
  return location.getX(); 
}

int Robot::getY(){
  return location.getY(); 
}

int Robot::getCoinsFound(){
  return coinsFound; 
}

void Robot::print() const {
  cout << "I am at (" << location.getX() << ", " << location.getY()
       << ") and I am facing ";
  switch (orientation) {
  case NORTH:
    cout << "north" << endl;
    break;
  case EAST:
    cout << "east" << endl;
    break;
  case SOUTH:
    cout << "south" << endl;
    break;
  case WEST:
    cout << "west" << endl;
    break;
  }
}

void Robot::setOrientation(Direction d) { orientation = d; }

bool Robot::forward() {
  if (orientation == NORTH) {
    if (location.getY() == -9) {
      return false;
    } else {
      location.set(location.getX(), location.getY() - 1);
      return true;
    }
  } else if (orientation == EAST) {
    if (location.getX() == 9) {
      return false;
    } else {
      location.set(location.getX() + 1, location.getY());
      return true;
    }
  } else if (orientation == SOUTH) {
    if (location.getY() == 0) {
      return false;
    } else {
      location.set(location.getX(), location.getY() + 1);
      return true;
    }
  } else if (orientation == WEST) {
    if (location.getX() == 0) {
      return false;
    } else {
      location.set(location.getX() - 1, location.getY());
      return true;
    }
  } else {
    return false;
  }
}

bool Robot::turnCW(){
  if (orientation == NORTH){
    orientation = WEST;
    return true; 
  }
  else if (orientation == EAST){
    orientation = NORTH;
    return true; 
  }
  else if (orientation == SOUTH){
    orientation = EAST; 
    return true; 
  }
  else if (orientation == WEST){
    orientation = SOUTH; 
    return true; 
  }
  else{
    return false; 
  }
}

bool Robot::turnAntiCW(){
  if (orientation == NORTH){
    orientation = EAST;
    return true; 
  }
  else if (orientation == WEST){
    orientation = NORTH;
    return true; 
  }
  else if (orientation == SOUTH){
    orientation = WEST; 
    return true; 
  }
  else if (orientation == EAST){
    orientation = SOUTH; 
    return true; 
  }
  else{
    return false; 
  }  
}

bool Robot::northEnd(){
  return (location.getY() == -9 ? true : false); 
}

bool Robot::southEnd(){
  return (location.getY() == 0 ? true : false); 
}

bool Robot::eastEnd(){
  return (location.getX() == 9 ? true : false); 
}

bool Robot::westEnd(){
  return (location.getX() == 0 ? true : false); 
}

bool Robot::zig(){
  if (orientation == EAST && eastEnd()){
    turnCW();
    forward();
    turnCW();
    return true; 
  }
  else{
    cout << "did not turn CW" << endl; 
    return false; 
  }
}

bool Robot::zag(){
  if (orientation == WEST && westEnd()){
    turnAntiCW();
    forward(); 
    turnAntiCW();
    return true; 
  }
  else{
    return false; 
  }
}

//not sure if this will work with a Point pointer...
bool Robot::checkLocation(Point p){
  return (location.getX() == p.getX() && location.getY() == p.getY()) ? true : false; 
}

//probably will be safer to overload and write one with a Point pointer. 

bool Robot::checkLocation(Point *p){
  //I used both dereferencing and the arrow operator to remind myself that I can do both when dealing with object pointers
    return (location.getX() == (*p).getX() && location.getY() == p->getY()) ? true : false;
}

void Robot::updateCoinsFound(int i){
  coinsFound += i; 
}