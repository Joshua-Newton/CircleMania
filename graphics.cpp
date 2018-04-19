//
// Created by Joshua Newton on 1/18/18.
//
#include "graphics.h"
#include "graphicsConstants.h"

/** INIT **/

void init() {
    // Set up window size and player's initial position
    width = WIDTH;
    height = HEIGHT;
    player.setPosition(width/2,height/2);

/** HARD CODE BELOW FOR TESTING **/

/** HARD CODE ABOVE FOR TESTING **/
    // Set up the start screen
    startBackground.set_dimensions(width + 50, height + 50);
    startBackground.set_fill(BACKGROUND_COLOR);
    startBackground.set_position(-25, -25);

    // Set up all buttons, creating their dimensions, colors, and positions

    // Buttons

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

    mainMenuButton.set_dimensions(BUTTON_WIDTH,BUTTON_HEIGHT);
    mainMenuButton.set_fill(MAIN_MENU_BUTTON_COLOR);
    mainMenuButton.set_position(25,25);

    // Rectangles that will be used to display current settings in the settings menu

    playerSizeDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    playerSizeDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    playerSizeDisplay.set_position(200,200);

    slowSizeDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    slowSizeDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    slowSizeDisplay.set_position(playerSizeDisplay.get_x(),playerSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    mediumSizeDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    mediumSizeDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    mediumSizeDisplay.set_position(slowSizeDisplay.get_x(),slowSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    fastSizeDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    fastSizeDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    fastSizeDisplay.set_position(mediumSizeDisplay.get_x(),mediumSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    pickupSizeDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    pickupSizeDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    pickupSizeDisplay.set_position(fastSizeDisplay.get_x(),fastSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    playerSpeedDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    playerSpeedDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    playerSpeedDisplay.set_position(pickupSizeDisplay.get_x(),pickupSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    slowSpeedDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    slowSpeedDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    slowSpeedDisplay.set_position(playerSpeedDisplay.get_x(),playerSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    mediumSpeedDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    mediumSpeedDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    mediumSpeedDisplay.set_position(slowSpeedDisplay.get_x(),slowSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    fastSpeedDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    fastSpeedDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    fastSpeedDisplay.set_position(mediumSpeedDisplay.get_x(),mediumSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    bulletSpeedDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    bulletSpeedDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    bulletSpeedDisplay.set_position(fastSpeedDisplay.get_x(),fastSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);


    playerHealthDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    playerHealthDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    playerHealthDisplay.set_position(bulletSpeedDisplay.get_x(),bulletSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    slowHealthDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    slowHealthDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    slowHealthDisplay.set_position(playerHealthDisplay.get_x(),playerHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    mediumHealthDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    mediumHealthDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    mediumHealthDisplay.set_position(slowHealthDisplay.get_x(),slowHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    fastHealthDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    fastHealthDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    fastHealthDisplay.set_position(mediumHealthDisplay.get_x(),mediumHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    playerAmmoDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    playerAmmoDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    playerAmmoDisplay.set_position(fastHealthDisplay.get_x(),fastHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    pickupDropRateDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    pickupDropRateDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    pickupDropRateDisplay.set_position(playerAmmoDisplay.get_x(),playerAmmoDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    spawnRateDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    spawnRateDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    spawnRateDisplay.set_position(pickupDropRateDisplay.get_x(),pickupDropRateDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    spawnRateSecondsDisplay.set_dimensions(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT);
    spawnRateSecondsDisplay.set_fill(SETTINGS_DISPLAY_COLOR);
    spawnRateSecondsDisplay.set_position(spawnRateDisplay.get_x(),spawnRateDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);

    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(startButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(loadButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(resumeButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(saveButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(exitButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(exitButtonPause));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(restartGameButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(settingsButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(mainMenuButton));

    //menuButtonsVector[2]->set_position(BUTTON_X_POSITION, 200);

}


/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black
}

/** DISPLAY **/
#include "graphicsDisplay.h"

/** INPUTS **/
#include "graphicsInputs.h"

/** TIMERS **/
#include "graphicsTimers.h"

/** SAVING AND LOADING **/
#include "graphicsSavingLoading.h"

/** GRAPHICS PLAY **/


/* Main function: GLUT runs as a console application starting at main()  */
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

    glutTimerFunc(0, hitTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;

}