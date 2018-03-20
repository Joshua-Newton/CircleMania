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
// TODO: Make this customizable from in game, maybe make a text file that gets read when the game starts,
// TODO: gets written to from user input in a new screen.
// TODO: Make all speeds, healths, spawnrates, fire rate, starting ammo, ammo dropped, buffs, customizable
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
color BACKGROUND_COLOR = {0,0,0}; // Black
color SPEED_UP_COLOR = {0.5,.75,0.25};
color AMMO_COLOR = {0.25,0.5,0.75};
color HEALTH_COLOR = {0.25,0.25,0.75};
color SHOTGUN_COLOR = {0.75,0.5,0.5};
color NUKE_COLOR = {0.3, 0.5, 0.7};
color NUKE_CIRCLE_COLOR = {0.1, 0.5, 0.7};

// Bullet damage constant
int BULLET_DAMAGE = 1;

// Player's initial number of special Attacks
int PLAYER_SPECIALS = 10;

// Pickup Constants
int NUMBER_PICKUPS_IMPLEMENTED = 5; // The number of pickups that have been implemented into the game (number of children of Pickup class)
int DROP_RATE = 100; // Percentage
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
// Hollow Circle constant
HollowCircle NUKE_HOLLOW_CIRCLE(NUKE_INNER_RADIUS_INITIAL, NUKE_OUTER_RADIUS_INITIAL, NUKE_CIRCLE_COLOR,0,0);

// Save File constant
string SAVE_FILE = "SavedFile.txt";

// Vectors to contain bullets, enemies, and pickups, and nukes
vector<unique_ptr<Enemy>> enemies;
vector<Bullet> bulletsVector;
vector<unique_ptr<Pickup>> pickups;
vector<HollowCircle> nukes;

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

// Mouse global position variables
int MOUSE_X = 0;
int MOUSE_Y = 0;

// GLut variable, window dimensions
GLdouble width, height;
int wd;
int WIDTH = 1400;
int HEIGHT = 800;

// Variables for Button dimensions
int BUTTON_WIDTH = 200;
int BUTTON_HEIGHT = 75;
int BUTTON_X_POSITION =  (WIDTH/2) - (BUTTON_WIDTH/2);

/** HARD CODE BELOW FOR TESTING **/
//HollowCircle hollow(30,50,{1,1,0.2},WIDTH/2,HEIGHT/2);

/** HARD CODE ABOVE FOR TESTING **/

/***************** END OF DEFINING VARIABLES AND CONSTANTS ******************/

#endif //CIRCLE_MANIA_GRAPHICSCONSTANTS_H
