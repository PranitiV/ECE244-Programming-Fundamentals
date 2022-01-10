//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    
    
    int player = 0; 
    
    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) != 0){
        game_state.set_moveValid(false);
    }
    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == 0){
        game_state.set_moveValid(true);
    }
    
    if(game_state.get_moveValid() == true){
        
        if (game_state.get_turn()==true){
            player = X;
        }
        else if (game_state.get_turn()==false){
            player = O;
        }
        
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), player);
        
        if (game_state.get_turn()==true){
            game_state.set_turn(false);
        }
        else if (game_state.get_turn()==false){
            game_state.set_turn(true);
        }    
    }
   
    // check win for rows 
        int ocheck, xcheck; 
        for (int i = 0; i <= boardSize -1; i++){
            ocheck = 0; xcheck = 0; 
        for (int j = 0; j <= boardSize -1; j++){
           
            if (game_state.get_gameBoard(i,j)==1){
                if (game_state.get_gameBoard(i,j)!=0){
                    xcheck+=1; 
                }    
            }
            if (game_state.get_gameBoard(i,j)==-1){
                if (game_state.get_gameBoard(i,j)!=0){
                    ocheck+=1; 
                }
            }
        
            if ((xcheck == 3)||(ocheck == 3)){
                game_state.set_winCode(i+1);
                game_state.set_gameOver(true);
                ocheck = 0; xcheck = 0; 
            }    
        }
    }
    
    // check win for cols 
    for (int i = 0; i <= boardSize -1; i++){
        ocheck = 0; xcheck = 0; 
        for (int j = 0; j <= boardSize -1; j++){
           
            if (game_state.get_gameBoard(j,i)==1){ 
                if (game_state.get_gameBoard(j,i)!=0){
                    xcheck+=1; 
                }
            }
            if (game_state.get_gameBoard(j,i)==-1){
                if (game_state.get_gameBoard(j,i)!=0){
                    ocheck+=1; 
                }
            }
        
            if ((xcheck == 3)||(ocheck == 3)){
                game_state.set_winCode(i+4); 
                game_state.set_gameOver(true);
                ocheck = 0; xcheck = 0; 
            }    
        }
    }
    
        if ((game_state.get_gameBoard(0,0)==game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,2))){
            if (game_state.get_gameBoard(0,0)!=0){     
                game_state.set_winCode(7);
                game_state.set_gameOver(true);
            }
        }
    
        if ((game_state.get_gameBoard(0,2)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(0,2)== game_state.get_gameBoard(2,0))){
            if (game_state.get_gameBoard(0,2)!= Empty){
                game_state.set_winCode(8);
                game_state.set_gameOver(true);
            }
        }
        
    if(game_state.get_gameOver() == false){
       
        game_state.set_gameOver(true);
        
        for (int i=0 ; i <= 2 ; i++){
            for (int j=0 ; j <= 2 ; j++){
                if (game_state.get_gameBoard(i, j) == Empty){
                    game_state.set_gameOver(false);
                }
            }
        }
    }
}
    
    
    
    


