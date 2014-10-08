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
    vertex(float xC, float yC, float dX, float dY, float mode); //constructor for point
   
    
    // GETS
    float retX();
    float retY();
    float retX2();
    float retY2();
    float getdirectX();
    float getdirectY();
    float getdirectX2();
    float getdirectY2();
    float getActive();
    float retPolyXind(float index);
    float retPolyYind(float index);
    float polyXSize();
    float polyYSize();
    float retPolyXD(float index);
    float retPolyYD(float index);
    
    
    // SETS
    void setX(float x, float mode);
    void setY(float y, float mode);
    void setX2(float x);
    void setY2(float y);
    void setActive(float a);
    void setdirectX(float dX, float mode);
    void setdirectY(float dY, float mode);
    void setdirectX2(float dX);
    void setdirectY2(float dX);
    void setIndexX(float dX, float index);
    void setIndexY(float dY, float index);
    
    
    
  
    
    
           
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
    vector <int> dirX;
    vector <int> dirY;

};





#endif
