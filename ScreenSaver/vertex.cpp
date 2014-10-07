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

float vertex::retX2(){	//our function retX
    return(x2);
}

float vertex::retY2(){
    return(y2);
    
}


float vertex::getActive(){
    return(active);
    
}


float vertex::getdirectX(){
    return (directX);
    
}

float vertex::getdirectY(){
    return (directY);
}

float vertex::getdirectX2() {
    
    return (directX2);
}

float vertex::getdirectY2() {
    
    return (directY2);
    
}




void vertex::setX(float xC) {
    x = xC;
}

void vertex::setY(float yC) {
    y = yC;
}

void vertex::setX2(float xC) {
    x2 = xC;
}

void vertex::setY2(float yC) {
    y2 = yC;
}


void vertex::setdirectX(float dX){
    directX = dX;
}

void vertex::setdirectY(float dY){
    directY = dY;
}

void vertex::setdirectX2(float dX) {
    directX2 = dX;
    
}

void vertex::setdirectY2(float dY) {
    directY2 = dY;
}

void vertex::setActive(float a){
    active = a;
}


