//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSINIT_H
#define CIRCLE_MANIA_GRAPHICSINIT_H

#include "graphics.h"
#include "graphicsConstants.h"


void init() {
    // Set up window size and player's initial position
    width = WIDTH;
    height = HEIGHT;
    player.setPosition(width/2,height/2);

    // Constant that requires width to be set

/** HARD CODE BELOW FOR TESTING **/
//     nukes.push_back(hollow);
//     NUKE_HOLLOW_CIRCLE.set_position(400,400);
//     nukes.push_back(NUKE_HOLLOW_CIRCLE);
/** HARD CODE ABOVE FOR TESTING **/

    // Set up the start screen
    startBackground.set_dimensions(width + 50, height + 50);
    startBackground.set_fill(BACKGROUND_COLOR);
    startBackground.set_position(-25, -25);

    // Set up all buttons, creating their dimensions, colors, and positions
    startButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    startButton.set_fill(START_BUTTON_COLOR);
    startButton.set_position(BUTTON_X_POSITION, 300);

    resumeButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    resumeButton.set_fill(RESUME_BUTTON_COLOR);
    resumeButton.set_position(BUTTON_X_POSITION, 200);

    restartGameButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    restartGameButton.set_fill(RESTART_GAME_BUTTON_COLOR);
    restartGameButton.set_position(BUTTON_X_POSITION, 300);

    loadButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    loadButton.set_fill(LOAD_BUTTON_COLOR);
    loadButton.set_position(BUTTON_X_POSITION, 400);

    saveButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    saveButton.set_fill(SAVE_BUTTON_COLOR);
    saveButton.set_position(BUTTON_X_POSITION, 500);

    exitButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    exitButton.set_fill(EXIT_BUTTON_COLOR);
    exitButton.set_position(BUTTON_X_POSITION, 500);

    exitButtonPause.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    exitButtonPause.set_fill(EXIT_BUTTON_COLOR);
    exitButtonPause.set_position(BUTTON_X_POSITION, 600);

    settingsButton.set_dimensions(BUTTON_WIDTH, BUTTON_HEIGHT);
    settingsButton.set_fill(SETTINGS_BUTTON_COLOR);
    settingsButton.set_position(BUTTON_X_POSITION, 600);
/**  NOTE: ANY CHANGES IN init HERE MUST BE REPLICATED IN graphics.cpp  */
}


/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black
}

#endif //CIRCLE_MANIA_GRAPHICSINIT_H
