//
// Created by Joshua Newton on 1/18/18.
//

#ifndef CIRCLE_MANIA_GRAPHICS_H
#define CIRCLE_MANIA_GRAPHICS_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void InitGL(void);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Handles "mouse cursor moved with mouse button pressed" events
void drag(int x,int y);

// Calls itself after a specified time
void timer(int extra);
void enemySpawnTimer(int extra);
void pickupHandlerTimer(int extra);
void fireRateTimer(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);

#endif //CIRCLE_MANIA_GRAPHICS_H
