//
// Created by Joshua Newton on 2/5/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSCONSTANTS_H
#define CIRCLE_MANIA_GRAPHICSCONSTANTS_H

#include "Player.h"
#include "Shapes.h"
#include "Pickup.h"
#include "Enemy.h"
#include "Bullet.h"

/***************** DEFINING VARIABLES AND CONSTANTS ******************/
// Speed constants
// NOTE: DO NOT REDUCE SPEEDS BELOW 2, OR THE MOVE CALCULATION WILL "BREAK"
int SLOW_SPEED = 3;
int MEDIUM_SPEED = 6;
int FAST_SPEED = 9;
int PLAYER_SPEED = 6;
int BULLET_SPEED = (FAST_SPEED + 1);
int NUKE_EXPANSION_RATE = 8; // increase in both radii each screen refresh

// Radius constants
int PLAYER_RADIUS = 10;
int SLOW_RADIUS = 40;
int MEDIUM_RADIUS = 30;
int FAST_RADIUS = 20;
int BULLET_RADIUS = 5;
int PICKUP_RADIUS = 8;
int NUKE_INNER_RADIUS_INITIAL = 1*PLAYER_RADIUS;
int NUKE_OUTER_RADIUS_INITIAL = 3*NUKE_INNER_RADIUS_INITIAL;
int HIT_CIRCLE_SIZE = 5; //Pixels away from inner radius that outer radius will reach

// Triangle length constants
int SETTINGS_TRIANGLE_LENGTH = 20;

// Spawn rate (in milliseconds)
int ENEMY_SPAWNRATE = 1000;

// Health Constants
int PLAYER_HEALTH = 3;
int SLOW_HEALTH = 7;
int MEDIUM_HEALTH = 5;
int FAST_HEALTH = 2;

// Color Constants
color PLAYER_COLOR = {0,0,1}; // Blue
color SLOW_COLOR = {1,0,0}; // Red
color MEDIUM_COLOR = {0,1,1}; // Light Blue
color FAST_COLOR = {1,0,1}; // Pink
color BULLET_COLOR = {1,1,1}; // White
color HOVER_COLOR = {0,1,0}; // Green
color START_BUTTON_COLOR = {1,0,0}; // Red
color SAVE_BUTTON_COLOR = {1,0,0}; // Red
color RESUME_BUTTON_COLOR = {1,0,0}; // Red
color RESTART_GAME_BUTTON_COLOR = {1,0,0}; // Red
color LOAD_BUTTON_COLOR = {1,0,0}; // Red
color EXIT_BUTTON_COLOR = {1,0,0}; // Red
color SETTINGS_BUTTON_COLOR = {1,0,0}; // Red
color MAIN_MENU_BUTTON_COLOR = {1,0,0}; // Red
color DEFAULT_MENU_BUTTON_COLOR = {1,0,0}; // Red
color BACKGROUND_COLOR = {0,0,0}; // Black
color SPEED_UP_COLOR = {0.5,.75,0.25};
color AMMO_COLOR = {0.25,0.5,0.75};
color HEALTH_COLOR = {0.25,0.25,0.75};
color SHOTGUN_COLOR = {0.75,0.5,0.5};
color NUKE_COLOR = {0.3, 0.5, 0.7};
color NUKE_CIRCLE_COLOR = {0.1, 0.5, 0.7};
color HIT_COLOR = {0.9, 0.5, 0.1};
color SETTINGS_DISPLAY_COLOR = {1,1,1}; // White
color SETTINGS_TRIANGLE_COLOR = {1,0,0}; // Red

// Bullet damage constant
int BULLET_DAMAGE = 1;

// Player's initial number of special Attacks
int PLAYER_SPECIALS = 10;

// Pickup Constants
int NUMBER_PICKUPS_IMPLEMENTED = 5; // The number of pickups that have been implemented into the game (number of children of Pickup class)
int DROP_RATE = 10; // Percentage
int PICKUP_LIFETIME = 20; // Seconds
int SPEED_BUFF = 2; // Pixels per frame
int SPEED_BUFF_TIME = 15; // Seconds
int AMMO_REGAINED = 2;
int HEALTH_REGAINED = 1;
int SHOTGUN_TIME = 5; // Seconds

// Pickup string constants
string SPEED_STRING = "SPEED";
string AMMO_STRING = "AMMO";
string HEALTH_STRING = "HEALTH";
string SHOTGUN_STRING = "SHOTGUN";
string NUKE_STRING = "NUKE";

// Score constants
int SLOW_SCORE = 1;
int MEDIUM_SCORE = 2;
int FAST_SCORE = 3;

// Circle constants
Circle PLAYER_CIRCLE(PLAYER_RADIUS,PLAYER_COLOR);
Circle SLOW_CIRCLE(SLOW_RADIUS, SLOW_COLOR);
Circle MEDIUM_CIRCLE(MEDIUM_RADIUS, MEDIUM_COLOR);
Circle FAST_CIRCLE(FAST_RADIUS, FAST_COLOR);
Circle SPEED_UP_CIRCLE(PICKUP_RADIUS,SPEED_UP_COLOR);
Circle AMMO_CIRCLE(PICKUP_RADIUS,AMMO_COLOR);
Circle HEALTH_CIRCLE(PICKUP_RADIUS,HEALTH_COLOR);
Circle SHOTGUN_CIRCLE(PICKUP_RADIUS,SHOTGUN_COLOR);
Circle NUKE_CIRCLE(PICKUP_RADIUS, NUKE_COLOR);
// Hollow Circle constants
HollowCircle NUKE_HOLLOW_CIRCLE(NUKE_INNER_RADIUS_INITIAL, NUKE_OUTER_RADIUS_INITIAL, NUKE_CIRCLE_COLOR,0,0);
HollowCircle SLOW_HIT_CIRCLE(SLOW_RADIUS, SLOW_RADIUS + HIT_CIRCLE_SIZE, HIT_COLOR, 0, 0);
HollowCircle MEDIUM_HIT_CIRCLE(MEDIUM_RADIUS, MEDIUM_RADIUS + HIT_CIRCLE_SIZE, HIT_COLOR, 0, 0);
HollowCircle FAST_HIT_CIRCLE(FAST_RADIUS, FAST_RADIUS + HIT_CIRCLE_SIZE, HIT_COLOR, 0, 0);

// Save File constant
string SAVE_FILE = "SavedFile.txt";

// Vectors to contain bullets, enemies, and pickups, and nukes
vector<unique_ptr<Enemy>> enemies;
vector<Bullet> bulletsVector;
vector<unique_ptr<Pickup>> pickups;
vector<HollowCircle> nukes;

// GLut variable, window dimensions
GLdouble width, height;
int wd;
int WIDTH = 1400;
int HEIGHT = 800;

// Variables for Button dimensions and/or spacing
int BUTTON_WIDTH = 200;
int BUTTON_HEIGHT = 75;
int BUTTON_X_POSITION =  (WIDTH/2) - (BUTTON_WIDTH/2);
int SETTING_DISPLAY_WIDTH = 100;
int SETTING_DISPLAY_HEIGHT = 20;
int SETTING_DISPLAY_MARGIN = 45;
//int SETTING_TRIANGLE_MARGIN = 2;
int SETTING_DISPLAY_X_1 = 200;
int SETTING_DISPLAY_X_2 = 600;
int SETTING_DISPLAY_Y = 200;
// Variables for Max values for settings
int PLAYER_RADIUS_MAX = 200;
int SLOW_RADIUS_MAX = 200;
int MEDIUM_RADIUS_MAX = 200;
int FAST_RADIUS_MAX = 200;
int PICKUP_RADIUS_MAX = 200;
int SPEED_MAX = 100;
int HEALTH_MAX = 100;
int AMMO_MAX = 10000;
int DROP_RATE_MAX = 100;
int SPAWN_RATE_MAX = 100000;
// Variables for Min values for settings
int PLAYER_RADIUS_MIN = 1;
int SLOW_RADIUS_MIN = 1;
int MEDIUM_RADIUS_MIN = 1;
int FAST_RADIUS_MIN = 1;
int PICKUP_RADIUS_MIN = 1;
int SPEED_MIN = 2;
int HEALTH_MIN = 1;
int AMMO_MIN = 0;
int DROP_RATE_MIN = 0;
int SPAWN_RATE_MIN = 1;

// Player variable
Player player(PLAYER_HEALTH,PLAYER_SPEED,PLAYER_SPECIALS,PLAYER_CIRCLE);

// bools to keep track of player movements
bool moveUp;
bool moveDown;
bool moveLeft;
bool moveRight;
// bool for holding down the shooting key
bool shooting;
// Player Fire Rate, one bullet every FIRE_RATE milliseconds
int FIRE_RATE = 175;

// enum to keep track of which screen the game is on
enum screenType {start, game, endGame, pauseGame, settings};

// variable to keep track of which screen the player is on
screenType screen;

// Rectangles used for background and buttons
Rectangle_Shape startBackground;

Rectangle_Shape startButton;
Rectangle_Shape loadButton;
Rectangle_Shape resumeButton;
Rectangle_Shape saveButton;
Rectangle_Shape exitButton;
Rectangle_Shape exitButtonPause;
Rectangle_Shape restartGameButton;
Rectangle_Shape settingsButton;
Rectangle_Shape mainMenuButton;
vector<unique_ptr<Rectangle_Shape>> menuButtonsVector;

// Rectangles used for settings display
Rectangle_Shape playerSizeDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,SETTING_DISPLAY_X_1,SETTING_DISPLAY_Y);
Rectangle_Shape slowSizeDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,playerSizeDisplay.get_x(),playerSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape mediumSizeDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,slowSizeDisplay.get_x(),slowSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape fastSizeDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,mediumSizeDisplay.get_x(),mediumSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape pickupSizeDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,fastSizeDisplay.get_x(),fastSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape playerSpeedDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,pickupSizeDisplay.get_x(),pickupSizeDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape slowSpeedDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,playerSpeedDisplay.get_x(),playerSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape mediumSpeedDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,slowSpeedDisplay.get_x(),slowSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape fastSpeedDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,mediumSpeedDisplay.get_x(),mediumSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape bulletSpeedDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,SETTING_DISPLAY_X_2, SETTING_DISPLAY_Y);
Rectangle_Shape playerHealthDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,bulletSpeedDisplay.get_x(),bulletSpeedDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape slowHealthDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,playerHealthDisplay.get_x(),playerHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape mediumHealthDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,slowHealthDisplay.get_x(),slowHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape fastHealthDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,mediumHealthDisplay.get_x(),mediumHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape playerAmmoDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,fastHealthDisplay.get_x(),fastHealthDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape pickupDropRateDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,playerAmmoDisplay.get_x(),playerAmmoDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape spawnRateDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,pickupDropRateDisplay.get_x(),pickupDropRateDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
Rectangle_Shape spawnRateSecondsDisplay(SETTING_DISPLAY_WIDTH,SETTING_DISPLAY_HEIGHT,SETTINGS_DISPLAY_COLOR,spawnRateDisplay.get_x(),spawnRateDisplay.get_y() + SETTING_DISPLAY_HEIGHT + SETTING_DISPLAY_MARGIN);
vector<unique_ptr<Rectangle_Shape>> settingsDisplaysVector;

// Triangles to be used for settings arrows
TriangleUp playerSizePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSizeDisplay);
TriangleDown playerSizeMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSizeDisplay);
TriangleLeft playerSizeMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSizeDisplay);
TriangleRight playerSizePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSizeDisplay);

TriangleUp slowSizePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSizeDisplay);
TriangleDown slowSizeMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSizeDisplay);
TriangleLeft slowSizeMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSizeDisplay);
TriangleRight slowSizePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSizeDisplay);

TriangleUp mediumSizePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSizeDisplay);
TriangleDown mediumSizeMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSizeDisplay);
TriangleLeft mediumSizeMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSizeDisplay);
TriangleRight mediumSizePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSizeDisplay);

TriangleUp fastSizePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSizeDisplay);
TriangleDown fastSizeMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSizeDisplay);
TriangleLeft fastSizeMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSizeDisplay);
TriangleRight fastSizePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSizeDisplay);

TriangleUp pickupSizePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupSizeDisplay);
TriangleDown pickupSizeMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupSizeDisplay);
TriangleLeft pickupSizeMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupSizeDisplay);
TriangleRight pickupSizePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupSizeDisplay);

TriangleUp playerSpeedPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSpeedDisplay);
TriangleDown playerSpeedMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSpeedDisplay);
TriangleLeft playerSpeedMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSpeedDisplay);
TriangleRight playerSpeedPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerSpeedDisplay);

TriangleUp slowSpeedPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSpeedDisplay);
TriangleDown slowSpeedMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSpeedDisplay);
TriangleLeft slowSpeedMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSpeedDisplay);
TriangleRight slowSpeedPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowSpeedDisplay);

TriangleUp mediumSpeedPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSpeedDisplay);
TriangleDown mediumSpeedMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSpeedDisplay);
TriangleLeft mediumSpeedMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSpeedDisplay);
TriangleRight mediumSpeedPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumSpeedDisplay);

TriangleUp fastSpeedPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSpeedDisplay);
TriangleDown fastSpeedMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSpeedDisplay);
TriangleLeft fastSpeedMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSpeedDisplay);
TriangleRight fastSpeedPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastSpeedDisplay);

TriangleUp bulletSpeedPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, bulletSpeedDisplay);
TriangleDown bulletSpeedMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, bulletSpeedDisplay);
TriangleLeft bulletSpeedMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, bulletSpeedDisplay);
TriangleRight bulletSpeedPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, bulletSpeedDisplay);

TriangleUp playerHealthPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerHealthDisplay);
TriangleDown playerHealthMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerHealthDisplay);
TriangleLeft playerHealthMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerHealthDisplay);
TriangleRight playerHealthPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerHealthDisplay);

TriangleUp slowHealthPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowHealthDisplay);
TriangleDown slowHealthMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowHealthDisplay);
TriangleLeft slowHealthMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowHealthDisplay);
TriangleRight slowHealthPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, slowHealthDisplay);

TriangleUp mediumHealthPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumHealthDisplay);
TriangleDown mediumHealthMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumHealthDisplay);
TriangleLeft mediumHealthMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumHealthDisplay);
TriangleRight mediumHealthPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, mediumHealthDisplay);

TriangleUp fastHealthPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastHealthDisplay);
TriangleDown fastHealthMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastHealthDisplay);
TriangleLeft fastHealthMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastHealthDisplay);
TriangleRight fastHealthPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, fastHealthDisplay);

TriangleUp playerAmmoPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerAmmoDisplay);
TriangleDown playerAmmoMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerAmmoDisplay);
TriangleLeft playerAmmoMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerAmmoDisplay);
TriangleRight playerAmmoPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, playerAmmoDisplay);

TriangleUp pickupDropRatePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupDropRateDisplay);
TriangleDown pickupDropRateMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupDropRateDisplay);
TriangleLeft pickupDropRateMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupDropRateDisplay);
TriangleRight pickupDropRatePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, pickupDropRateDisplay);

TriangleUp spawnRatePlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateDisplay);
TriangleDown spawnRateMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateDisplay);
TriangleLeft spawnRateMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateDisplay);
TriangleRight spawnRatePlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateDisplay);

TriangleUp spawnRateSecondsPlusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateSecondsDisplay);
TriangleDown spawnRateSecondsMinusTen(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateSecondsDisplay);
TriangleLeft spawnRateSecondsMinusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateSecondsDisplay);
TriangleRight spawnRateSecondsPlusOne(SETTINGS_TRIANGLE_LENGTH, SETTINGS_TRIANGLE_COLOR, spawnRateSecondsDisplay);

// Vector for all settings triangles
vector<unique_ptr<Triangle>> settingsTriangles;
// Vectors for specific types of triangles in the settings screen
vector<unique_ptr<TriangleUp>> settingsTriangleUps;
vector<unique_ptr<TriangleDown>> settingsTriangleDowns;
vector<unique_ptr<TriangleLeft>> settingsTriangleLefts;
vector<unique_ptr<TriangleRight>> settingsTriangleRights;

//TODO: Add enabling/disabling certain pickups
//TODO: Add enabling/disabling HUD


// Mouse global position variables
int MOUSE_X = 0;
int MOUSE_Y = 0;

/** HARD CODE BELOW FOR TESTING **/

/** HARD CODE ABOVE FOR TESTING **/

/***************** END OF DEFINING VARIABLES AND CONSTANTS ******************/

#endif //CIRCLE_MANIA_GRAPHICSCONSTANTS_H
