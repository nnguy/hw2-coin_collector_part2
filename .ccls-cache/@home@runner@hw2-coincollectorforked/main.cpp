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
#include "robot.h"

using namespace std; 

const int NUM_POINTS = 3; 



int main(int argc, char* argv[]){
  int a, b; 
  World w; 
  Robot r; 
  
  //check if a proper number of arguments was entered (a valid number of arguments is always an odd number (calling the executable + 2 integers per point)
/*
argv[0] = .\main 
argv[1 and odd numbered argument] = x coordinate, must be between 0 and 10 
argv[2 and even numbered argument] = y coordinate, must be between 0 and -10 

*/
  if (argc % 2 == 0){
    cout << "Invalid number of arguments. You must specify an integer for each coordinate's X and Y" << endl; 
  }

  //if a correct number of inputs were added, then begin checking that each parameter is valid for  
  else{
    int point_index = 0; 
    char *char_ptr = nullptr; 
    for (int i = 1; i+1 < argc; i+=2){
        //cout << i << endl;
      //for argv[2,4,6] (aka if i > 1 && i % 2 == 0)
      // if i == 1/3/5[0] == '-' then print out an error 
      //else if i == 2/4/6[0] && argv[i][0] != '0' then print out an error 
      //else, do the below for argv[1,3,5] (if i == 1 and the below)

      //this checks if argv[1] and argv[2] is not a number
      if (!isdigit(*argv[i]) || (*argv[i+1] != '0' && argv[i+1][0] != '-') ){
        cout << "Error - invalid input " << endl; 
      }

      //check if the odd-numbered parameters (x) are negative or greater than 10
      else if (argv[i][0] == '-' || atoi(argv[i]) > 9 ){
        cout << "error - out of bounds X parameter " << endl; 
      }

      //check if the even-numbered parameter is valid is 0 or negative 
      else if (strtol(argv[i+1], &char_ptr, 10) > 0 || strtol(argv[i+1], &char_ptr, 10) < -9){
        cout << "error, out of bounds Y parameter " << endl; 
      }
        
      else{
        cout << "parameter check passed " << endl; 
        a = strtol(argv[i], &char_ptr, 10); 
        b = strtol(argv[i+1], &char_ptr, 10); 
        cout << "a: " << a << endl
          <<"b: " << b << endl;
        w.set(point_index, a, b); 
        point_index++; 
      }


    }    
  w.print(); 
  r.init(); 
  r.print();
  r.setOrientation(NORTH); 
  r.print(); 
  r.forward(); 
  r.print();
  r.turnCW(); 
  r.print(); 
  r.turnAntiCW(); 
  r.print(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.forward(); 
  r.print(); 
  if (r.northEnd()){
    cout << "reached the north end" << endl; 
  }
  r.turnCW(); 
  for (int i = 0; i < 9; i++){
    r.forward(); 
  }
  r.print();
  r.zig(); 
  r.print(); 
  r.setLocation(0,-10);
  r.print();  
  return 0;
}
  }

