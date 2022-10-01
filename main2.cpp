/*
Nelson Nguy 
CSC 211H
Assignment 2.5 - This program utilizes the Point, World, and Robot classes to create a human v computer game to see who can claim the most coins. 

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

using namespace std; 

int main(int argc, char* argv[]){
    //create world, robot
    World w;
    //Player 1 is the human-controlled robot, Player 2 is the computer-controlled robot 
    Robot p1, p2; 
    p1.init(); 
    p2.init(); 
    char c; 

    int input; 
    cout << "Do you want to input a file or do RNG for the point locations" << endl;
    cout <<  "Input 1 for file or 2 for RNG" << endl; 
    cin >> input; 

    while (input != 1 && input != 2){
        cout << "Invalid entry. " << endl; 
        cout << "Do you want to input a file or do RNG for the point locations" << endl;
        cout <<  "Input 1 for file or 2 for RNG" << endl; 
        cin >> input; 
    }
    int x_coord = 0; 
    int y_coord = 0; 
    int x = 0; 
    bool rng_due_to_invalid_file = false; 

    string file_name; 
    if (input == 1){
        cin.ignore(10,'\n');
        cout << "Please enter the name of the file "; 
        getline(cin, file_name); 
        ifstream infile (file_name); 
        int i = 0; 
        if (infile.is_open()){
            while (infile >> x_coord >> y_coord){
                if (x_coord < 0 || x_coord > 9){
                    cout << "invalid x coordinates " << endl;
                    rng_due_to_invalid_file = true; 
                    break;   
                }
                else if (y_coord > 0 || y_coord < -9){
                    cout << "invalid y coordinates " << endl;
                    cout << "switching to RNG  coordinates " << endl; 
                    rng_due_to_invalid_file = true; 
                    break;    
                }
                else{
                    w.set(i,x_coord, y_coord); 
                    i++; 
                }

            }
            
        }
        else{
            cout << "error, file did not open properly" << endl;
            cout << "switching to RNG  coordinates " << endl; 
            rng_due_to_invalid_file = true; 
        }

    }

    else{
        srand(time(0)); 
        for (int j = 0; j < MAX_POINTS; j++){
            x_coord = rand() % 10;
            y_coord = (rand() % 10) * -1; 
            //this checks if the same coordinates are re-rolled more than once 
            if (w.isPointExistent(x_coord,y_coord)){
                j--; 
            }
            else{
                w.set(j, x_coord, y_coord); 
            }
        }
    }
    if (rng_due_to_invalid_file == true){
        srand(time(0)); 
        for (int j = 0; j < MAX_POINTS; j++){
            x_coord = rand() % 10;
            y_coord = (rand() % 10) * -1; 
            //this checks if the same coordinates are re-rolled more than once 
            if (w.isPointExistent(x_coord,y_coord)){
                j--; 
            }
            else{
                w.set(j, x_coord, y_coord); 
            }
        }
    }

    w.print(); 

    int total_coins_found = 0; 
    while (total_coins_found < MAX_POINTS){
        //player1movement - computer player
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
        //player2 movement - human player 
        cout << "Input one of the following to move your robot" << endl; 
        cout << "   ^" << endl;
        cout << "   w" << endl; 
        cout << "<a s d>" << endl;
        cout << "   v" << endl;  
        cin >> c; 
        p2.moveOnce(c);


        //ANSI escape sequence that clears the console - commented out to make sure stuff is working properly
 
        //p2.print(); 
        for (int i = 0; i < MAX_POINTS; i++){
            cout<< u8"\033[2J\033[1;1H"; 
            if (w.isPointExistent(i)){

                if (w.isPointExistent(i) && p2.checkLocation(w.getPoint(i))){
                    cout << "Player 2 found a coin at ";
                    w.getPoint(i).print();
                    p2.updateCoinsFound(1);
                    total_coins_found++; 
                    w.releasePoint(i); 
                    cout << "found " << p2.getCoinsFound() << " coins so far" << endl;

                }
                else if (w.isPointExistent(i) && p1.checkLocation(w.getPoint(i))){
                    cout << "Player 1 found a coin at ";
                    w.getPoint(i).print();
                    p1.updateCoinsFound(1);
                    total_coins_found++; 
                    w.releasePoint(i); 
                    cout << "found " << p1.getCoinsFound() << " coins so far" << endl; 
                }
                else {
                    p1.print(1);
                    p2.print(2);
                }
            }
        }
        cout << total_coins_found << " coins found" << endl; 

    }
    cout << "Player 1 has " << p1.getCoinsFound() << " coins " << endl; 
    cout << "Player 2 has " << p2.getCoinsFound() << " coins " << endl; 
    
    if (p1.getCoinsFound() > p2.getCoinsFound())
        cout << "Player 1 wins " << endl; 
    else
        cout << "Player 2 wins " << endl; 
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
