/*
Nelson Nguy 
CSC 211H
Assignment 2.5 - This program utilizes the Point, World, and Robot classes to 

*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cctype>
#include "point.h"
#include "world.h"
#include "robot.h"

using namespace std; 

int main(int argc, char* argv[]){
    //create world, robot
    World w;
    //Player 1 is the human-controlled robot, Player 2 is the computer-controlled robot 
    Robot p1, p2; 
    p1.init(); 
    p2.init(); 
    char c; 

    srand(time(0)); 
    int x = 0; 


    for (int i = 0; i < 10; i++){
        x = (rand() % 4) + 1;
        switch (x){
            case 1:
                p1.moveOnce('w'); 
                break;  
            case 2: 
                p1.moveOnce('a'); 
                break; 
            case 3: 
                p1.moveOnce('s'); 
                break; 
            case 4: 
                p1.moveOnce('d'); 
                break;
            default: 
                cout << "error, invalid value" << endl; 
                break; 
        }
        p1.print(); 

    }
    /*
    while (true){
        cout << "Input one of the following to move your robot" << endl; 
        cout << "   ^" << endl;
        cout << "   w" << endl; 
        cout << "<a s d>" << endl;
        cout << "   v" << endl;  
        cin >> c; 
        p2.moveOnce(c); 
        p2.print(); 
        cout << endl; 
    }
    */
    return 0; 
    
    

    //check for command line input for the coordinates 
    //case of argc = 1, that means no command line arguments wre included. So have the user input 
    //case of argc = 7, that means that the user attempted to put in coordinates via command line 
    //case of argc >1 and != 7, throw an error message 
    
    //create a function in world that prints the world  
    //create a funciton in robot that moves via random directions
    //create a function in robot that receives arrow key input (or wasd)
    //clear the screen after every movement 
}
