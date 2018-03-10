//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSPLAY_H
#define CIRCLE_MANIA_GRAPHICSPLAY_H

#include "graphicsConstants.h
#include "graphics.h"
#include "graphicsInit.h"
#include "graphicsInputs.h"

int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("CIRCLE-MANIA" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    glutKeyboardUpFunc(kbdUp);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse movement with a button pressed
    glutMotionFunc(drag);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timers
    glutTimerFunc(0, timer, 0);

    glutTimerFunc(0, enemySpawnTimer, 0);

    glutTimerFunc(0, pickupHandlerTimer, 0);

    glutTimerFunc(0, fireRateTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;

}

#endif //CIRCLE_MANIA_GRAPHICSPLAY_H
