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
        // Pause the game = P or space
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
    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {

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

void drag(int x,int y){
    if (screen == game){
        MOUSE_X = x;
        MOUSE_Y = y;
    }
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (screen == start) {
        //if start game button (rectangle) is clicked, start the game


        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && startButton.is_overlapping(x, y)) {
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
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && exitButton.is_overlapping(x, y)) {
            glutDestroyWindow(wd);
            exit(0);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && settingsButton.is_overlapping(x, y)) {
            screen = settings;
        }
    }


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
    }

    if (screen == settings){
         if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mainMenuButton.is_overlapping(x, y)) {
             screen = start;
         }

        //TODO: FILE I/O FOR CUSTOM DIFFICULTY


    }

    if (screen == endGame) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && startButton.is_overlapping(x, y)) {
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
    }

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
