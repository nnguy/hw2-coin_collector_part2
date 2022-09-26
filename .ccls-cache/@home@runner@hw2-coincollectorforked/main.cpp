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

  //navigate across the entire map 
  r.init(); 
  r.forward(); 
  r.print(); 

  //I dont think I need reached_x and reached_y
  //r.getX() <= 9
  bool reached_x = false; 
  bool reached_y = false;

  w.print();
  w.set(0,1,-4); 
  w.set(1,3,-3); 
  w.set(1,10,-2); 
  w.set(1,4,10); 
  w.set(2,5,-5);
  w.print();
  //a while loop to make the robot search the entire map
  while ((r.getY() != -9) || (r.getX() != 0)){

    if (r.getX() == 0 && r.getY() == -9){
      cout << "stop!!!" << endl; 
      break; 
    }
    else if (r.getX() == 9 && r.getY() != 9){
      r.zig(); 
      r.print();
      r.forward(); 
      r.print(); 
    }
    else if (r.getX() == 0 && r.getY() != 9){
      r.zag();
      r.print(); 
      r.forward(); 
      r.print(); 
    }

    else{
      r.forward(); 
      r.print(); 
    }

    
  }
  int stepsTravelled = 0; 
  r.init(); 
  while (((r.getY() != -9) || (r.getX() != 0)) && r.getCoinsFound() < MAX_POINTS){

    if (r.getX() == 0 && r.getY() == -9){
      cout << "stop!!!" << endl; 
      break; 
    }
    else if (r.getX() == 9 && r.getY() != 9){
      r.zig();
      r.forward(); 
    }
    else if (r.getX() == 0 && r.getY() != 9){
      r.zag();
      r.forward(); 
    }

    else{
      r.forward(); 
    }
    stepsTravelled++;
    for (int i = 0; i < MAX_POINTS && r.getCoinsFound() < MAX_POINTS; i++){
      if (w.isPointExistent(i)){
        if (w.isPointExistent(i) && r.checkLocation(w.getPoint(i))){
          cout << "found a coin at ";
          w.getPoint(i).print();
          r.updateCoinsFound(1);
          w.releasePoint(i); 
          cout << "found " << r.getCoinsFound() << " coins so far" << endl; 
        }
        else {
          r.print();
          cout << " and a coin was not found" << endl; 
        }
      }

    } 
    
  }
    cout << "All coins found in " << stepsTravelled << " steps" << endl; 

    /*
    cout << "stopped " << endl; 
    cout << "x: "<< r.getX() << " y: " << r.getY() << endl;
    cout << "total truth value " << static_cast<int>(r.getY() != -9 && r.getX() != 0) << endl; 
    cout << "truth value of r.getY() != -9: " << static_cast<int>(r.getY() != -9) << endl; 
    cout << "truth value of r.getX() != 0: " << static_cast<int>(r.getX() != 0) << endl; 
    */
  cout << "exiting" << endl; 
  return 0;
}
}

