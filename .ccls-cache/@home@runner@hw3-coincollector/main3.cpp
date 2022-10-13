 /*This program is for testing of the overloaded oeprators: 

++ operator, which just calls foward()
-- operator, which just calls reverse()
- operator, which just provides the distance of two robots 
== operator, which returns true if 2 robots have the same x and y coordiantes 
= operator (overloaded copy constructor) 


*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cctype>
#include <string>
#include <fstream>
#include "point.h"
#include "world.h"
#include "robot.h"

int main(){
  Robot r;
  cout << "Robot 1 created \n"; 
  cout << "Testing overloaded ++ operator (prefix)" << endl; 
  ++r; 
  r.print(); 
  cout << "Testing overloaded ++ operator (postfix)" << endl; 
  r++; 
  r.print();
  cout << "Testing overloaded -- operator (postfix)" << endl; 
  r--; 
  r.print(); 
  cout << "Created new robot r2" << endl; 
  Robot r2; 
  r2.print();
  cout << "Testing comparison operator and subtraction operator" << endl; 
  if (r == r2){
    cout << "r and r2 are at the same location " << endl; 
  }
  else{
    cout << "r and r2 are not at the same location " << endl;
    cout << "r and r2 are " << r-r2 << " units apart" << endl; 
  }
  cout << "Testing copy constructor " << endl; 
  r2 = r; 
  r2.print(); 
  return 0; 
}