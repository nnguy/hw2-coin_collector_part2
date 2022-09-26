/*
Nelson Nguy
CSC 211H Assignment 2 
Definitions of the point class
*/

#include <iostream> 
#include "point.h"

using namespace std; 


void Point::print() const{
  cout << "x: " << x << " "
  << "y: " << y << endl; 
}

void Point::set(int a, int b){
  x = a; 
  y = b;     
}