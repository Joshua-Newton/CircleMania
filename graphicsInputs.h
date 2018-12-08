//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSINPUTS_H
#define CIRCLE_MANIA_GRAPHICSINPUTS_H

#include "graphicsConstants.h"
#include "graphics.h"
#include "graphicsSavingLoading.h"

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
// Detect Keyboard key releases
void kbdUp(unsigned char key, int x, int y){

    switch (key) {
        // Down = S
        case (83):
            moveDown = false;
            break;
        case (115):
            moveDown = false;
            break;
            // Left = A
        case (65):
            moveLeft = false;
            break;
        case (97):
            moveLeft = false;
            break;
            // Right = D
        case (68):
            moveRight = false;
            break;
        case (100):
            moveRight = false;
            break;
            // Up = W
        case (87):
            moveUp = false;
            break;
        case (119):
            moveUp = false;
            break;
    }
}



// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {

    for (int i = 0; i < menuButtonsVector.size(); i++){
        menuButtonsVector[i]->set_fill(DEFAULT_MENU_BUTTON_COLOR);
    }


    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    switch (key) {
        // Pause the game = 'space' , 'P', or 'p', in that order
        case (32):
            if (screen == game) {
                screen = pauseGame;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            else if (screen == pauseGame){
                screen = game;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            break;
        case (80):
            if (screen == game) {
                screen = pauseGame;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            else if (screen == pauseGame){
                screen = game;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            break;
        case (112):
            if (screen == game) {
                screen = pauseGame;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            else if (screen == pauseGame){
                screen = game;
                MOUSE_X = x;
                MOUSE_Y = y;
            }
            break;
            // Down = S
        case (83):
            moveDown = true;
            break;
        case (115):
            moveDown = true;
            break;
            // Left = A
        case (65):
            moveLeft = true;
            break;
        case (97):
            moveLeft = true;
            break;
            // Right = D
        case (68):
            moveRight = true;
            break;
        case (100):
            moveRight = true;
            break;
            // Up = W
        case (87):
            moveUp = true;
            break;
        case (119):
            moveUp = true;
            break;

    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {

    // Arrow keys cause the player to shoot while in the game
    if(screen == game) {
        switch (key) {
            case GLUT_KEY_DOWN:
                player.shoot(player.getX(), player.getY() + 200, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
                break;
            case GLUT_KEY_LEFT:
                player.shoot(player.getX() - 200, player.getY(), bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
                break;
            case GLUT_KEY_RIGHT:
                player.shoot(player.getX() + 200, player.getY(), bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
                break;
            case GLUT_KEY_UP:
                player.shoot(player.getX(), player.getY() - 200, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
                break;
        }

    }

    if (screen == settings){
        switch (key) {
            case GLUT_KEY_LEFT:
                if (playerSizeDisplay.is_overlapping(x,y)){
                    if (PLAYER_RADIUS > PLAYER_RADIUS_MIN) {
                        PLAYER_RADIUS--;
                    }
                }
                if (slowSizeDisplay.is_overlapping(x,y)){
                    if (SLOW_RADIUS > SLOW_RADIUS_MIN) {
                        SLOW_RADIUS--;
                    }
                }
                if (mediumSizeDisplay.is_overlapping(x,y)){
                    if (MEDIUM_RADIUS > MEDIUM_RADIUS_MIN) {
                        MEDIUM_RADIUS--;
                    }
                }
                if (fastSizeDisplay.is_overlapping(x,y)){
                    if (FAST_RADIUS > FAST_RADIUS_MIN) {
                        FAST_RADIUS--;
                    }
                }
                if (pickupSizeDisplay.is_overlapping(x,y)){
                    if (PICKUP_RADIUS > PICKUP_RADIUS_MIN) {
                        PICKUP_RADIUS--;
                    }
                }
                if (playerSpeedDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPEED > SPEED_MIN) {
                        PLAYER_SPEED--;
                    }
                }
                if (slowSpeedDisplay.is_overlapping(x,y)){
                    if (SLOW_SPEED > SPEED_MIN) {
                        SLOW_SPEED--;
                    }
                }
                if (mediumSpeedDisplay.is_overlapping(x,y)){
                    if (MEDIUM_SPEED > SPEED_MIN) {
                        MEDIUM_SPEED--;
                    }
                }
                if (fastSpeedDisplay.is_overlapping(x,y)){
                    if (FAST_SPEED > SPEED_MIN) {
                        FAST_SPEED--;
                    }
                }
                if (bulletSpeedDisplay.is_overlapping(x,y)){
                    if (BULLET_SPEED > SPEED_MIN) {
                        BULLET_SPEED--;
                    }
                }
                if (playerHealthDisplay.is_overlapping(x,y)){
                    if (PLAYER_HEALTH > HEALTH_MIN) {
                        PLAYER_HEALTH--;
                    }
                }
                if (slowHealthDisplay.is_overlapping(x,y)){
                    if (SLOW_HEALTH > HEALTH_MIN) {
                        SLOW_HEALTH--;
                    }
                }
                if (mediumHealthDisplay.is_overlapping(x,y)){
                    if (MEDIUM_HEALTH > HEALTH_MIN) {
                        MEDIUM_HEALTH--;
                    }
                }
                if (fastHealthDisplay.is_overlapping(x,y)){
                    if (FAST_HEALTH > HEALTH_MIN) {
                        FAST_HEALTH--;
                    }
                }
                if (playerAmmoDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPECIALS > AMMO_MIN) {
                        PLAYER_SPECIALS--;
                    }
                }
                if (pickupDropRateDisplay.is_overlapping(x,y)){
                    if (DROP_RATE > DROP_RATE_MIN) {
                        DROP_RATE--;
                    }
                }
                if (spawnRateDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE > SPAWN_RATE_MIN) {
                        ENEMY_SPAWNRATE--;
                    }
                }
                if (spawnRateSecondsDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE > SPAWN_RATE_MIN) {
                        ENEMY_SPAWNRATE -= 1000;
                        if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                            ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
                        }
                    }
                }
                break;
            case GLUT_KEY_RIGHT :
                if (playerSizeDisplay.is_overlapping(x,y)){
                    if (PLAYER_RADIUS < PLAYER_RADIUS_MAX) {
                        PLAYER_RADIUS++;
                    }
                }
                if (slowSizeDisplay.is_overlapping(x,y)){
                    if (SLOW_RADIUS < SLOW_RADIUS_MAX) {
                        SLOW_RADIUS++;
                    }
                }
                if (mediumSizeDisplay.is_overlapping(x,y)){
                    if (MEDIUM_RADIUS < MEDIUM_RADIUS_MAX) {
                        MEDIUM_RADIUS++;
                    }
                }
                if (fastSizeDisplay.is_overlapping(x,y)){
                    if (FAST_RADIUS < FAST_RADIUS_MAX) {
                        FAST_RADIUS++;
                    }
                }
                if (pickupSizeDisplay.is_overlapping(x,y)){
                    if (PICKUP_RADIUS < PICKUP_RADIUS_MAX) {
                        PICKUP_RADIUS++;
                    }
                }
                if (playerSpeedDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPEED < SPEED_MAX) {
                        PLAYER_SPEED++;
                    }
                }
                if (slowSpeedDisplay.is_overlapping(x,y)){
                    if (SLOW_SPEED < SPEED_MAX) {
                        SLOW_SPEED++;
                    }
                }
                if (mediumSpeedDisplay.is_overlapping(x,y)){
                    if (MEDIUM_SPEED < SPEED_MAX) {
                        MEDIUM_SPEED++;
                    }
                }
                if (fastSpeedDisplay.is_overlapping(x,y)){
                    if (FAST_SPEED < SPEED_MAX) {
                        FAST_SPEED++;
                    }
                }
                if (bulletSpeedDisplay.is_overlapping(x,y)){
                    if (BULLET_SPEED < SPEED_MAX) {
                        BULLET_SPEED++;
                    }
                }
                if (playerHealthDisplay.is_overlapping(x,y)){
                    if (PLAYER_HEALTH < HEALTH_MAX) {
                        PLAYER_HEALTH++;
                    }
                }
                if (slowHealthDisplay.is_overlapping(x,y)){
                    if (SLOW_HEALTH < HEALTH_MAX) {
                        SLOW_HEALTH++;
                    }
                }
                if (mediumHealthDisplay.is_overlapping(x,y)){
                    if (MEDIUM_HEALTH < HEALTH_MAX) {
                        MEDIUM_HEALTH++;
                    }
                }
                if (fastHealthDisplay.is_overlapping(x,y)){
                    if (FAST_HEALTH < HEALTH_MAX) {
                        FAST_HEALTH++;
                    }
                }
                if (playerAmmoDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPECIALS < AMMO_MAX) {
                        PLAYER_SPECIALS++;
                    }
                }
                if (pickupDropRateDisplay.is_overlapping(x,y)){
                    if (DROP_RATE < DROP_RATE_MAX) {
                        DROP_RATE++;
                    }
                }
                if (spawnRateDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE < SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE++;
                    }
                }
                if (spawnRateSecondsDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE < SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE += 1000;
                        if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                            ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
                        }
                    }
                }
                break;
            case GLUT_KEY_UP :
                if (playerSizeDisplay.is_overlapping(x,y)){
                    PLAYER_RADIUS += 10;
                    if (PLAYER_RADIUS > PLAYER_RADIUS_MAX){
                        PLAYER_RADIUS = PLAYER_RADIUS_MAX;
                    }
                }
                if (slowSizeDisplay.is_overlapping(x,y)){
                    SLOW_RADIUS += 10;
                    if (SLOW_RADIUS > SLOW_RADIUS_MAX){
                        SLOW_RADIUS = SLOW_RADIUS_MAX;
                    }
                }
                if (mediumSizeDisplay.is_overlapping(x,y)){
                    MEDIUM_RADIUS += 10;
                    if (MEDIUM_RADIUS > MEDIUM_RADIUS_MAX){
                        MEDIUM_RADIUS = MEDIUM_RADIUS_MAX;
                    }
                }
                if (fastSizeDisplay.is_overlapping(x,y)){
                    FAST_RADIUS += 10;
                    if (FAST_RADIUS > FAST_RADIUS_MAX){
                        FAST_RADIUS = FAST_RADIUS_MAX;
                    }
                }
                if (pickupSizeDisplay.is_overlapping(x,y)){
                    PICKUP_RADIUS += 10;
                    if (PICKUP_RADIUS > PICKUP_RADIUS_MAX){
                        PICKUP_RADIUS = PICKUP_RADIUS_MAX;
                    }
                }
                if (playerSpeedDisplay.is_overlapping(x,y)){
                    PLAYER_SPEED += 10;
                    if (PLAYER_SPEED > SPEED_MAX){
                        PLAYER_SPEED = SPEED_MAX;
                    }
                }
                if (slowSpeedDisplay.is_overlapping(x,y)){
                    SLOW_SPEED += 10;
                    if (SLOW_SPEED > SPEED_MAX){
                        SLOW_SPEED = SPEED_MAX;
                    }
                }
                if (mediumSpeedDisplay.is_overlapping(x,y)){
                    MEDIUM_SPEED += 10;
                    if (MEDIUM_SPEED > SPEED_MAX){
                        MEDIUM_SPEED = SPEED_MAX;
                    }
                }
                if (fastSpeedDisplay.is_overlapping(x,y)){
                    FAST_SPEED += 10;
                    if (FAST_SPEED > SPEED_MAX){
                        FAST_SPEED = SPEED_MAX;
                    }
                }
                if (bulletSpeedDisplay.is_overlapping(x,y)){
                    BULLET_SPEED += 10;
                    if (BULLET_SPEED > SPEED_MAX){
                        BULLET_SPEED = SPEED_MAX;
                    }
                }
                if (playerHealthDisplay.is_overlapping(x,y)){
                    PLAYER_HEALTH += 10;
                    if (PLAYER_HEALTH > HEALTH_MAX){
                        PLAYER_HEALTH = HEALTH_MAX;
                    }
                }
                if (slowHealthDisplay.is_overlapping(x,y)){
                    SLOW_HEALTH += 10;
                    if (SLOW_HEALTH > HEALTH_MAX){
                        SLOW_HEALTH = HEALTH_MAX;
                    }
                }
                if (mediumHealthDisplay.is_overlapping(x,y)){
                    MEDIUM_HEALTH += 10;
                    if (MEDIUM_HEALTH > HEALTH_MAX){
                        MEDIUM_HEALTH = HEALTH_MAX;
                    }
                }
                if (fastHealthDisplay.is_overlapping(x,y)){
                    FAST_HEALTH += 10;
                    if (FAST_HEALTH > HEALTH_MAX){
                        FAST_HEALTH = HEALTH_MAX;
                    }
                }
                if (playerAmmoDisplay.is_overlapping(x,y)){
                    PLAYER_SPECIALS += 10;
                    if (PLAYER_SPECIALS > AMMO_MAX){
                        PLAYER_SPECIALS = AMMO_MAX;
                    }
                }
                if (pickupDropRateDisplay.is_overlapping(x,y)){
                    DROP_RATE += 10;
                    if (DROP_RATE > DROP_RATE_MAX){
                        DROP_RATE = DROP_RATE_MAX;
                    }
                }
                if (spawnRateDisplay.is_overlapping(x,y)){
                    ENEMY_SPAWNRATE += 10;
                    if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
                    }
                }
                if (spawnRateSecondsDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE < SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE += 10000;
                        if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                            ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
                        }
                    }
                }
                break;
            case GLUT_KEY_DOWN :
                if (playerSizeDisplay.is_overlapping(x,y)){
                    PLAYER_RADIUS -= 10;
                    if (PLAYER_RADIUS < PLAYER_RADIUS_MIN){
                        PLAYER_RADIUS = PLAYER_RADIUS_MIN;
                    }
                }
                if (slowSizeDisplay.is_overlapping(x,y)){
                    SLOW_RADIUS -= 10;
                    if (SLOW_RADIUS < SLOW_RADIUS_MIN){
                        SLOW_RADIUS = SLOW_RADIUS_MIN;
                    }
                }
                if (mediumSizeDisplay.is_overlapping(x,y)){
                    MEDIUM_RADIUS -= 10;
                    if (MEDIUM_RADIUS < MEDIUM_RADIUS_MIN){
                        MEDIUM_RADIUS = MEDIUM_RADIUS_MIN;
                    }
                }
                if (fastSizeDisplay.is_overlapping(x,y)){
                    FAST_RADIUS -= 10;
                    if (FAST_RADIUS < FAST_RADIUS_MIN){
                        FAST_RADIUS = FAST_RADIUS_MIN;
                    }
                }
                if (pickupSizeDisplay.is_overlapping(x,y)){
                    PICKUP_RADIUS -= 10;
                    if (PICKUP_RADIUS < PICKUP_RADIUS_MIN){
                        PICKUP_RADIUS = PICKUP_RADIUS_MIN;
                    }
                }
                if (playerSpeedDisplay.is_overlapping(x,y)){
                    PLAYER_SPEED -= 10;
                    if (PLAYER_SPEED < SPEED_MIN){
                        PLAYER_SPEED = SPEED_MIN;
                    }
                }
                if (slowSpeedDisplay.is_overlapping(x,y)){
                    SLOW_SPEED -= 10;
                    if (SLOW_SPEED < SPEED_MIN){
                        SLOW_SPEED = SPEED_MIN;
                    }
                }
                if (mediumSpeedDisplay.is_overlapping(x,y)){
                    MEDIUM_SPEED -= 10;
                    if (MEDIUM_SPEED < SPEED_MIN){
                        MEDIUM_SPEED = SPEED_MIN;
                    }
                }
                if (fastSpeedDisplay.is_overlapping(x,y)){
                    FAST_SPEED -= 10;
                    if (FAST_SPEED < SPEED_MIN){
                        FAST_SPEED = SPEED_MIN;
                    }
                }
                if (bulletSpeedDisplay.is_overlapping(x,y)){
                    BULLET_SPEED -= 10;
                    if (BULLET_SPEED < SPEED_MIN){
                        BULLET_SPEED = SPEED_MIN;
                    }
                }
                if (playerHealthDisplay.is_overlapping(x,y)){
                    PLAYER_HEALTH -= 10;
                    if (PLAYER_HEALTH < HEALTH_MIN){
                        PLAYER_HEALTH = HEALTH_MIN;
                    }
                }
                if (slowHealthDisplay.is_overlapping(x,y)){
                    SLOW_HEALTH -= 10;
                    if (SLOW_HEALTH < HEALTH_MIN){
                        SLOW_HEALTH = HEALTH_MIN;
                    }
                }
                if (mediumHealthDisplay.is_overlapping(x,y)){
                    MEDIUM_HEALTH -= 10;
                    if (MEDIUM_HEALTH < HEALTH_MIN){
                        MEDIUM_HEALTH = HEALTH_MIN;
                    }
                }
                if (fastHealthDisplay.is_overlapping(x,y)){
                    FAST_HEALTH -= 10;
                    if (FAST_HEALTH < HEALTH_MIN){
                        FAST_HEALTH = HEALTH_MIN;
                    }
                }
                if (playerAmmoDisplay.is_overlapping(x,y)){
                    PLAYER_SPECIALS -= 10;
                    if (PLAYER_SPECIALS < AMMO_MIN){
                        PLAYER_SPECIALS = AMMO_MIN;
                    }
                }
                if (pickupDropRateDisplay.is_overlapping(x,y)){
                    DROP_RATE -= 10;
                    if (DROP_RATE < DROP_RATE_MIN){
                        DROP_RATE = DROP_RATE_MIN;
                    }
                }
                if (spawnRateDisplay.is_overlapping(x,y)){
                    ENEMY_SPAWNRATE -= 10;
                    if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN) {
                        ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
                    }
                }
                if (spawnRateSecondsDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE > SPAWN_RATE_MIN) {
                        ENEMY_SPAWNRATE -= 10000;
                        if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                            ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
                        }
                    }
                }
                break;
        }
    }
    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {


    // Handles hovering events outside of the game
    if (screen != game){

        for (int i = 0; i < menuButtonsVector.size(); i++){
            menuButtonsVector[i]->set_fill(HOVER_COLOR);

            if (menuButtonsVector[i]->is_overlapping(x,y)){
                menuButtonsVector[i]->set_fill(HOVER_COLOR);
            }
            else {
                menuButtonsVector[i]->set_fill(DEFAULT_MENU_BUTTON_COLOR);
            }
        }

        for (int i = 0; i < settingsTriangles.size(); i++){
            settingsTriangles[i]->set_fill(HOVER_COLOR);

            if (settingsTriangles[i]->is_overlapping(x,y)){
                settingsTriangles[i]->set_fill(HOVER_COLOR);
            }
            else {
                settingsTriangles[i]->set_fill(SETTINGS_TRIANGLE_COLOR);
            }

        }

    }



    glutPostRedisplay();
}

// Occurs when the mouse is dragged (click held while mouse moves)
void drag(int x,int y){
    if (screen == game){
        MOUSE_X = x;
        MOUSE_Y = y;
    }
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    for (int i = 0; i < menuButtonsVector.size(); i++){
        menuButtonsVector[i]->set_fill(DEFAULT_MENU_BUTTON_COLOR);
    }

    /** Interactions on start screen **/
    if (screen == start) {
        //if start game button (rectangle) is clicked, start the game
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && startButton.is_overlapping(x, y)) {
            player.setPosition(width / 2, height / 2);
            player.setRadius(PLAYER_RADIUS);
            player.setHealth(PLAYER_HEALTH);
            player.setScore(0);
            player.setSpecialAttacks(PLAYER_SPECIALS);
            player.setBoostBool(false);
            player.setBoostTime(0);
            player.setShotgunBool(false);
            player.setShotgunTime(0);

            enemies.clear();
            bulletsVector.clear();
            pickups.clear();
            nukes.clear();
            screen = game;
        }
        //if the load game button (rectangle) is clicked, load the game
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && loadButton.is_overlapping(x, y)) {
            ifstream saveFile(SAVE_FILE);
            if (saveFile) {
                enemies.clear();
                bulletsVector.clear();
                pickups.clear();
                nukes.clear();
                loading(player, enemies, bulletsVector, pickups, nukes,SAVE_FILE);
                screen = game;
            }
        }
        // if the exit button is clicked, exit the game, destroying the window
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && exitButton.is_overlapping(x, y)) {
            glutDestroyWindow(wd);
            exit(0);
        }
        // If the settings button is clicked, move to the settings screen
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && settingsButton.is_overlapping(x, y)) {
            screen = settings;
        }
    }

    /** Interactions on pause screen **/
    if (screen == pauseGame) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && resumeButton.is_overlapping(x, y)) {
            screen = game;
        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && saveButton.is_overlapping(x, y)) {
            saving(player, enemies, bulletsVector, pickups, nukes, SAVE_FILE);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && loadButton.is_overlapping(x, y)) {
            enemies.clear();
            bulletsVector.clear();
            pickups.clear();
            nukes.clear();
            loading(player, enemies, bulletsVector, pickups, nukes, SAVE_FILE);
            screen = game;
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && exitButtonPause.is_overlapping(x, y)) {
            glutDestroyWindow(wd);
            exit(0);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && restartGameButton.is_overlapping(x, y)) {
            player.setPosition(width / 2, height / 2);
            player.setHealth(PLAYER_HEALTH);
            player.setScore(0);
            player.setSpecialAttacks(PLAYER_SPECIALS);
            player.setBoostBool(false);
            player.setBoostTime(0);
            player.setShotgunBool(false);
            player.setShotgunTime(0);

            enemies.clear();
            bulletsVector.clear();
            pickups.clear();
            screen = game;
        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mainMenuButton.is_overlapping(x, y)) {
            screen = start;

        }
    }

    /** Interactions on settings screen **/
    if (screen == settings) {
        // Go to the main menu
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mainMenuButton.is_overlapping(x, y)) {
            screen = start;
            // Apply settings that are necessary
            SLOW_CIRCLE.set_radius(SLOW_RADIUS);
            MEDIUM_CIRCLE.set_radius(MEDIUM_RADIUS);
            FAST_CIRCLE.set_radius(FAST_RADIUS);
            NUKE_CIRCLE.set_radius(PICKUP_RADIUS);
            AMMO_CIRCLE.set_radius(PICKUP_RADIUS);
            SPEED_UP_CIRCLE.set_radius(PICKUP_RADIUS);
            SHOTGUN_CIRCLE.set_radius(PICKUP_RADIUS);
            HEALTH_CIRCLE.set_radius(PICKUP_RADIUS);
            player.setSpeed(PLAYER_SPEED);
            SLOW_HIT_CIRCLE.setRadiusInner(SLOW_RADIUS);
            SLOW_HIT_CIRCLE.setRadiusOuter(SLOW_RADIUS + HIT_CIRCLE_SIZE);
            MEDIUM_HIT_CIRCLE.setRadiusInner(MEDIUM_RADIUS);
            MEDIUM_HIT_CIRCLE.setRadiusOuter(MEDIUM_RADIUS + HIT_CIRCLE_SIZE);
            FAST_HIT_CIRCLE.setRadiusInner(FAST_RADIUS);
            FAST_HIT_CIRCLE.setRadiusOuter(FAST_RADIUS + HIT_CIRCLE_SIZE);
        }
        // TODO: Uncomment this when default settings is ready
//        // Load the default settings
//        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && defaultSettingsButton.is_overlapping(x, y)){
//            loadSettings(DEFAULT_SETTINGS_FILE);
//        }
        // Load the easy settings
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && easySettingsButton.is_overlapping(x, y)){
            loadSettings(EASY_SETTINGS_FILE);
        }
        // Load the normal settings
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && normalSettingsButton.is_overlapping(x, y)){
            loadSettings(NORMAL_SETTINGS_FILE);
        }
        // Load the hard settings
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && hardSettingsButton.is_overlapping(x, y)){
            loadSettings(HARD_SETTINGS_FILE);
        }
        // Player Size
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSizePlusTen.is_overlapping(x, y)) {
            PLAYER_RADIUS += 10;
            if (PLAYER_RADIUS > PLAYER_RADIUS_MAX){
                PLAYER_RADIUS = PLAYER_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSizeMinusTen.is_overlapping(x, y)) {
            PLAYER_RADIUS -= 10;
            if (PLAYER_RADIUS < PLAYER_RADIUS_MIN){
                PLAYER_RADIUS = PLAYER_RADIUS_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSizePlusOne.is_overlapping(x, y)) {
            PLAYER_RADIUS += 1;
            if (PLAYER_RADIUS > PLAYER_RADIUS_MAX){
                PLAYER_RADIUS = PLAYER_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSizeMinusOne.is_overlapping(x, y)) {
            PLAYER_RADIUS -= 1;
            if (PLAYER_RADIUS < PLAYER_RADIUS_MIN){
                PLAYER_RADIUS = PLAYER_RADIUS_MIN;
            }
        }
        // Slow Size
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSizePlusTen.is_overlapping(x, y)) {
            SLOW_RADIUS += 10;
            if (SLOW_RADIUS > SLOW_RADIUS_MAX){
                SLOW_RADIUS = SLOW_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSizeMinusTen.is_overlapping(x, y)) {
            SLOW_RADIUS -= 10;
            if (SLOW_RADIUS < SLOW_RADIUS_MIN){
                SLOW_RADIUS = SLOW_RADIUS_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSizePlusOne.is_overlapping(x, y)) {
            SLOW_RADIUS += 1;
            if (SLOW_RADIUS > SLOW_RADIUS_MAX){
                SLOW_RADIUS = SLOW_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSizeMinusOne.is_overlapping(x, y)) {
            SLOW_RADIUS -= 1;
            if (SLOW_RADIUS < SLOW_RADIUS_MIN){
                SLOW_RADIUS = SLOW_RADIUS_MIN;
            }
        }
        // Medium Size
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSizePlusTen.is_overlapping(x, y)) {
            MEDIUM_RADIUS += 10;
            if (MEDIUM_RADIUS > MEDIUM_RADIUS_MAX){
                MEDIUM_RADIUS = MEDIUM_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSizeMinusTen.is_overlapping(x, y)) {
            MEDIUM_RADIUS -= 10;
            if (MEDIUM_RADIUS < MEDIUM_RADIUS_MIN){
                MEDIUM_RADIUS = MEDIUM_RADIUS_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSizePlusOne.is_overlapping(x, y)) {
            MEDIUM_RADIUS += 1;
            if (MEDIUM_RADIUS > MEDIUM_RADIUS_MAX){
                MEDIUM_RADIUS = MEDIUM_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSizeMinusOne.is_overlapping(x, y)) {
            MEDIUM_RADIUS -= 1;
            if (MEDIUM_RADIUS < MEDIUM_RADIUS_MIN){
                MEDIUM_RADIUS = MEDIUM_RADIUS_MIN;
            }
        }
        // Fast Size
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSizePlusTen.is_overlapping(x, y)) {
            FAST_RADIUS += 10;
            if (FAST_RADIUS > FAST_RADIUS_MAX){
                FAST_RADIUS = FAST_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSizeMinusTen.is_overlapping(x, y)) {
            FAST_RADIUS -= 10;
            if (FAST_RADIUS < FAST_RADIUS_MIN){
                FAST_RADIUS = FAST_RADIUS_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSizePlusOne.is_overlapping(x, y)) {
            FAST_RADIUS += 1;
            if (FAST_RADIUS > FAST_RADIUS_MAX){
                FAST_RADIUS = FAST_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSizeMinusOne.is_overlapping(x, y)) {
            FAST_RADIUS -= 1;
            if (FAST_RADIUS < FAST_RADIUS_MIN){
                FAST_RADIUS = FAST_RADIUS_MIN;
            }
        }
        // Pickup Size
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupSizePlusTen.is_overlapping(x, y)) {
            PICKUP_RADIUS += 10;
            if (PICKUP_RADIUS > PICKUP_RADIUS_MAX){
                PICKUP_RADIUS = PICKUP_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupSizeMinusTen.is_overlapping(x, y)) {
            PICKUP_RADIUS -= 10;
            if (PICKUP_RADIUS < PICKUP_RADIUS_MIN){
                PICKUP_RADIUS = PICKUP_RADIUS_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupSizePlusOne.is_overlapping(x, y)) {
            PICKUP_RADIUS += 1;
            if (PICKUP_RADIUS > PICKUP_RADIUS_MAX){
                PICKUP_RADIUS = PICKUP_RADIUS_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupSizeMinusOne.is_overlapping(x, y)) {
            PICKUP_RADIUS -= 1;
            if (PICKUP_RADIUS < PICKUP_RADIUS_MIN){
                PICKUP_RADIUS = PICKUP_RADIUS_MIN;
            }
        }
        // Player Speed
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSpeedPlusTen.is_overlapping(x, y)) {
            PLAYER_SPEED += 10;
            if (PLAYER_SPEED > SPEED_MAX){
                PLAYER_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSpeedMinusTen.is_overlapping(x, y)) {
            PLAYER_SPEED -= 10;
            if (PLAYER_SPEED < SPEED_MIN){
                PLAYER_SPEED = SPEED_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSpeedPlusOne.is_overlapping(x, y)) {
            PLAYER_SPEED += 1;
            if (PLAYER_SPEED > SPEED_MAX){
                PLAYER_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerSpeedMinusOne.is_overlapping(x, y)) {
            PLAYER_SPEED -= 1;
            if (PLAYER_SPEED < SPEED_MIN){
                PLAYER_SPEED = SPEED_MIN;
            }
        }
        // Slow Speed
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSpeedPlusTen.is_overlapping(x, y)) {
            SLOW_SPEED += 10;
            if (SLOW_SPEED > SPEED_MAX){
                SLOW_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSpeedMinusTen.is_overlapping(x, y)) {
            SLOW_SPEED -= 10;
            if (SLOW_SPEED < SPEED_MIN){
                SLOW_SPEED = SPEED_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSpeedPlusOne.is_overlapping(x, y)) {
            SLOW_SPEED += 1;
            if (SLOW_SPEED > SPEED_MAX){
                SLOW_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowSpeedMinusOne.is_overlapping(x, y)) {
            SLOW_SPEED -= 1;
            if (SLOW_SPEED < SPEED_MIN){
                SLOW_SPEED = SPEED_MIN;
            }
        }
        // Medium Speed
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSpeedPlusTen.is_overlapping(x, y)) {
            MEDIUM_SPEED += 10;
            if (MEDIUM_SPEED > SPEED_MAX){
                MEDIUM_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSpeedMinusTen.is_overlapping(x, y)) {
            MEDIUM_SPEED -= 10;
            if (MEDIUM_SPEED < SPEED_MIN){
                MEDIUM_SPEED = SPEED_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSpeedPlusOne.is_overlapping(x, y)) {
            MEDIUM_SPEED += 1;
            if (MEDIUM_SPEED > SPEED_MAX){
                MEDIUM_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumSpeedMinusOne.is_overlapping(x, y)) {
            MEDIUM_SPEED -= 1;
            if (MEDIUM_SPEED < SPEED_MIN){
                MEDIUM_SPEED = SPEED_MIN;
            }
        }
        // Fast Speed
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSpeedPlusTen.is_overlapping(x, y)) {
            FAST_SPEED += 10;
            if (FAST_SPEED > SPEED_MAX){
                FAST_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSpeedMinusTen.is_overlapping(x, y)) {
            FAST_SPEED -= 10;
            if (FAST_SPEED < SPEED_MIN){
                FAST_SPEED = SPEED_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSpeedPlusOne.is_overlapping(x, y)) {
            FAST_SPEED += 1;
            if (FAST_SPEED > SPEED_MAX){
                FAST_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastSpeedMinusOne.is_overlapping(x, y)) {
            FAST_SPEED -= 1;
            if (FAST_SPEED < SPEED_MIN){
                FAST_SPEED = SPEED_MIN;
            }
        }
        // Bullet Speed
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && bulletSpeedPlusTen.is_overlapping(x, y)) {
            BULLET_SPEED += 10;
            if (BULLET_SPEED > SPEED_MAX){
                BULLET_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && bulletSpeedMinusTen.is_overlapping(x, y)) {
            BULLET_SPEED -= 10;
            if (BULLET_SPEED < SPEED_MIN){
                BULLET_SPEED = SPEED_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && bulletSpeedPlusOne.is_overlapping(x, y)) {
            BULLET_SPEED += 1;
            if (BULLET_SPEED > SPEED_MAX){
                BULLET_SPEED = SPEED_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && bulletSpeedMinusOne.is_overlapping(x, y)) {
            BULLET_SPEED -= 1;
            if (BULLET_SPEED < SPEED_MIN){
                BULLET_SPEED = SPEED_MIN;
            }
        }
        // Player Health
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerHealthPlusTen.is_overlapping(x, y)) {
            PLAYER_HEALTH += 10;
            if (PLAYER_HEALTH > HEALTH_MAX){
                PLAYER_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerHealthMinusTen.is_overlapping(x, y)) {
            PLAYER_HEALTH -= 10;
            if (PLAYER_HEALTH < HEALTH_MIN){
                PLAYER_HEALTH = HEALTH_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerHealthPlusOne.is_overlapping(x, y)) {
            PLAYER_HEALTH += 1;
            if (PLAYER_HEALTH > HEALTH_MAX){
                PLAYER_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerHealthMinusOne.is_overlapping(x, y)) {
            PLAYER_HEALTH -= 1;
            if (PLAYER_HEALTH < HEALTH_MIN){
                PLAYER_HEALTH = HEALTH_MIN;
            }
        }
        // Slow Health
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowHealthPlusTen.is_overlapping(x, y)) {
            SLOW_HEALTH += 10;
            if (SLOW_HEALTH > HEALTH_MAX){
                SLOW_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowHealthMinusTen.is_overlapping(x, y)) {
            SLOW_HEALTH -= 10;
            if (SLOW_HEALTH < HEALTH_MIN){
                SLOW_HEALTH = HEALTH_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowHealthPlusOne.is_overlapping(x, y)) {
            SLOW_HEALTH += 1;
            if (SLOW_HEALTH > HEALTH_MAX){
                SLOW_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && slowHealthMinusOne.is_overlapping(x, y)) {
            SLOW_HEALTH -= 1;
            if (SLOW_HEALTH < HEALTH_MIN){
                SLOW_HEALTH = HEALTH_MIN;
            }
        }
        // Medium Health
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumHealthPlusTen.is_overlapping(x, y)) {
            MEDIUM_HEALTH += 10;
            if (MEDIUM_HEALTH > HEALTH_MAX){
                MEDIUM_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumHealthMinusTen.is_overlapping(x, y)) {
            MEDIUM_HEALTH -= 10;
            if (MEDIUM_HEALTH < HEALTH_MIN){
                MEDIUM_HEALTH = HEALTH_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumHealthPlusOne.is_overlapping(x, y)) {
            MEDIUM_HEALTH += 1;
            if (MEDIUM_HEALTH > HEALTH_MAX){
                MEDIUM_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mediumHealthMinusOne.is_overlapping(x, y)) {
            MEDIUM_HEALTH -= 1;
            if (MEDIUM_HEALTH < HEALTH_MIN){
                MEDIUM_HEALTH = HEALTH_MIN;
            }
        }
        // Fast Health
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastHealthPlusTen.is_overlapping(x, y)) {
            FAST_HEALTH += 10;
            if (FAST_HEALTH > HEALTH_MAX){
                FAST_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastHealthMinusTen.is_overlapping(x, y)) {
            FAST_HEALTH -= 10;
            if (FAST_HEALTH < HEALTH_MIN){
                FAST_HEALTH = HEALTH_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastHealthPlusOne.is_overlapping(x, y)) {
            FAST_HEALTH += 1;
            if (FAST_HEALTH > HEALTH_MAX){
                FAST_HEALTH = HEALTH_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fastHealthMinusOne.is_overlapping(x, y)) {
            FAST_HEALTH -= 1;
            if (FAST_HEALTH < HEALTH_MIN){
                FAST_HEALTH = HEALTH_MIN;
            }
        }
        // Player Ammo
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerAmmoPlusTen.is_overlapping(x, y)) {
            PLAYER_SPECIALS += 10;
            if (PLAYER_SPECIALS > AMMO_MAX){
                PLAYER_SPECIALS = AMMO_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerAmmoMinusTen.is_overlapping(x, y)) {
            PLAYER_SPECIALS -= 10;
            if (PLAYER_SPECIALS < AMMO_MIN){
                PLAYER_SPECIALS = AMMO_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerAmmoPlusOne.is_overlapping(x, y)) {
            PLAYER_SPECIALS += 1;
            if (PLAYER_SPECIALS > AMMO_MAX){
                PLAYER_SPECIALS = AMMO_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerAmmoMinusOne.is_overlapping(x, y)) {
            PLAYER_SPECIALS -= 1;
            if (PLAYER_SPECIALS < AMMO_MIN){
                PLAYER_SPECIALS = AMMO_MIN;
            }
        }
        // Pickup Drop Rate
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupDropRatePlusTen.is_overlapping(x, y)) {
            DROP_RATE += 10;
            if (DROP_RATE > DROP_RATE_MAX){
                DROP_RATE = DROP_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupDropRateMinusTen.is_overlapping(x, y)) {
            DROP_RATE -= 10;
            if (DROP_RATE < DROP_RATE_MIN){
                DROP_RATE = DROP_RATE_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupDropRatePlusOne.is_overlapping(x, y)) {
            DROP_RATE += 1;
            if (DROP_RATE > DROP_RATE_MAX){
                DROP_RATE = DROP_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && pickupDropRateMinusOne.is_overlapping(x, y)) {
            DROP_RATE -= 1;
            if (DROP_RATE < DROP_RATE_MIN){
                DROP_RATE = DROP_RATE_MIN;
            }
        }
        // Spawn Rate (milliseconds
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRatePlusTen.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE += 10;
            if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateMinusTen.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE -= 10;
            if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRatePlusOne.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE += 1;
            if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateMinusOne.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE -= 1;
            if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
            }
        }
        // Spawn Rate (seconds)
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateSecondsPlusTen.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE += 10000;
            if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateSecondsMinusTen.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE -= 10000;
            if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateSecondsPlusOne.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE += 1000;
            if (ENEMY_SPAWNRATE > SPAWN_RATE_MAX){
                ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && spawnRateSecondsMinusOne.is_overlapping(x, y)) {
            ENEMY_SPAWNRATE -= 1000;
            if (ENEMY_SPAWNRATE < SPAWN_RATE_MIN){
                ENEMY_SPAWNRATE = SPAWN_RATE_MIN;
            }
        }


    }
    /** Interactions on game over screen **/
    if (screen == endGame) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && startButton.is_overlapping(x, y)) {
            player.setPosition(width / 2, height / 2);
            player.setRadius(PLAYER_RADIUS);
            player.setHealth(PLAYER_HEALTH);
            player.setScore(0);
            player.setSpecialAttacks(PLAYER_SPECIALS);
            player.setBoostBool(false);
            player.setBoostTime(0);
            player.setShotgunBool(false);
            player.setShotgunTime(0);

            enemies.clear();
            bulletsVector.clear();
            pickups.clear();
            nukes.clear();
            screen = game;
        }
            // Load game
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && loadButton.is_overlapping(x, y)) {
            enemies.clear();
            bulletsVector.clear();
            nukes.clear();
            pickups.clear();
            loading(player, enemies, bulletsVector, pickups, nukes, SAVE_FILE);
            screen = game;
        }
            //exit game option exits game and closes window
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && exitButton.is_overlapping(x, y)) {
            glutDestroyWindow(wd);
            exit(0);
        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mainMenuButton.is_overlapping(x, y)){
            player.setPosition(width / 2, height / 2);
            player.setHealth(PLAYER_HEALTH);
            player.setScore(0);
            player.setSpecialAttacks(PLAYER_SPECIALS);
            player.setBoostBool(false);
            player.setBoostTime(0);
            player.setShotgunBool(false);
            player.setShotgunTime(0);

            enemies.clear();
            bulletsVector.clear();
            pickups.clear();
            nukes.clear();
            screen = start;
        }
    }

    /** Interactions on game screen **/
    if (screen == game) {
        // if the left mouse key is pressed, the player is shooting
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            shooting = true;
        }
        // if the left mouse key is released, the player has stopped shooting
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            shooting = false;
        }

        // if the right mouse key is pressed, a special attack occurs, shooting 16 shots around the player
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            if (player.getSpecialAttacks() > 0) {
                player.shoot(player.getX() + 5, player.getY() + 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 5, player.getY() - 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() + 5, player.getY() - 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 5, player.getY() + 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() + 5, player.getY(), bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 5, player.getY(), bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX(), player.getY() + 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX(), player.getY() - 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                             BULLET_RADIUS);

                player.shoot(player.getX() + 10, player.getY() + 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() + 5, player.getY() + 10, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 5, player.getY() + 10, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 10, player.getY() + 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);

                player.shoot(player.getX() - 10, player.getY() - 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() - 5, player.getY() - 10, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() + 5, player.getY() - 10, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);
                player.shoot(player.getX() + 10, player.getY() - 5, bulletsVector, BULLET_SPEED, BULLET_DAMAGE,
                             BULLET_COLOR,
                             BULLET_RADIUS);

                player.setSpecialAttacks(player.getSpecialAttacks() - 1);
            }
        }

        glutPostRedisplay();
    }
}

#endif //CIRCLE_MANIA_GRAPHICSINPUTS_H
