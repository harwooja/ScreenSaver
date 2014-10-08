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






vertex::vertex(float xC, float yC, float dX, float dY, float mode){	//constructor
   
    if (mode != 3) {
    x = xC;
    y = yC;
    directX = dX;
    directY = dY;
    } else if (mode == 3) {
        
        polyX.push_back(xC);
        polyY.push_back(yC);

        
    }
    
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

float vertex::polyXSize(){
    
    return (polyX.size());
}

float vertex::polyYSize(){
    
    return (polyY.size());
}

float vertex::retPolyXind(float index) {
    
    return(polyX[index]);
}

float vertex::retPolyYind(float index) {
    
    return(polyY[index]);
}

float vertex::retPolyXD(float index) {
    
    return(dirX[index]);
}

float vertex::retPolyYD(float index) {

    return(dirY[index]);
}



void vertex::setX(float xC, float mode) {
    
    if (mode != 3) {
        x = xC;
    } else if (mode == 3) {
        polyX.push_back(xC);
        
    }
    
    

}

void vertex::setY(float yC, float mode) {
   
    if (mode != 3) {
        y = yC;
    } else if (mode == 3) {
        polyY.push_back(yC);
        
    }

}

void vertex::setX2(float xC) {
    x2 = xC;
}

void vertex::setY2(float yC) {
    y2 = yC;
}



void vertex::setIndexX(float dX, float index){
    polyX[index] = dX;
    
}


void vertex::setIndexY(float dY, float index){
    polyY[index] = dY;
}





void vertex::setdirectX(float dX, float mode){
    
    if (mode != 3) {
        directX = dX;
    } else if (mode == 3) {
        dirX.push_back(dX);
    }
}

void vertex::setdirectY(float dY, float mode){
    if (mode != 3){
        directY = dY;
    } else if (mode == 3) {
        dirY.push_back(dY);
    }
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





