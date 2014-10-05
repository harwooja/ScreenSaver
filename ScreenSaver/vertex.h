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



class vertex{
public:
    vertex(float xC, float yC, float dX, float dY); //constructor
    float retX();
    float retY();
    float getdirectX();
    float getdirectY();
    void setX(float x);
    void setY(float y);
    void setdirectX(float dX);
    void setdirectY(float dY);
           
           
private:
    float x;
    float y;
    int speed;
    float directX;
    float directY;
    int colour;
};





#endif
