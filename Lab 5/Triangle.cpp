//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle(string n, float xcent, float ycent, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3):Shape(n, xcent, ycent) {
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
    x3 = x_3;
    y3 = y_3; 
}

Triangle::~Triangle() {
    // Nothing to do
}

/* Accessor
float Triangle::getWidth() const {
    return width;
}
float Triangle::getHeight() const {
    return height;
}

// Mutator
void Triangle::setWidth(float w) {
    width = w;
}
void Triangle::setHeight(float h) {
    height = h;
}*/

void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    
    float xcentre = (x1+x2+x3)/3.00;
    float ycentre = (y1+y2+y3)/3.00;
    cout << "triangle: " << name << " " << xcentre << " " << ycentre << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << computeArea() << endl;
}

float Triangle::computeArea() const {
    float a = x1*(y2-y3);
    float b = x2*(y3-y1);
    float c = x3*(y1-y2);
    
    float ans; 
    ans =  (a+b+c)/2.00;
    if (ans < 0){return -ans;}
    return ans;
    
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}
