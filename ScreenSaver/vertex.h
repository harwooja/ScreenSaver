//
//  vertex.h
//  ScreenSaver
//
//  Created by Jake Harwood on 2014-09-27.
//  Copyright (c) 2014 Jake Harwood. All rights reserved.
//

#pragma once

#ifndef ScreenSaver_vertex_h
#define ScreenSaver_vertex_h

#include <vector>
using namespace std;

class vertex{
public:
    vertex(float xC, float yC, float dX, float dY); //constructor for point
    
    float retX();
    float retY();
    float retX2();
    float retY2();
    float getdirectX();
    float getdirectY();
    float getdirectX2();
    float getdirectY2();
    float getActive();
    
    void setX(float x);
    void setY(float y);
    void setX2(float x);
    void setY2(float y);
    
    void setActive(float a);
    
    void setdirectX(float dX);
    void setdirectY(float dY);
    void setdirectX2(float dX);
    void setdirectY2(float dX);
           
           
private:
    float x;
    float y;
    float directX;
    float directY;
    float directX2;
    float directY2;
    float active;
 // extra variables for GL_LINES
    float x2;
    float y2;
    vector <int> polyX;
    vector <int> polyY;

};





#endif
