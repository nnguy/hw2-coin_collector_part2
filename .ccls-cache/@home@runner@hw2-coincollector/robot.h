/*
Nelson Nguy 
CSC 211H 
Defining the robot class 

*/
#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"
class Robot {
private: 
	//a point object to store the robot's current location 
	Point location; 
	
	//an enumerated data type called orientation_type that defines the 4 directions the robot can be facing (n,e,s,w) or orientation 

	//a variable to store the robot's current orientation 
public: 
	//void init() that initializes the robot's location to 0,0 and current orientation is east 

	//void print const that prints the current location in a pretty format like "I am at 0,0 and I am facing east 

	//void setOrientation (orientation_type orientation); which sets the value of the robot's orientation data member 

	//bool forward() which makes the robot move forward one step IN THE DIRECTION THAT IT IS FACING (but first check that the robot is not at the edge of the world. 
	//if orienation is n, y cannot be < -10
	//if orientation is e, x cannot be > 10 
	//if orientation is s, y cannot be > 0
	//if orientation is w, x cannot be <  0

	//void turnCW() which chanes the robot's orientation one step clockwise 
	//n->e->s->w

	//void turnAntiCW() which changes the robot's orientation one step counterclockwise 
	//n->w->s->e

	//bool eastEnd/westEnd/northEnd/southEnd() which simply checks if the robot has reached the pos
};
#endif


