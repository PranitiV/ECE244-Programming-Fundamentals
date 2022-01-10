                               //
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file


#include <iostream>
#include <string>
using namespace std; 

#include "globals.h"
#include "GameState.h"


// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state; 
    
    game_state.set_selectedColumn(0);
    game_state.set_selectedRow(0);
    game_state.set_winCode(0);
    game_state.set_moveValid(true); 
    game_state.set_turn(true); 
    
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            game_state.set_gameBoard(i,j,Empty);
        }
    }
    
    game_state.set_gameOver(false);
    
    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    while (!game_state.get_gameOver()) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
        
        game_state.set_selectedRow(row);
        game_state.set_selectedColumn(col);
        
        playMove(game_state);
        
        //printing the gamestate object 
        cout << "Selected row "<< game_state.get_selectedRow() << " and column "<< game_state.get_selectedColumn()<< endl;
        cout << "Game state after playMove:" << endl; 
        cout << "Board:" << endl;
        
        if (game_state.get_gameBoard(0,0) == 0){
            cout << "   B";
        }
        else if (game_state.get_gameBoard(0,0) == 1){
            cout << "   X";
        }
        else if (game_state.get_gameBoard(0,0) == -1){
            cout << "   O";
        }
        
        if (game_state.get_gameBoard(0,1) == 0){
            cout << " B";
        }
        else if (game_state.get_gameBoard(0,1) == 1){
            cout << " X";
        }
        else if (game_state.get_gameBoard(0,1) == -1){
            cout << " O";
        }
        
        if (game_state.get_gameBoard(0,2) == 0){
            cout << " B" << endl; 
        }
        else if (game_state.get_gameBoard(0,2) == 1){
            cout << " X" << endl;
        }
        else if (game_state.get_gameBoard(0,2) == -1){
            cout << " O" << endl;
        }
        
        if (game_state.get_gameBoard(1,0) == 0){
            cout << "   B";
        }
        else if (game_state.get_gameBoard(1,0) == 1){
            cout << "   X";
        }
        else if (game_state.get_gameBoard(1,0) == -1){
            cout << "   O";
        }
        
        if (game_state.get_gameBoard(1,1) == 0){
            cout << " B";
        }
        else if (game_state.get_gameBoard(1,1) == 1){
            cout << " X";
        }
        else if (game_state.get_gameBoard(1,1) == -1){
            cout << " O";
        }
        
        if (game_state.get_gameBoard(1,2) == 0){
            cout << " B" << endl; 
        }
        else if (game_state.get_gameBoard(1,2) == 1){
            cout << " X" << endl;
        }
        else if (game_state.get_gameBoard(1,2) == -1){
            cout << " O" << endl;
        }
        
        if (game_state.get_gameBoard(2,0) == 0){
            cout << "   B";
        }
        else if (game_state.get_gameBoard(2,0) == 1){
            cout << "   X";
        }
        else if (game_state.get_gameBoard(2,0) == -1){
            cout << "   O";
        }
        
        if (game_state.get_gameBoard(2,1) == 0){
            cout << " B";
        }
        else if (game_state.get_gameBoard(2,1) == 1){
            cout << " X";
        }
        else if (game_state.get_gameBoard(2,1) == -1){
            cout << " O";
        }
        
        if (game_state.get_gameBoard(2,2) == 0){
            cout << " B" << endl; 
        }
        else if (game_state.get_gameBoard(2,2) == 1){
            cout << " X" << endl;
        }
        else if (game_state.get_gameBoard(2,2) == -1){
            cout << " O" << endl;
        }
        
        
        if (game_state.get_moveValid()== true){
            cout << "moveValid: true"<< endl;
        }
        else {
            cout << "moveValid: false"<< endl;
        }
        
        if (game_state.get_gameOver()){
            cout << "gameOver: true"<< endl;
        }
        else {
            cout << "gameOver: false"<< endl;
        }
        
        cout << "winCode: "<< game_state.get_winCode()<< endl; 
        
        cout << endl; 
        
        // The coordinates are valid; set the selectedRow and selectedColumn
        // members of the game state to the read values
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
            
        // ECE244 Student: add your code here
            
        // Call playMove
            
        // ECE244 Student: add your code here 
          
        // Print the GameState object, as prescribed in the handout
            
        // ECE244 Student: add your code here
            
    }
    

    return 0;
}

