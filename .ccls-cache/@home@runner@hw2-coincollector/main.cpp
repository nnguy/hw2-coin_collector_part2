/*
Nelson Nguy
CSC 211H 
Assignment 2 - This program receives 3 sets of coordinates as command line arguments to create coordiantes of coins that the roomba is supposed to search for. 
*/
#include <iostream> 
#include <stdlib.h>
#include <cctype>
#include "point.h"
#include "world.h"
using namespace std; 

const int NUM_POINTS = 3; 


//I'm getting a segfault lol 
//review this https://stackoverflow.com/questions/25633448/segmentation-fault-while-using-argv
//I avoided the segfault by changing i < argc to i+1 < argc (we dont want the loop to run on the last element anyway...)

int main(int argc, char* argv[]){
  int a, b; 
  World w; 
  //check if a proper number of arguments was entered (a valid number of arguments is always an odd number (calling the executable + 2 integers per point)
/*
argv[0] = .\main 
argv[1 and odd numbered argument] = x coordinate, must be between 0 and 10 
argv[2 and even numbered argument] = y coordinate, must be between 0 and -10 

*/
  if (argc % 2 == 0){
    cout << "Invalid number of arguments. You must specify an integer for each coordinate's X and Y" << endl; 
  }

  //if the input passes all of these checks, proceed with adding the points. 
  else{
    int point_index = 0; 
    for (int i = 1; i+1 < argc; i+=2){
        //cout << i << endl;
      //check for valid X coordinates I
      if (i % 2 == 1 && argv[i] )

      //for argv[2,4,6] (aka if i > 1 && i % 2 == 0)
      // if i == 1/3/5[0] == '-' then print out an error 

      //else if i == 2/4/6[0] && argv[i][0] != '0' then print out an error 

      //else, do the below for argv[1,3,5] (if i == 1 and the below)
      if (isdigit(*argv[i]) && isdigit(*argv[i+1]) && (i+1 <= argc)){
        a = atoi(argv[i]); 
        
  

      //else if argv[2][4][6] etc, 
      //parse 
       //b = atoi(argv[i][1] * -1;
        cout << "a: " << a << endl
          <<"b: " << b << endl;
        w.set(point_index, a, b); 
        point_index++; 
      }
    }
    w.print(); 
    
    
  }

  return 0;
}