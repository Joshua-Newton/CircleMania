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

    // Triangles on the settings screen

    playerSizePlusTen.set_position(playerSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH / 2 , playerSizeDisplay.get_y() - SETTING_DISPLAY_MARGIN - SETTINGS_TRIANGLE_LENGTH);
    playerSizePlusOne.set_position(200 , 200);

    // Put all the menu button in a vector
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(startButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(loadButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(resumeButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(saveButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(exitButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(exitButtonPause));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(restartGameButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(settingsButton));
    menuButtonsVector.push_back(make_unique<Rectangle_Shape>(mainMenuButton));

    // Put all the settings displays in a vector
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(playerSizeDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(slowSizeDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(mediumSizeDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(fastSizeDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(pickupSizeDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(playerSpeedDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(slowSpeedDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(mediumSpeedDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(fastSpeedDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(bulletSpeedDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(playerHealthDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(slowHealthDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(mediumHealthDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(fastHealthDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(playerAmmoDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(pickupDropRateDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(spawnRateDisplay));
    settingsDisplaysVector.push_back(make_unique<Rectangle_Shape>(spawnRateSecondsDisplay));

    // Put all the triangles into their respective vectors

    // All triangles
    settingsTriangles.push_back(make_unique<TriangleUp>(playerSizePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(slowSizePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(mediumSizePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(fastSizePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(pickupSizePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(playerSpeedPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(slowSpeedPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(mediumSpeedPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(fastSpeedPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(bulletSpeedPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(playerHealthPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(slowHealthPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(mediumHealthPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(fastHealthPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(playerAmmoPlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(pickupDropRatePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(spawnRatePlusTen));
    settingsTriangles.push_back(make_unique<TriangleUp>(spawnRateSecondsPlusTen));
    settingsTriangles.push_back(make_unique<TriangleLeft>(playerSizeMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(slowSizeMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(mediumSizeMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(fastSizeMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(pickupSizeMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(playerSpeedMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(slowSpeedMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(mediumSpeedMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(fastSpeedMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(bulletSpeedMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(playerHealthMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(slowHealthMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(mediumHealthMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(fastHealthMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(playerAmmoMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(pickupDropRateMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(spawnRateMinusOne));
    settingsTriangles.push_back(make_unique<TriangleLeft>(spawnRateSecondsMinusOne));
    settingsTriangles.push_back(make_unique<TriangleDown>(playerSizeMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(slowSizeMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(mediumSizeMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(fastSizeMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(pickupSizeMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(playerSpeedMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(slowSpeedMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(mediumSpeedMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(fastSpeedMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(bulletSpeedMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(playerHealthMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(slowHealthMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(mediumHealthMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(fastHealthMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(playerAmmoMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(pickupDropRateMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(spawnRateMinusTen));
    settingsTriangles.push_back(make_unique<TriangleDown>(spawnRateSecondsMinusTen));
    settingsTriangles.push_back(make_unique<TriangleRight>(playerSizePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(slowSizePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(mediumSizePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(fastSizePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(pickupSizePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(playerSpeedPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(slowSpeedPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(mediumSpeedPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(fastSpeedPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(bulletSpeedPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(playerHealthPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(slowHealthPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(mediumHealthPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(fastHealthPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(playerAmmoPlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(pickupDropRatePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(spawnRatePlusOne));
    settingsTriangles.push_back(make_unique<TriangleRight>(spawnRateSecondsPlusOne));

    // TriangleUp
    settingsTriangleUps.push_back(make_unique<TriangleUp>(playerSizePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(slowSizePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(mediumSizePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(fastSizePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(pickupSizePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(playerSpeedPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(slowSpeedPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(mediumSpeedPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(fastSpeedPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(bulletSpeedPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(playerHealthPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(slowHealthPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(mediumHealthPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(fastHealthPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(playerAmmoPlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(pickupDropRatePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(spawnRatePlusTen));
    settingsTriangleUps.push_back(make_unique<TriangleUp>(spawnRateSecondsPlusTen));

    // TriangleLeft
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(playerSizeMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(slowSizeMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(mediumSizeMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(fastSizeMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(pickupSizeMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(playerSpeedMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(slowSpeedMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(mediumSpeedMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(fastSpeedMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(bulletSpeedMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(playerHealthMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(slowHealthMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(mediumHealthMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(fastHealthMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(playerAmmoMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(pickupDropRateMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(spawnRateMinusOne));
    settingsTriangleLefts.push_back(make_unique<TriangleLeft>(spawnRateSecondsMinusOne));

    // TriangleDown
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(playerSizeMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(slowSizeMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(mediumSizeMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(fastSizeMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(pickupSizeMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(playerSpeedMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(slowSpeedMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(mediumSpeedMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(fastSpeedMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(bulletSpeedMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(playerHealthMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(slowHealthMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(mediumHealthMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(fastHealthMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(playerAmmoMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(pickupDropRateMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(spawnRateMinusTen));
    settingsTriangleDowns.push_back(make_unique<TriangleDown>(spawnRateSecondsMinusTen));

    // TriangleRight
    settingsTriangleRights.push_back(make_unique<TriangleRight>(playerSizePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(slowSizePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(mediumSizePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(fastSizePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(pickupSizePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(playerSpeedPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(slowSpeedPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(mediumSpeedPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(fastSpeedPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(bulletSpeedPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(playerHealthPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(slowHealthPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(mediumHealthPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(fastHealthPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(playerAmmoPlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(pickupDropRatePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(spawnRatePlusOne));
    settingsTriangleRights.push_back(make_unique<TriangleRight>(spawnRateSecondsPlusOne));

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