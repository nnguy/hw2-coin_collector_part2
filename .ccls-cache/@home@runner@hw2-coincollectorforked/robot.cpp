#include "robot.h"
#include "point.h"
#include "world.h"
#include <iostream>
using namespace std;

Robot::Robot() {
  location.set(0, 0);
  orientation = EAST;
}

Robot::~Robot() {
  //...
}

void Robot::init() {
  location.set(0, 0);
  orientation = EAST;
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
    if (location.getY() == -10) {
      return false;
    } else {
      location.set(location.getX(), location.getY() - 1);
      return true;
    }
  } else if (orientation == EAST) {
    if (location.getX() == 10) {
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