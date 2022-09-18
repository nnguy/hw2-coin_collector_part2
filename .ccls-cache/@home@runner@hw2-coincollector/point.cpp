/*
Nelson Nguy
CSC 211H Assignment 2 
Definitions of the point class
*/

#include <iostream> 
#include "point.h"

using namespace std; 


void Point::print() const{
  cout << "x: " << x << endl
  << "y: " << y << endl; 
}

void Point::set(int a, int b){
  if ((a < 0 && a > 10 ) || (b < -10 || b > 0)){
    cout << "Invalid parameters, please input valid parameters " << endl; 
  }
  else{
    cout << "correct parameters \n"; 
    x = a; 
    y = b;     
  }
}