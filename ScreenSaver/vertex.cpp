//
//  vertex.cpp
//  ScreenSaver
//
//  Created by Jake Harwood on 2014-09-27.
//  Copyright (c) 2014 Jake Harwood. All rights reserved.
//

// Includes our headers..
#include "vertex.h"
#include <stdio.h>
#include <stdlib.h> 



/**

Thought process: So evidently I was pretty time constrained for this project (had about a day and a half with other things to worry about), but I still manage to hammer it out pretty well. I found that as I translated into programming the polygons, I could had used vectors for the X-coordinates, Y-coordinates, direction X (direction vector value that pretty much means "go in this direction x-coordinate") and direction Y (same principle but it's saying "go in this direction y-coordinate").
 
 Tl;DR: Point and Line primitives use variables for their X, Y, Direction X, Direction Y values
        Polygon uses four vectors(1 for x-coord, 1 for y-coord, 1 for direction X, 1 for direction Y)
 
 In this file, I simply store my data for a specific primitive as a record so I can use it later when displaying to the screen


**/



vertex::vertex(float xC, float yC, float dX, float dY, float mode){	//constructor

    
// If in point or line mode .. then set these variables
    if (mode != 3) {
    x = xC;
    y = yC;
    directX = dX;
    directY = dY;
    } else if (mode == 3) { // If in polygon mode, add to vector
        
        polyX.push_back(xC);
        polyY.push_back(yC);

        
    }
    
}








float vertex::retX(){	//returns x-coord
    return(x);
}

float vertex::retY(){ // returns y-coord
    return(y);
    
}

float vertex::retX2(){	//returns x2-coord
    return(x2);
}

float vertex::retY2(){ // returns y2-coord
    return(y2);
    
}


float vertex::getActive(){ // returns if primtive is ready to be displayed
    return(active);
    
}


float vertex::getdirectX(){ // returns directionX vector value
    return (directX);
    
}

float vertex::getdirectY(){ // returns directionY vector value
    return (directY);
}

float vertex::getdirectX2() { //returns directionX2 vector value
    
    return (directX2);
}

float vertex::getdirectY2() { //returns directionY2 vector value
    
    return (directY2);
    
}

float vertex::polyXSize(){ //returns size of X-coord vector
    
    return (polyX.size());
}

float vertex::polyYSize(){ // returns size of Y-coord vector
    
    return (polyY.size());
}

float vertex::retPolyXind(float index) { // returns x-coord at given index of vector
    
    return(polyX[index]);
}

float vertex::retPolyYind(float index) {// returns y-coord at given index of vector
    
    return(polyY[index]);
}

float vertex::retPolyXD(float index) { // returns direction X val at given index of vector
    
    return(dirX[index]);
}

float vertex::retPolyYD(float index) { // returns direction Y val at given index of vector

    return(dirY[index]);
}



void vertex::setX(float xC, float mode) { // sets value / pushes data to vector
    
    if (mode != 3) {
        x = xC;
    } else if (mode == 3) {
        polyX.push_back(xC);
        
    }
    
    

}

void vertex::setY(float yC, float mode) { // sets value / pushes data to vector
   
    if (mode != 3) {
        y = yC;
    } else if (mode == 3) {
        polyY.push_back(yC);
        
    }

}

void vertex::setX2(float xC) { // sets value
    x2 = xC;
}

void vertex::setY2(float yC) { // sets value
    y2 = yC;
}



void vertex::setIndexX(float dX, float index){ //sets value to certain index
    polyX[index] = dX;
    
}


void vertex::setIndexY(float dY, float index){ // sets value to certain index
    polyY[index] = dY;
}





void vertex::setdirectX(float dX, float mode){ // sets direction X to value or vector
    
    if (mode != 3) {
        directX = dX;
    } else if (mode == 3) {
        dirX.push_back(dX);
    }
}

void vertex::setdirectY(float dY, float mode){ // sets direction Y to value or vector
    if (mode != 3){
        directY = dY;
    } else if (mode == 3) {
        dirY.push_back(dY);
    }
}

void vertex::setdirectX2(float dX) { // sets direction X2 value (line/point primitives)
    directX2 = dX;
    
}

void vertex::setdirectY2(float dY) { // sets direction Y2 value (line/point primitives)
    directY2 = dY;
}

void vertex::setActive(float a){ // sets "active" ("Is this primtive done being created?" to argument
    active = a;
}

void vertex::setIndexDX(float dX, float index){ // sets value of direction X vector
    dirX[index] = dirX[index] * dX;
    
}

void vertex::setIndexYX(float dY, float index){ // sets value of direction Y vector
    dirY[index] = dirY[index] * dY;
}




