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
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    switch (key) {
        // Pause the game = 'P' , 'p', or space
        case (32):
            if (screen == game) {
                screen = pauseGame;
            }
            else if (screen == pauseGame){
                screen = game;
            }
            break;
        case (80):
            if (screen == game) {
                screen = pauseGame;
            }
            else if (screen == pauseGame){
                screen = game;
            }
            break;
        case (112):
            if (screen == game) {
                screen = pauseGame;
            }
            else if (screen == pauseGame){
                screen = game;
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
                break;
            case GLUT_KEY_RIGHT :
                if (playerSizeDisplay.is_overlapping(x,y)){
                    if (PLAYER_RADIUS <= PLAYER_RADIUS_MAX) {
                        PLAYER_RADIUS++;
                    }
                }
                if (slowSizeDisplay.is_overlapping(x,y)){
                    if (SLOW_RADIUS <= SLOW_RADIUS_MAX) {
                        SLOW_RADIUS++;
                    }
                }
                if (mediumSizeDisplay.is_overlapping(x,y)){
                    if (MEDIUM_RADIUS <= MEDIUM_RADIUS_MAX) {
                        MEDIUM_RADIUS++;
                    }
                }
                if (fastSizeDisplay.is_overlapping(x,y)){
                    if (FAST_RADIUS <= FAST_RADIUS_MAX) {
                        FAST_RADIUS++;
                    }
                }
                if (pickupSizeDisplay.is_overlapping(x,y)){
                    if (PICKUP_RADIUS <= PICKUP_RADIUS_MAX) {
                        PICKUP_RADIUS++;
                    }
                }
                if (playerSpeedDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPEED <= SPEED_MAX) {
                        PLAYER_SPEED++;
                    }
                }
                if (slowSpeedDisplay.is_overlapping(x,y)){
                    if (SLOW_SPEED <= SPEED_MAX) {
                        SLOW_SPEED++;
                    }
                }
                if (mediumSpeedDisplay.is_overlapping(x,y)){
                    if (MEDIUM_SPEED <= SPEED_MAX) {
                        MEDIUM_SPEED++;
                    }
                }
                if (fastSpeedDisplay.is_overlapping(x,y)){
                    if (FAST_SPEED <= SPEED_MAX) {
                        FAST_SPEED++;
                    }
                }
                if (bulletSpeedDisplay.is_overlapping(x,y)){
                    if (BULLET_SPEED <= SPEED_MAX) {
                        BULLET_SPEED++;
                    }
                }
                if (playerHealthDisplay.is_overlapping(x,y)){
                    if (PLAYER_HEALTH <= HEALTH_MAX) {
                        PLAYER_HEALTH++;
                    }
                }
                if (slowHealthDisplay.is_overlapping(x,y)){
                    if (SLOW_HEALTH <= HEALTH_MAX) {
                        SLOW_HEALTH++;
                    }
                }
                if (mediumHealthDisplay.is_overlapping(x,y)){
                    if (MEDIUM_HEALTH <= HEALTH_MAX) {
                        MEDIUM_HEALTH++;
                    }
                }
                if (fastHealthDisplay.is_overlapping(x,y)){
                    if (FAST_HEALTH <= HEALTH_MAX) {
                        FAST_HEALTH++;
                    }
                }
                if (playerAmmoDisplay.is_overlapping(x,y)){
                    if (PLAYER_SPECIALS <= AMMO_MAX) {
                        PLAYER_SPECIALS++;
                    }
                }
                if (pickupDropRateDisplay.is_overlapping(x,y)){
                    if (DROP_RATE <= DROP_RATE_MAX) {
                        DROP_RATE++;
                    }
                }
                if (spawnRateDisplay.is_overlapping(x,y)){
                    if (ENEMY_SPAWNRATE <= SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE++;
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
                    if (ENEMY_SPAWNRATE < SPAWN_RATE_MAX) {
                        ENEMY_SPAWNRATE = SPAWN_RATE_MAX;
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
        // start button hover
        if (startButton.is_overlapping(x, y)){
            startButton.set_fill(HOVER_COLOR);
        }
        else {
            startButton.set_fill(START_BUTTON_COLOR);
        }

        // load button hover
        if (loadButton.is_overlapping(x, y)) {
            loadButton.set_fill(HOVER_COLOR);
        }
        else {
            loadButton.set_fill(LOAD_BUTTON_COLOR);
        }

        // save button hover
        if (saveButton.is_overlapping(x, y)) {
            saveButton.set_fill(HOVER_COLOR);
        }
        else {
            saveButton.set_fill(SAVE_BUTTON_COLOR);
        }

        // resume button hover
        if (resumeButton.is_overlapping(x, y)) {
            resumeButton.set_fill(HOVER_COLOR);
        }
        else {
            resumeButton.set_fill(RESUME_BUTTON_COLOR);
        }

        // restart button hover
        if (restartGameButton.is_overlapping(x, y)) {
            restartGameButton.set_fill(HOVER_COLOR);
        }
        else {
            restartGameButton.set_fill(RESTART_GAME_BUTTON_COLOR);
        }

        // exit button hover
        if (exitButton.is_overlapping(x, y)) {
            exitButton.set_fill(HOVER_COLOR);
        }
        else {
            exitButton.set_fill(EXIT_BUTTON_COLOR);
        }

        // exit pause button hover
        if (exitButtonPause.is_overlapping(x, y)) {
            exitButtonPause.set_fill(HOVER_COLOR);
        }
        else {
            exitButtonPause.set_fill(EXIT_BUTTON_COLOR);
        }

        // Settings button hover
        if (settingsButton.is_overlapping(x, y)) {
            settingsButton.set_fill(HOVER_COLOR);
        }
        else {
            settingsButton.set_fill(EXIT_BUTTON_COLOR);
        }

        // Main Menu button hover
        if (mainMenuButton.is_overlapping(x, y)) {
            mainMenuButton.set_fill(HOVER_COLOR);
        }
        else {
            mainMenuButton.set_fill(EXIT_BUTTON_COLOR);
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
                loading(player, enemies, bulletsVector, pickups, SAVE_FILE);
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
            saving(player, enemies, bulletsVector, pickups, SAVE_FILE);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && loadButton.is_overlapping(x, y)) {
            enemies.clear();
            bulletsVector.clear();
            loading(player, enemies, bulletsVector, pickups, SAVE_FILE);
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
    if (screen == settings){
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
            loading(player, enemies, bulletsVector, pickups, SAVE_FILE);
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
