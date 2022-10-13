/*
Nelson Nguy 
CSC 211H 
Defining the robot class 

*/
#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"
enum Direction {NORTH, EAST, SOUTH, WEST}; 

class Robot {
private: 
	//a point object to store the robot's current location 
	Point location;
  int coinsFound; 

	//an enumerated data type called orientation_type that defines the 4 directions the robot can be facing (n,e,s,w) or orientation 


	//a variable to store the robot's current orientation 
  Direction orientation; 
public: 
  Robot();
  ~Robot(); 
  //to overload the prefix operator, you dont need to add anything but to overload the postfix operator you need to pass an additional parameter 
  bool operator++(); 
  bool operator++(int); 
  bool operator--(); 
  bool operator--(int); 
  int operator-(Robot&); 
  bool operator==(Robot&); 
  Robot (Robot&);

  void setLocation(int, int); 
//void init() that initializes the robot's location to 0,0 and current orientation is east 
  int getX();
  int getY(); 
  int getCoinsFound();
  void init();
	//void print const that prints the current location in a pretty format like "I am at 0,0 and I am facing east 
  void print() const; 
  void print(int) const; 
	//void setOrientation (orientation_type orientation); which sets the value of the robot's orientation data member 
  void setOrientation(Direction); 

	//bool forward() which makes the robot move forward one step IN THE DIRECTION THAT IT IS FACING (but first check that the robot is not at the edge of the world. 
	//if orienation is n, y cannot be < -10
	//if orientation is e, x cannot be > 10 
	//if orientation is s, y cannot be > 0
	//if orientation is w, x cannot be <  0
  bool forward(); 
  bool reverse(); 
	//void turnCW() which chanes the robot's orientation one step clockwise 
	//n->e->s->w
  bool turnCW(); 

	//void turnAntiCW() which changes the robot's orientation one step counterclockwise 
	//n->w->s->e
  bool turnAntiCW(); 
	//bool eastEnd/westEnd/northEnd/southEnd() which simply checks if the robot has reached the any of the walls 
  bool eastEnd();
  bool westEnd(); 
  bool northEnd(); 
  bool southEnd(); 

  //bool zag, check if the robot was moving east, if it reached the east edge, turn clockcwise, move south one, and then turn clockwise again 

  bool zag(); 

  //bool zig, check if the robot was moving west, if it reached the west edge, turn counterclockwise, move south one, and then turn counterclockwise again 
  bool zig(); 

  bool checkLocation(Point); 
  bool checkLocation(Point*); 
  void updateCoinsFound(int);
  void moveOnce(char); 

};
#endif


