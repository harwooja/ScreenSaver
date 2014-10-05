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


bool ptClick = true;
int h, w;
float origX, origY;
float directX, directY;
int vectorIndex = -1;






void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
  
    gluOrtho2D(0, w, 0, h);
    
    glPointSize(10);
    
    glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
    
    
    for (int x  = 0; x < point.size(); x++) {
        glVertex2f(point[x]->vertex::retX()+(point[x]->getdirectX()), h - point[x]->vertex::retY()+(point[x]->getdirectY()) );
        point[x]->setX(point[x]->vertex::retX()+(point[x]->getdirectX()));
        point[x]->setY(point[x]->vertex::retY()+(point[x]->getdirectY()));
                               
    
    }
    
    
    
    
    glEnd();
    
    glutSwapBuffers();
    
    
    
    


}




void keyboard(unsigned char key, int x, int y){
    
    switch(key){
            
            case 'r': // reset to blank screen
            break;
            case 'a': // create random primitives
            break;
            case 'p': // pause animation
            break;
            case '+': // increase movement speed of vertices
            break;
            case '-': // decrease movement speed of vertices
            break;
            
            case 'b': // line width up
            break;
            case 'v': // line width down
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
      
            
        if (ptClick == true) {
           
            printf("original x-coord: %d, original y-coord: %d \n", x, y);
            origX = x;
            origY = y;
            ptClick = false;
            
            vertex * pt = new vertex(origX, origY, 0, 0);
            point.push_back(pt);
            vectorIndex++;
            
            
        } else if (ptClick == false){
            
            
            // If variable is false, save next point clicked x & y (for direction)
            
            
            
            
            point[vectorIndex]->setdirectY(  (y - origY) / (y+origY) );
            point[vectorIndex]->setdirectX(  (x - origX) / (x+origX) );
            
            
            ptClick = true;
            
        }
        

        
         
            
        

        
        
        
    
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
/*    posX ++;
    posY ++;
  */
   
    
    glutPostRedisplay();
    glutTimerFunc(0.1, timer, 0);
   
}



int main(int argc, char * argv[]) {
   
 
    glutInit(&argc, argv);
 
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Using Double Buffering and RGB (vs RGBA)
    
    
//** Create our GLUT Window
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("ScreenSaver");
                                    //**
    
    glEnable(GL_POINT_SMOOTH);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0.2, timer, 0);
    
   
    
    glutMainLoop();
    
    
    
    
    
    return 0;
}
