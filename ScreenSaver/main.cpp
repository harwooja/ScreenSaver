//
//  main.cpp
//  ScreenSaver
//
//  Created by Jake Harwood on 2014-09-27.
//  Copyright (c) 2014 Jake Harwood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "vertex.h"

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



// * indicates something on the heap
vector <vertex *> point;


int mode = 1; // handles our mode, default is dot mode
int lineClick = 1;
int polyClick = 1; // handles if we are drawing a new line/polygon point or not
bool ptClick = true; // handles if we are drawing a new point (user click)
int h, w; // window height, width
float origX, origY; // originalX vertex, originalY vertex
float directX, directY; // directionXvalue, directionYvalue
int vectorIndex = -1; // handles index of the vector we are targeting
int speed = 1; // handles speed at which primitives will move around the screen
bool pause = false; // handles if the screen is paused or not
int ptCounter = 0;



void display(void) {
    
    
   
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
  
    gluOrtho2D(0, w, 0, h);
    
    glPointSize(3);
    
    
    if (mode == 1) {
        glEnable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
            glColor3f(1, 0, 0);

        if (point.size() > 0) {
            
        for (int x  = 0; x < point.size(); x++) {
            
            glVertex2f(point[x]->retX()+(point[x]->getdirectX()), h - point[x]->retY()+(point[x]->getdirectY()) );
            
            
            if (pause == false ) {
                point[x]->setX(point[x]->retX()+(point[x]->getdirectX()) * speed, mode );
                point[x]->setY(point[x]->retY()+(point[x]->getdirectY()) * speed, mode );
            }
        
        }
    
    }
    
    
    } else if (mode == 2){
    
        
        glBegin(GL_LINES);
            glColor3f(1, 4, 0);
        
        
        
        
        if (point.size() > 0) {
            
            
               for (int x  = 0; x < point.size(); x++) {
                   
                   if (point[x]->getActive() == 1) {
                       glVertex2f(point[x]->retX()+(point[x]->getdirectX()), h - point[x]->retY()+(point[x]->getdirectY()) );
                       glVertex2f(point[x]->retX2()+(point[x]->getdirectX2()), h - point[x]->retY2()+(point[x]->getdirectY2()) );
                   
                    if (pause == false) {
                        point[x]->setX(point[x]->retX()+(point[x]->getdirectX()) * speed, mode );
                        point[x]->setY(point[x]->retY()+(point[x]->getdirectY()) * speed, mode );
                   
                        point[x]->setX2(point[x]->retX2()+(point[x]->getdirectX2()) * speed );
                        point[x]->setY2(point[x]->retY2()+(point[x]->getdirectY2()) * speed );
                    }
                       
                   }
                   
                   
               }
            
        }
    
    } else if (mode == 3) {
        
        

        
  

        
   
        
        if (point.size() > 0) {
            
            
       
           
            for (int x = 0; x < point.size(); x++) {
                
                if (point[x]->getActive() == 1) {
             
                    

                    
                    for (int z = 0; z < point[x]->polyXSize(); z++) {
                        glBegin(GL_POLYGON);
                        glColor3f(1, 4, 0);
                        
                        glVertex2f(point[x]->retPolyXind(z), h - point[x]->retPolyYind(z));
                        
                        
                        // point[x]-> retPolyXind(z) + point[x]->retPolyXD(z)
                        
                        point[x]->setIndexX(point[x]-> retPolyXind(z) + point[x]->retPolyXD(z), z);
                        point[x]->setIndexY(point[x]-> retPolyYind(z) + point[x]->retPolyYD(z), z);
                    
                        //   point[x]->setX(point[x]->retX()+(point[x]->getdirectX()) * speed, mode );
                        
                    }

                    
                    
                    glEnd();
                
             
                }
            
                
                
                
                
            }
            
            
        }
     
        
    }
    



    
    glEnd();
    
    glutSwapBuffers();
    
}




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
            case '[':

            
            
            break;
            
            
            
            case ' ':
            
            if (mode == 3 && (ptCounter % 2) == 0) {
            
            ptCounter = 0;
            point[vectorIndex]->setActive(1);
            
            polyClick = 1;
            }
            
            
            break;
        
            
            case 'a': // create random primitives
            
            
            
            
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
            
            case 'b': // line width up
            break;
            case 'v': // line width down
            break;
            
            case '1':
            mode = 1;
            point.clear();
            ptClick = true;
            vectorIndex = -1;
            speed = 1;
            origX = 0;
            origY = 0;
            lineClick = 1;
            
            break;
            case '2':
            mode = 2;
            point.clear();
            ptClick = true;
            speed = 1;
            origX = 0;
            origY = 0;
            vectorIndex = -1;
            lineClick = 1;
            
            
            break;
            case '3':
            mode = 3;
            point.clear();
            ptClick = true;
            speed = 1;
            origX = 0;
            origY = 0;
            vectorIndex = -1;
            lineClick = 1;
            
            break;
            
            case 27:
            exit(0);
            break;
            
            
    }
    
}


void mouse(int button, int state, int x, int y) {
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // If variable = true, create a new object
      
        
        if (mode == 1) {
            
        if (ptClick == true) {
           
            printf("original x-coord: %d, original y-coord: %d \n", x, y);
            origX = x;
            origY = y;
            ptClick = false;
            
            vertex * pt = new vertex(origX, origY, 0, 0, mode);
            point.push_back(pt);
            vectorIndex++;
            
         
            
            
            
        } else if (ptClick == false){
            
            
            // If variable is false, save next point clicked x & y (for direction)
            
           
            float dx = (x - origX);
            float dy = (y - origY);
            
            float dx2 = dx * dx;
            float dy2 = dy * dy;
            float dt = sqrt(dx2+dy2);
            
            
            point[vectorIndex]->setdirectY( (dy/dt)*2, mode );
            point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
            
            
         
            ptClick = true;
            
            
        }
        
        
        } else if (mode == 2) {
            
            

            if (lineClick == 1){
                
              
                printf("original x-coord: %d, original y-coord: %d \n", x, y);
                origX = x;
                origY = y;
            
                
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
                
                
                point[vectorIndex]->setdirectY( (dy/dt)*2, mode );
                point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
                
                
                
                lineClick++;
            
            } else if (lineClick == 3) {
                
                origX = x;
                origY = y;
                
                point[vectorIndex]->setX2(origX);
                point[vectorIndex]->setY2(origY);
                
                
                lineClick++;
            } else if (lineClick == 4) {
                
                
                float dx = (x - origX);
                float dy = (y - origY);
                
                float dx2 = dx * dx;
                float dy2 = dy * dy;
                float dt = sqrt(dx2+dy2);
                
                
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
              
                
                
                point[vectorIndex]->setdirectY( (dy/dt)*2, mode);
                point[vectorIndex]->setdirectX( (dx/dt)*2, mode );
                ptCounter++;
              
                polyClick++;
       
              
                
            } else if (polyClick == 3) {
              
             
                origX = x;
                origY = y;
                
               
                
                point[vectorIndex]->setX(origX, mode);
                point[vectorIndex]->setY(origY, mode);
                ptCounter++;
              
                polyClick = 2;
           
              
            }
            
            
            
            
            
        }
    
    
        
        
        
        
        }
        
        
    }





void bounceOff() {
    
    if (mode ==1) {
        for (int x  = 0; x < point.size(); x++) {

// If X-coordinate is at the left or right of the window
            if (point[x]->retX() <= 0 ) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
            
            } else if (point[x]->retX() >= w) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
            
            }
        
        
// If Y-coordinate is at the top of the window or the bottom
            if (point[x]->retY() <= 0) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
            
            } else if (point[x]->retY() >= h) {
                point[x]->setdirectY( (point[x]->getdirectY() * -1), mode);
            
            }
            
        
        }
        
    } else if (mode == 2) {
        
        
        for (int x = 0; x < point.size(); x++) {
           
            
            if (point[x]->retX() <= 0 ) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
                
            } else if (point[x]->retX() >= w) {
                point[x]->setdirectX( (point[x]->getdirectX() * -1), mode);
                
            }
            
            
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
            
        
            if (point[x]->retY() <= 0) {
                point[x]->setdirectY2( (point[x]->getdirectY2() * -1));
                
            } else if (point[x]->retY() >= h) {
                point[x]->setdirectY2( (point[x]->getdirectY2() * -1));
                
            }
            
            
        }
        
    } else if (mode == 3) {
        
        
        
        
        
        
        
        
        
        
        
    }
    
}


void resize(int width, int height)
{
    w = width;
    h = height;
    printf("width: %d, height: %d", w, h);
    
    glViewport(0,0, w, h);
    
}


void timer(int value)
{
    bounceOff();
    glutPostRedisplay();
    glutTimerFunc(0.01, timer, 0);
    
   
}



int main(int argc, char * argv[]) {
   
 
    glutInit(&argc, argv);
 
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Using Double Buffering and RGB (vs RGBA)
    
    
//** Create our GLUT Window
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("ScreenSaver");
                                    //**
    
 
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0.2, timer, 0);
    
   
    
    glutMainLoop();
    
    
    
    
    
    return 0;
}
