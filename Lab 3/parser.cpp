//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool checkValue(int value); 
bool checkName(string name, bool failFlag, bool eofFlag, bool error);
bool checkType(string type, bool failFlag, bool eofFlag);
bool checkLocation(int location, bool failFlag, bool eofFlag);
bool checkShapeName(string name);
bool shapeName(string name); 


int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input
    
    while ( !cin.eof () ) {
        
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        if (command == "maxShapes"){
            
            if(lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } 
            else if (!lineStream.eof()){          
                lineStream >> max_shapes;

                if(lineStream.fail()){
                    cout << "Error: invalid argument" << endl;
                    lineStream.clear();    
                }
                else{            
                    if(lineStream.peek() != EOF){
                        cout << "Error: too many arguments"<<endl;}        
                    else if (checkValue(max_shapes)){                
                        shapesArray = new Shape*[max_shapes]; 
                        for(int i = 0 ; i < max_shapes ;i++ ){
                            shapesArray[i] = NULL;} 
                        cout << "New database: max shapes is " << max_shapes << endl;
                    }
                }
            }}
        
        else if (command == "create"){

           
            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } 
            
            else {
            string s_name; 
            lineStream >> s_name; 

            if (!checkName(s_name, lineStream.fail(), lineStream.eof(), true)){

                string s_type; 
                lineStream >> s_type; 

                if ( !checkType(s_type, lineStream.fail(), lineStream.eof())){

                    int locofx;
                    lineStream >> locofx; 

                    if (checkLocation(locofx, lineStream.fail(), lineStream.eof()) ){ 
                        int locofy;
                        lineStream >> locofy;

                        if(checkLocation(locofy, lineStream.fail(), lineStream.eof())){
                            
                            int sizeofx;
                            lineStream >> sizeofx;

                            if(checkLocation(sizeofx, lineStream.fail(), lineStream.eof())){

                                int sizeofy;
                                lineStream >> sizeofy;

                                if( checkLocation(sizeofy, lineStream.fail(), lineStream.eof())){

                            
                                    while (lineStream.peek()==32 /*&& lineStream.eof()!=EOF)*/){
                                    lineStream.ignore(1);
                                    }
                                    if ((s_type == "circle")&&(sizeofx!=sizeofy)){cout << "Error: invalid value"<<endl; }
                                    else if( !lineStream.eof() ){cout << "Error: too many arguments" << endl;}
                                        else {
                                        
                                        if (shapeCount >= max_shapes){
                                            cout << "Error: shape array is full" << endl; 
                                        }                   
                                        else {
                                            for (int i = 0; i < max_shapes; i++){
                                                if (shapesArray[i]==NULL){
                                            shapesArray[i] = new Shape(s_name, s_type, locofx, sizeofx, locofy, sizeofy);
                                        cout << "Created "<< s_name << ": " << s_type << " " << locofx << " " << locofy << " " << sizeofx << " " << sizeofy << endl; 
                                        shapeCount++; break;}}}
                                        }}}}}}}}}
        
            else if (command == "move"){
            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } else {

            string m_name;
            lineStream >> m_name;

            if( !checkName(m_name, lineStream.fail(), lineStream.eof(), false) ){
                int locationx;
                lineStream >> locationx;

                if (checkLocation(locationx, lineStream.fail(), lineStream.eof())){ 
                        int locationy;
                        lineStream >> locationy;

                        if(checkLocation(locationy, lineStream.fail(), lineStream.eof())){
                            while (lineStream.peek()==32){
                                    lineStream.ignore(1);}
                            if( !lineStream.eof() ){cout << "Error: too many arguments" << endl;}
                            
                            int buffer = 0;
                            for (int i = 0; i < shapeCount; i++){
                                if (shapesArray[i]->getName() == m_name){
                                    buffer = 1;
                                }
                            }

                            if (buffer == 0){cout << "Error: shape "<< m_name<< " not found"<<endl;}

                            for(int i = 0 ; i < max_shapes ; i++){
                                if(shapesArray[i] != NULL){
                                    if(shapesArray[i]->getName() == m_name){
                                        shapesArray[i]->setXlocation(locationx);
                                        shapesArray[i]->setYlocation(locationy);
                                        cout <<"Moved "<< shapesArray[i]->getName() <<" to "<< 
                                        shapesArray[i]->getXlocation()<<" "<< shapesArray[i]->getYlocation() << endl;
                                    }}}}}}}}
        else if (command == "rotate"){
            
            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } 

            string r_name;
            lineStream >> r_name;

            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } 

            if(checkName(r_name, lineStream.fail(), lineStream.eof(), false)==false){
                    
                    bool can_rotate = true;
                    
                    int r_angle = -1;
                    lineStream >> r_angle;

                    if (lineStream.fail()){
                    cout<< "Error: invalid argument" <<endl;} 

                    if ((0 <= r_angle )&&(r_angle <= 360)){
                        if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                        else {
                            
                                    for(int i = 0 ; i < max_shapes ; i++){
                                        if(shapesArray[i] != NULL){
                                            if(shapesArray[i]->getName() == r_name){
                                                shapesArray[i]->setRotate(r_angle);
                                                cout <<"Rotated "<< shapesArray[i]->getName() <<" by "<<
                                                        r_angle << " degrees"<< endl; 
                                                can_rotate = false;
                                            }}} if (can_rotate == true){
                                                cout << "Error: shape " << r_name << " not found"<< endl; 
                                            }}}
                    else {
                        cout << "Error: invalid value"<< endl; 
                    }
            }
        }
        
        else if (command == "draw"){

            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } else {

            string d_name; 
            lineStream >> d_name; 
            
            if (lineStream.fail()){
                cout << "Error: invalid argument this" << endl; 
            }
            else {
                
                if (d_name == "all"){
                    
                    while(lineStream.peek() == 32){
                    lineStream.ignore(1);}
                    if (!lineStream.eof()){
                        cout << "Error: too many arguments"<< endl;
                    }
                    else {
                        cout << "Drew all shapes" << endl; 
                        for (int i = 0 ; i < shapeCount ; i++){
                        shapesArray[i]->draw();}
                    }

                }else {

                    if (checkName(d_name, lineStream.fail(), lineStream.eof(), false)==false){
                        while(lineStream.peek() == 32){
                        lineStream.ignore(1);}
                        if (!lineStream.eof()){
                        cout << "Error: too many arguments"<< endl;}
                        else {
                            //cout << "Drew " << d_name << endl; 

                            for (int i = 0 ; shapeCount>i ; i++){
                                if (d_name == shapesArray[i]->getName()){
                                    cout << "Drew ";
                                    shapesArray[i] -> draw(); 
                                }}}}}}}}
        
        else if (command == "delete"){

            if (lineStream.eof()){
                cout<< "Error: too few arguments" <<endl;
            } else {

            string del_name; 
            lineStream >> del_name; 

            if (lineStream.fail()){
                cout << "Error: invalid argument"<< endl; 
            }
            
            else {
                
                if(del_name == "all"){
                    
                    while(lineStream.peek() == 32){
                    lineStream.ignore(1);}
                    if (!lineStream.eof()){
                        cout << "Error: too many arguments"<< endl;
                    }
                    else{
                        for(int i = 0 ; i < max_shapes ; i++){
                          if(shapesArray[i] != NULL){
                                delete shapesArray[i];
                                shapesArray[i] = NULL;                       
                           }
                        }

                cout << "Deleted: all shapes"<< endl;
                    shapeCount = 0;}
                }else {
                    int rand = 0; 
                    for(int i = 0 ; i < max_shapes ; i++){
                            if(shapesArray[i] != NULL){
                                   if(del_name ==shapesArray[i]->getName()){ 
                                       delete shapesArray[i];
                                       shapesArray[i] = NULL;
                                       cout<< "Deleted shape " << del_name << endl;
                                       shapeCount--; 
                                       rand = 1; 
                                   }
                               }
                            }

                            if (true){
                                if (rand==0){
                                    {cout << "Error: shape " << del_name << " not found"<<endl;}}
                                else {
                                    while(lineStream.peek() == 32){lineStream.ignore(1);}
                                    if (!lineStream.eof()){cout << "Error: too many arguments"<< endl;
                                }}}}}}}
        else {
            cout << "Error: invalid command" << endl; 
        }
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
        } // End input loop until EOF.
        
    return 0;
    }
    
    bool checkValue(int value){
        if (value >= 0){
            return true;
        }
        else return false; 
    }
    
    bool checkName(string name, bool failFlag, bool eofFlag, bool error){

        if (failFlag){
            if (eofFlag){
                cout << "Error: too few arguments" << endl; 
                return true;
            }
            else {
                cout << "Error: invalid argument" << endl; 
                return true;
            }
        }
        else if (shapeName(name)){
            cout << "Error: invalid shape name" << endl;
            return true; 
        }
        else if (checkShapeName(name)){
            if (error){
                cout << "Error: shape " << name << " exists" <<endl; 
                return true;}
            else {
                return false;}
        }

        if (!error){
            cout << "Error: shape " << name << " not found"<<endl;
            return true;
        }
        
        return false; 
    }
    
    bool checkType(string type, bool failFlag, bool eofFlag){
        
        if (failFlag){
            if (eofFlag){
                cout << "Error: too few arguments" << endl; 
                return true;
            }
            else {
                cout << "Error: invalid argument" << endl; 
                return true;
            }
        }

        else if (!shapeName(type)){
            cout << "Error: invalid shape type" << endl;
            return true; 
        }
        return false;
    }

    bool checkLocation(int location, bool failFlag, bool eofFlag){

        if (failFlag){
            if (eofFlag){
                cout << "Error: too few arguments" << endl; 
                return false ;
            }
            else {
                cout << "Error: invalid argument" << endl; 
                return false;
            }
        }
        
        if (location < 0){
            cout << "Error: invalid value" << endl; 
            return false; 
        }

        return true; 

    } 


    bool shapeName(string name){
            for(int i = 0; i < 4; i++) {
                if( name == shapeTypesList[i]){
                return true;
                }
            }
            
            for(int i = 0; i < 7; i++) {
                if( name == keyWordsList[i]){
                return true;
        }
    } 
            return false;
    }

    bool checkShapeName(string name){
        for(int i = 0; i < max_shapes ; i++){      
            if(shapesArray[i] != NULL){
                if(name == shapesArray[i]->getName()){
                    return true;
                }   
            }
        }
        return false; 
    }
    

