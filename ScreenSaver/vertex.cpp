//
//  vertex.cpp
//  ScreenSaver
//
//  Created by Jake Harwood on 2014-09-27.
//  Copyright (c) 2014 Jake Harwood. All rights reserved.
//

#include "vertex.h"
#include <stdio.h>
#include <stdlib.h> 






vertex::vertex(float xC, float yC, float dX, float dY){	//constructor
    x = xC;
    y = yC;
    directX = dX;
    directY = dY;
    
}



float vertex::retX(){	//our function retX
    return(x);
}

float vertex::retY(){
    return(y);
    
}


float vertex::getdirectX(){
    return (directX);
    
}

float vertex::getdirectY(){
    return (directY);
}

void vertex::setX(float xC) {
    x = xC;
}

void vertex::setY(float yC) {
    y = yC;
}

void vertex::setdirectX(float dX){
    directX = dX;
}

void vertex::setdirectY(float dY){
    directY = dY;
}



