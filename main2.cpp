/*
Nelson Nguy 
CSC 211H
Assignment 2.5 - This program utilizes the Point, World, and Robot classes to 

*/
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include "point.h"
#include "world.h"
#include "robot.h"

using namespace std; 

int main(int argc, char* argv[]){
    //create world, robot
    World w; 
    Robot r; 

    //check for command line input for the coordinates 
    //case of argc = 1, that means no command line arguments wre included. So have the user input 
    //case of argc = 7, that means that the user attempted to put in coordinates via command line 
    //case of argc >1 and != 7, throw an error message 
    
    //create a function in world that prints the world  
    //create a funciton in robot that moves via random directions
    //create a function in robot that receives arrow key input (or wasd)
    //clear the screen after every movement 
}
