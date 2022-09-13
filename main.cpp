/*
Nelson Nguy
CSC 211H 
Assignment 2 - This program receives 3 sets of coordinates as command line arguments to create coordiantes of coins that the roomba is supposed to search for. 
*/
#include <iostream> 
#include <stdlib.h>
#include <cctype>
#include "point.h"
using namespace std; 

const int NUM_POINTS = 3; 


//I'm getting a segfault lol 
//review this https://stackoverflow.com/questions/25633448/segmentation-fault-while-using-argv
//I avoided the segfault by changing i < argc to i+1 < argc (we dont want the loop to run on the last element anyway...)

int main(int argc, char* argv[]){
  int a, b; 
  //check if a proper number of arguments was entered (a valid number of arguments is always an odd number (calling the executable + 2 integers per point)
  if (argc % 2 == 0){
    cout << "Invalid number of arguments. You must specify an integer for each coordinate's X and Y" << endl; 
  }
  //check if any of the coordinates are invalid (a valid point must be between 0-10 for X and -10-0 for Y)
    
  //if the input passes all of these checks, proceed with adding the points. 
  else{
    for (int i = 1; i+1 < argc; i+=2){
        cout << i << endl;
        if (isdigit(*argv[i]) && isdigit(*argv[i+1]) && (i+1 <= argc)){
          a = atoi(argv[i]); 
          b = atoi(argv[i+1]); 
          cout << "a: " << a << endl
            <<"b: " << b << endl; 
        }
      }    
  }

  return 0;
}