//
//  main.cpp
//  ScreenSaver
//
//  Created by Jake Harwood on 2014-09-27.
//  Copyright (c) 2014 Jake Harwood. All rights reserved.
//


// Include all of our libraries / personal headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>
#include "vertex.h"



// Use certain library depending on OS
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif


#include <iostream>
using namespace std;




/**
 
To save time ...

Bugs to Fix: Polygons acting weird when created in certain locations, Fullscreen doesn't work on OSX -- issue between GLUT / 
 FREEFLUT?
 
Things missing: Random primtives for polygons, GLUT Menu to change colour
 
 
LEGEND:
 
"+" = Speed up
"-" = Speed down
"[" = Line width up
"]" = Line width down
"SPACE" = Create polygon (assuming even number of clicks)
"a" = Random Primtives
"p" = Pause state of screen
"r" = Reset screen (wipe vector)
"ESCAPE" = Close screen
"f" = Fullscreen (tested working on linux, not OSX
"1" = Mode 1 (Points)
"2" = Mode 2 (Lines)
"3" = Mode 3 (Polygons)
 
 
 **/






// * indicates something on the heap
vector <vertex *> point;


int mode = 1; // handles our mode, default is dot mode
int lineClick = 1; // handles our "how many lines are there"
int polyClick = 1; // handles if we are drawing a new line/polygon point or not
bool ptClick = true; // handles if we are drawing a new point (user click)
int h, w; // window height, width
float origX, origY; // originalX vertex, originalY vertex
float directX, directY; // directionXvalue, directionYvalue
int vectorIndex = -1; // handles index of the vector we are targeting
int speed = 1; // handles speed at which primitives will move around the screen
bool pause = false; // handles if the screen is paused or not
int ptCounter = 0; // handles if we had chosen a correct number of vertices for polygons
int size = 1; // size of primitives
float r = 0; // red color value
float g = 0; // green color value
float b = 0; // blue color value
bool fullscreen = false; // if full screen



// Display Callback
void display(void) {
    
    
    glClear(GL_COLOR_BUFFER_BIT); //clears screen
    glLoadIdentity();
  
    gluOrtho2D(0, w, 0, h);
    
    glPointSize(size); // sets point size
    glColor3f(r, g, b); // sets color
    glLineWidth(size); // sets line width


    // if Mode 1, create vertexes
    if (mode == 1) {
        glEnable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);

        // if vector > 0 then...
        if (point.size() > 0) {

            
        for (int x  = 0; x < point.size(); x++) {
            
            glVertex2f(point[x]->retX()+(point[x]->getdirectX()), h - point[x]->retY()+(point[x]->getdirectY()) ); //draws vertex
            
            // if user did not pause, then update vertices x and y coordinates (so they appear to be moving)
            if (pause == false ) {
                point[x]->setX(point[x]->retX()+(point[x]->getdirectX()) * speed, mode );
                point[x]->setY(point[x]->retY()+(point[x]->getdirectY()) * speed, mode );
            }
        
        }
    
    }
    
    // if Mode is 2 then...
    } else if (mode == 2){
    
        
        glBegin(GL_LINES);
        
        // if vector > 0 then...
        if (point.size() > 0) {
            
            
               for (int x  = 0; x < point.size(); x++) {
                   
                   // If the value in vertex class is set to active (means that the line is created and ready to be drawn) then..
                   if (point[x]->getActive() == 1) {

                       // Create the line!
                       glVertex2f(point[x]->retX()+(point[x]->getdirectX()), h - point[x]->retY()+(point[x]->getdirectY()) );
                       glVertex2f(point[x]->retX2()+(point[x]->getdirectX2()), h - point[x]->retY2()+(point[x]->getdirectY2()) );
  
                    // If the user did not press pause, then update the x and y coordinates of the line primtive (so it moves!)
                    if (pause == false) {
                        point[x]->setX(point[x]->retX()+(point[x]->getdirectX()) * speed, mode );
                        point[x]->setY(point[x]->retY()+(point[x]->getdirectY()) * speed, mode );
                   
                        point[x]->setX2(point[x]->retX2()+(point[x]->getdirectX2()) * speed );
                        point[x]->setY2(point[x]->retY2()+(point[x]->getdirectY2()) * speed );
                    }
                       
                   }
                   
                   
               }
            
        }
  
        
    // If Mode is 3 then...
    } else if (mode == 3) {
        
        // if vector > 0 then...
        if (point.size() > 0) {
            
            for (int x = 0; x < point.size(); x++) {
                
                // If the value in vertex class is set to active (means that the polygon is created and ready to be drawn) then..
                if (point[x]->getActive() == 1) {
                    for (int z = 0; z < point[x]->polyXSize(); z++) {
   
                        glBegin(GL_POLYGON);
                        // Draw the polygon!
                        glVertex2f(point[x]->retPolyXind(z), h - point[x]->retPolyYind(z));
                    
                        // Updates the polygon x and y coordinates
                        point[x]->setIndexX((point[x]-> retPolyXind(z) + point[x]->retPolyXD(z)), z);
                        point[x]->setIndexY((point[x]-> retPolyYind(z) + point[x]->retPolyYD(z)), z);
                        
                    }
                    // glEnd() is early so polygons are separately drawn
                    glEnd();
    
                }
            
            }
            
        }
     
        
    }
    



    glEnd();
    glutSwapBuffers(); // swaps buffers (double buffering)
    
}



// Method for creating random primitives on A key
void randomPrimitive(){
    
    if (mode == 1) {
        
        for (int z = 0; z < rand()%250; z++) {
            
            int x1 = rand()%w;
            int y1 = rand()%h;
            int x2 = rand()%w;
            int y2 = rand()%h;
            
            float dx = (x2 - x1);
            float dy = (y2 - y1);
            float dx2 = dx * dx;
            float dy2 = dy * dy;
            float dt = sqrt(dx2+dy2);
            
            
            
            
            vertex * pt = new vertex(x1, y1, 0, 0, mode);
            point.push_back(pt);
            
            point[z]->setdirectY( (dy/dt)*2, mode );
            point[z]->setdirectX( (dx/dt)*2, mode );
            
            
        }
        
        
    } else if (mode == 2) {
        
        
        for (int z = 0; z < rand()%250; z++) {
            
            int x1 = rand()%w;
            int y1 = rand()%h;
            int x2 = rand()%w;
            int y2 = rand()%h;
            
            float dx = (x2 - x1);
            float dy = (y2 - y1);
            float dx2 = dx * dx;
            float dy2 = dy * dy;
            float dt = sqrt(dx2+dy2);
            
            vertex * pt = new vertex(x1, y1, 0, 0, mode);
            point.push_back(pt);
            point[z]->setdirectY( (dy/dt)*2, mode );
            point[z]->setdirectX( (dx/dt)*2, mode );
            
            x1 = rand()%w;
            y1 = rand()%h;
            x2 = rand()%w;
            y2 = rand()%h;
            
            dx = (x2 - x1);
            dy = (y2 - y1);
            dx2 = dx * dx;
            dy2 = dy * dy;
            dt = sqrt(dx2+dy2);
            
            point[z]->setX2(x1);
            point[z]->setY2(y1);
            
            point[z]->setdirectY2( (dy/dt)*2 );
            point[z]->setdirectX2( (dx/dt)*2 );
            point[z]->setActive(1);
            
        }
        
        
        
        
    } else if (mode == 3) {
        
       
            
            
        
        
    }
    
}


// Keyboard call back
void keyboard(unsigned char key, int x, int y){
    
    switch(key){
            
            case 'r': // reset to blank screen
                point.clear();
                ptClick = true;
                vectorIndex = -1;
                speed = 1;
                origX = 0;
                origY = 0;
            break;
            
            case '[': // line width up
                size++;
            break;
            
            case ']': // line width down
                if (size > 1) {
                    size--;
                }
            break;
            
            case ' ': // if space is pressed, draw polygon
            
            if (ptCounter > 0) {
            if (mode == 3 && (ptCounter % 2) == 0) {
            
                ptCounter = 0;
                point[vectorIndex]->setActive(1);
                polyClick = 1;
            }
            }
            break;
        
            
            case 'a': // create random primitives
                point.clear();
                randomPrimitive();
            
            break;
            
            case 'p': // pause animation
                if (pause == true) {
                    pause = false;
                } else if (pause == false) {
                    pause = true;
                }
            break;
           
            case '+': // increase movement speed of vertices
                speed++;
            break;
            
            case '-': // decrease movement speed of vertices
                if (speed > 1) {
                    speed--;
                }
            break;
            
            case 'f': // fullscreen on "f"
                if (fullscreen == false) {
                    glutFullScreen();
                    fullscreen = true;
                } else if (fullscreen == true) {
                    glutInitWindowSize(800,600);
                    glutInitWindowPosition(100,100);
                
                    fullscreen = false;
                
            }
                
                break;
            
            case '1': // switches mode to 1
                mode = 1;
                point.clear();
                ptClick = true;
                vectorIndex = -1;
                speed = 1;
                origX = 0;
                origY = 0;
                lineClick = 1;
            break;
            
            case '2': //switches mode to 2
                mode = 2;
                point.clear();
                ptClick = true;
                speed = 1;
                origX = 0;
                origY = 0;
                vectorIndex = -1;
                lineClick = 1;
            break;
            
            case '3': // switches mode to 3
                mode = 3;
                point.clear();
                ptClick = true;
                speed = 1;
                origX = 0;
                origY = 0;
                vectorIndex = -1;
                lineClick = 1;
            
            break;
            
            case 27: // if escape is pressed
                exit(0);
            break;
            
            
    }
    
}


// Mouse callback
void mouse(int button, int state, int x, int y) {
    
    // If left key is pressed down
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
   
      
        // If mode 1 then..
        if (mode == 1) {
        
        // if variable = true then!
        if (ptClick == true) {
           
            printf("original x-coord: %d, original y-coord: %d \n", x, y);
            origX = x;
            origY = y;
            ptClick = false;
            
            // Creates a new object using x and y coordinates (sets them)
            vertex * pt = new vertex(origX, origY, 0, 0, mode);
            point.push_back(pt);
            vectorIndex++;
            
         
            
            
        // If variable is false, save next point clicked x & y (for direction)
        } else if (ptClick == false){
            
            

            
           
            float dx = (x - origX);
            float dy = (y - origY);
            
            float dx2 = dx * dx;
            float dy2 = dy * dy;
            float dt = sqrt(dx2+dy2);
            
           // save direction vector value
            point[vectorIndex]->setdirectY( (dy/dt)*2, mode );
            point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
            
            
         
            ptClick = true;
            
            
        }
        
        // If Mode is 2 then..
        } else if (mode == 2) {
            
            
            
            if (lineClick == 1){
                
              
                printf("original x-coord: %d, original y-coord: %d \n", x, y);
                origX = x;
                origY = y;
            
                // Creates a new object using x and y coordinates (sets them)
                vertex * pt = new vertex(origX, origY, 0, 0, mode);
                point.push_back(pt);
                vectorIndex++;
                
                
                lineClick++;
                
            } else if (lineClick == 2) {
                
                float dx = (x - origX);
                float dy = (y - origY);
                
                float dx2 = dx * dx;
                float dy2 = dy * dy;
                float dt = sqrt(dx2+dy2);
                
                // save directionv vector value
                point[vectorIndex]->setdirectY( (dy/dt)*2, mode );
                point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
                
                
                
                lineClick++;
            
            } else if (lineClick == 3) {
                
                origX = x;
                origY = y;
                
                // Creates second vertex (end of line)
                point[vectorIndex]->setX2(origX);
                point[vectorIndex]->setY2(origY);
                
                
                lineClick++;
            } else if (lineClick == 4) {
                
                
                float dx = (x - origX);
                float dy = (y - origY);
                
                float dx2 = dx * dx;
                float dy2 = dy * dy;
                float dt = sqrt(dx2+dy2);
                
                // save next point clicked x & y (for direction)
                point[vectorIndex]->setdirectY2( (dy/dt)*2 );
                point[vectorIndex]->setdirectX2( (dx/dt)*2 );
                
                
                lineClick = 1;
                point[vectorIndex]->setActive(1);
            }
            
            
            
        } else if (mode == 3) {
           
            
            if (polyClick == 1) {
                
                printf("original x-coord: %d, original y-coord: %d \n", x, y);
                origX = x;
                origY = y;
                // Creates a new object using x and y coordinates (sets them)
                vertex * pt = new vertex(origX, origY, 0, 0, mode); //  ***** ****** MIGHT HAVE TO SWITCH 0's to 1's!!!!
                point.push_back(pt);
                vectorIndex++;
            
                polyClick++;
                ptCounter++;
                
                
                
                
                
            } else if (polyClick == 2) {
                
                float dx = (x - origX);
                float dy = (y - origY);
                
                float dx2 = dx * dx;
                float dy2 = dy * dy;
                float dt = sqrt(dx2+dy2);
              
                // sets values for direction vector
                point[vectorIndex]->setdirectY( (dy/dt)*2, mode);
                point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
                ptCounter++;
              
                polyClick++;
       
              
                
            } else if (polyClick == 3) {
              
             
                origX = x;
                origY = y;
                
                // sets new vertex values (v2)
                point[vectorIndex]->setX(origX, mode);
                point[vectorIndex]->setY(origY, mode);
                ptCounter++;
              
                polyClick = 2;
           
              
            }
            
        }
        
    }
        
        
}



// This function handles any primtives bouncing off the top, left, right, and bottom of the screens.

void bounceOff() {
    
    if (mode ==1) {
        for (int x  = 0; x < point.size(); x++) {

// If X-coordinate is at the left or right of the window
            if (point[x]->retX() <= 0 ) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
            
            } else if (point[x]->retX() >= w) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
            
            }
        
        
// If Y-coordinate is at the top or bottom of the window or the bottom
            if (point[x]->retY() <= 0) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
            
            } else if (point[x]->retY() >= h) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
            
            }
            
        
        }
        
    } else if (mode == 2) {
        
        
        for (int x = 0; x < point.size(); x++) {
           
// If X-coordinate is at the left or right of the window
            if (point[x]->retX() <= 0 ) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
                
            } else if (point[x]->retX() >= w) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
                
            }
            
// If X-coordinate is at the left or right of the window
            if (point[x]->retX2() <= 0 ) {
                point[x]->setdirectX2( (point[x]->getdirectX2() * -1));
                
            } else if (point[x]->retX2() >= w) {
                point[x]->setdirectX2( (point[x]->getdirectX2() * -1));
                
            }
            
            
            
// If Y-coordinate is at the top of the window or the bottom
            if (point[x]->retY() <= 0) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
                
            } else if (point[x]->retY() >= h) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
                
            }
            
 // If Y-coordinate is at the top or bottom of the window
            if (point[x]->retY() <= 0) {
                point[x]->setdirectY2( (point[x]->getdirectY2() * -1));
                
            } else if (point[x]->retY() >= h) {
                point[x]->setdirectY2( (point[x]->getdirectY2() * -1));
                
            }
            
            
        }
        
    } else if (mode == 3) {
        
        
        
        for (int x = 0; x < point.size(); x++) {
            for (int z = 0; z < point[x]->polyXSize(); z++) {
               
                
 // If X-coordinate is at the left or right of the window
                if (point[x]->retPolyXind(z) <= 0 ) {
                    point[x]->setIndexDX(-1, z);
                    
                } else if (point[x]->retPolyXind(z) >= w) {
                  point[x]->setIndexDX(-1, z);
                    
                }

// If Y-coordinate is at the top or bottom of the window
                if (point[x] -> retPolyYind(z) <= 0) {
                    
                    point[x]->setIndexYX(-1, z);
                } else if (point[x] ->retPolyYind(z) >= h){
                    point[x]->setIndexYX(-1, z);
                
            }
            
        }
        
    }
        
  }
    
}



// Callback that handles resize
void resize(int width, int height)
{
    w = width; //sets variable to width of window
    h = height; // sets height to height of window
    printf("width: %d, height: %d", w, h);
    
    glViewport(0,0, w, h); //resets viewport on resize window
    
}


void timer(int value)
{
    bounceOff();
    glutPostRedisplay();
    glutTimerFunc(0.01, timer, 0);
    
   
}

// initializes random colours on startup
void init() {

    srand(time(NULL));
    r =  (float)rand()/RAND_MAX;
    g =  (float)rand()/RAND_MAX;
    b =  (float)rand()/RAND_MAX;
}








// Main function
int main(int argc, char * argv[]) {
   
 
    glutInit(&argc, argv);
 
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Using Double Buffering and RGB (vs RGBA)
    
    
    //** Create our GLUT Window
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("ScreenSaver");
                                    //**
    
    //sets our callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0.2, timer, 0);
    
    init();
    
    glutMainLoop();
    
    
    
    
    
    return 0;
}
