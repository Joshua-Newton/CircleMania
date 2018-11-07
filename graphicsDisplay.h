//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSDISPLAY_H
#define CIRCLE_MANIA_GRAPHICSDISPLAY_H

#include "graphicsConstants.h"
#include "graphics.h"

void displayTitle();

void displayControls();

void displayHUD();

// display settings screen
void displaySettings() {
    // Draw Buttons and text
    menuButtonsVector[8]->draw();

    string mainMenuMessage = "Main Menu";
    glColor3f(1, 1, 1);
    glRasterPos2i(mainMenuButton.get_x() + 25, mainMenuButton.get_y() + 45);
    for (int i = 0; i < mainMenuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mainMenuMessage[i]);
    }

    string number;
    string label;
    playerSizeDisplay.draw();

    number = to_string(PLAYER_RADIUS);
    glColor3f(0, 0, 0);
    glRasterPos2i(playerSizeDisplay.get_x() + 10, playerSizeDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Player Radius";
    glColor3f(1, 1, 1);
    glRasterPos2i(playerSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, playerSizeDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    slowSizeDisplay.draw();

    number = to_string(SLOW_RADIUS);
    glColor3f(0, 0, 0);
    glRasterPos2i(slowSizeDisplay.get_x() + 10, slowSizeDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Slow Enemy Radius";
    glColor3f(1, 1, 1);
    glRasterPos2i(slowSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, slowSizeDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    mediumSizeDisplay.draw();

    number = to_string(MEDIUM_RADIUS);
    glColor3f(0, 0, 0);
    glRasterPos2i(mediumSizeDisplay.get_x() + 10, mediumSizeDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Medium Enemy Radius";
    glColor3f(1, 1, 1);
    glRasterPos2i(mediumSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, mediumSizeDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    fastSizeDisplay.draw();

    number = to_string(FAST_RADIUS);
    glColor3f(0, 0, 0);
    glRasterPos2i(fastSizeDisplay.get_x() + 10, fastSizeDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Fast Enemy Radius";
    glColor3f(1, 1, 1);
    glRasterPos2i(fastSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, fastSizeDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    pickupSizeDisplay.draw();

    number = to_string(PICKUP_RADIUS);
    glColor3f(0, 0, 0);
    glRasterPos2i(pickupSizeDisplay.get_x() + 10, pickupSizeDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Pickup Radius";
    glColor3f(1, 1, 1);
    glRasterPos2i(pickupSizeDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, pickupSizeDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    playerSpeedDisplay.draw();

    number = to_string(PLAYER_SPEED);
    glColor3f(0, 0, 0);
    glRasterPos2i(playerSpeedDisplay.get_x() + 10, playerSpeedDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Player Speed";
    glColor3f(1, 1, 1);
    glRasterPos2i(playerSpeedDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, playerSpeedDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    slowSpeedDisplay.draw();

    number = to_string(SLOW_SPEED);
    glColor3f(0, 0, 0);
    glRasterPos2i(slowSpeedDisplay.get_x() + 10, slowSpeedDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Slow Enemy Speed";
    glColor3f(1, 1, 1);
    glRasterPos2i(slowSpeedDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, slowSpeedDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }
    /////////////////////////////
    mediumSpeedDisplay.draw();

    number = to_string(MEDIUM_SPEED);
    glColor3f(0, 0, 0);
    glRasterPos2i(mediumSpeedDisplay.get_x() + 10, mediumSpeedDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Medium Enemy Speed";
    glColor3f(1, 1, 1);
    glRasterPos2i(mediumSpeedDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, mediumSpeedDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    fastSpeedDisplay.draw();

    number = to_string(FAST_SPEED);
    glColor3f(0, 0, 0);
    glRasterPos2i(fastSpeedDisplay.get_x() + 10, fastSpeedDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Fast Enemy Speed";
    glColor3f(1, 1, 1);
    glRasterPos2i(fastSpeedDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, fastSpeedDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    bulletSpeedDisplay.draw();

    number = to_string(BULLET_SPEED);
    glColor3f(0, 0, 0);
    glRasterPos2i(bulletSpeedDisplay.get_x() + 10, bulletSpeedDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Bullet Speed";
    glColor3f(1, 1, 1);
    glRasterPos2i(bulletSpeedDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, bulletSpeedDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    playerHealthDisplay.draw();

    number = to_string(PLAYER_HEALTH);
    glColor3f(0, 0, 0);
    glRasterPos2i(playerHealthDisplay.get_x() + 10, playerHealthDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Player Initial Health";
    glColor3f(1, 1, 1);
    glRasterPos2i(playerHealthDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, playerHealthDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    slowHealthDisplay.draw();

    number = to_string(SLOW_HEALTH);
    glColor3f(0, 0, 0);
    glRasterPos2i(slowHealthDisplay.get_x() + 10, slowHealthDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Slow Enemy Health";
    glColor3f(1, 1, 1);
    glRasterPos2i(slowHealthDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, slowHealthDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    mediumHealthDisplay.draw();

    number = to_string(MEDIUM_HEALTH);
    glColor3f(0, 0, 0);
    glRasterPos2i(mediumHealthDisplay.get_x() + 10, mediumHealthDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Medium Enemy Health";
    glColor3f(1, 1, 1);
    glRasterPos2i(mediumHealthDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, mediumHealthDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    fastHealthDisplay.draw();

    number = to_string(FAST_HEALTH);
    glColor3f(0, 0, 0);
    glRasterPos2i(fastHealthDisplay.get_x() + 10, fastHealthDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Fast Enemy Health";
    glColor3f(1, 1, 1);
    glRasterPos2i(fastHealthDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, fastHealthDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    playerAmmoDisplay.draw();

    number = to_string(PLAYER_SPECIALS);
    glColor3f(0, 0, 0);
    glRasterPos2i(playerAmmoDisplay.get_x() + 10, playerAmmoDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Player Initial Ammo";
    glColor3f(1, 1, 1);
    glRasterPos2i(playerAmmoDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, playerAmmoDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    pickupDropRateDisplay.draw();

    number = to_string(DROP_RATE);
    glColor3f(0, 0, 0);
    glRasterPos2i(pickupDropRateDisplay.get_x() + 10, pickupDropRateDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Pickup Drop Rate";
    glColor3f(1, 1, 1);
    glRasterPos2i(pickupDropRateDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, pickupDropRateDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    spawnRateDisplay.draw();

    number = to_string(ENEMY_SPAWNRATE);
    glColor3f(0, 0, 0);
    glRasterPos2i(spawnRateDisplay.get_x() + 10, spawnRateDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Enemy Spawn Rate (Milliseconds)";
    glColor3f(1, 1, 1);
    glRasterPos2i(spawnRateDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, spawnRateDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    spawnRateSecondsDisplay.draw();

    number = to_string(ENEMY_SPAWNRATE/1000);
    glColor3f(0, 0, 0);
    glRasterPos2i(spawnRateSecondsDisplay.get_x() + 10, spawnRateSecondsDisplay.get_y() + 15);
    for (int i = 0; i < number.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
    label = "Enemy Spawn Rate (Seconds, Rounded Down)";
    glColor3f(1, 1, 1);
    glRasterPos2i(spawnRateSecondsDisplay.get_x() + SETTING_DISPLAY_WIDTH + SETTING_DISPLAY_LABEL_MARGIN, spawnRateSecondsDisplay.get_y() + 15);
    for (int i = 0; i < label.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label[i]);
    }

    //playerSizePlusTen.draw();

    for (int i = 0; i < settingsTriangles.size(); i++){

        settingsTriangles[i]->draw();           //TODO: Does not draw any triangles, why?
        //settingsTriangleUps[i]->draw();       //TODO: This line breaks the settings menu, exit code 11
        //settingsTriangleRights[i]->draw();    //TODO: This line breaks the settings menu, exit code 11
    }
    //playerSizePlusTen.draw();
    //playerSizePlusOne.draw();
}

// display pause screen
void displayPause() {
    // Draw buttons and text
    startBackground.draw();

    menuButtonsVector[2]->draw(); // resumeButton
    menuButtonsVector[6]->draw(); // restartGameButton
    menuButtonsVector[1]->draw(); // loadButton
    menuButtonsVector[3]->draw(); // saveButton
    menuButtonsVector[5]->draw(); // exitButtonPause
    displayTitle();
    displayControls();
    menuButtonsVector[8]->draw(); // mainMenuButton

    string mainMenuMessage = "Main Menu";
    glColor3f(1, 1, 1);
    glRasterPos2i(mainMenuButton.get_x() + 25, mainMenuButton.get_y() + 45);
    for (int i = 0; i < mainMenuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mainMenuMessage[i]);
    }

    string menuMessage = "PAUSED";
    glColor3f(1, 1, 1);
    glRasterPos2i(width - (width / 2) - 50, 150);
    for (int i = 0; i < menuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, menuMessage[i]);
    }

    // Draw Labels for buttons
    string resumeMessage = "Resume Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(resumeButton.get_x() + 25, resumeButton.get_y() + 45);
    for (int i = 0; i < resumeMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, resumeMessage[i]);
    }

    string restartMessage = "Restart Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(restartGameButton.get_x() + 25, restartGameButton.get_y() + 45);
    for (int i = 0; i < restartMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, restartMessage[i]);
    }

    string saveMessage = "Save Game";
    glRasterPos2i(saveButton.get_x() + 25, saveButton.get_y() + 45);
    for (int i = 0; i < saveMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, saveMessage[i]);
    }

    string loadMessage = "Load Game";
    glRasterPos2i(loadButton.get_x() + 25, loadButton.get_y() + 45);
    for (int i = 0; i < loadMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, loadMessage[i]);
    }

    string exitMessage = "Exit Game";
    glRasterPos2i(exitButtonPause.get_x() + 25, exitButtonPause.get_y() + 45);
    for (int i = 0; i < exitMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exitMessage[i]);
    }
}

// Display game over screen
void displayEnd() {
    // draw the buttons and text
    startBackground.draw();

    menuButtonsVector[0]->draw(); // startButton
    menuButtonsVector[1]->draw(); // loadButton
    menuButtonsVector[4]->draw(); // exitButton
    displayTitle();
    menuButtonsVector[8]->draw(); // mainMenuButton

    string mainMenuMessage = "Main Menu";
    glColor3f(1, 1, 1);
    glRasterPos2i(mainMenuButton.get_x() + 25, mainMenuButton.get_y() + 45);
    for (int i = 0; i < mainMenuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mainMenuMessage[i]);
    }

    string menuMessage = "GAME OVER";
    glColor3f(1, 1, 1);
    glRasterPos2i(BUTTON_X_POSITION + 25, 150);
    for (int i = 0; i < menuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, menuMessage[i]);
    }

    // Draw labels for buttons
    string resumeMessage = "New Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(startButton.get_x() + 25, startButton.get_y() + 45);
    for (int i = 0; i < resumeMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, resumeMessage[i]);
    }

    string loadMessage = "Load Game";
    glRasterPos2i(loadButton.get_x() + 25, loadButton.get_y() + 45);
    for (int i = 0; i < loadMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, loadMessage[i]);
    }

    string exitMessage = "Exit Game";
    glRasterPos2i(exitButton.get_x() + 25, exitButton.get_y() + 45);
    for (int i = 0; i < exitMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exitMessage[i]);
    }


}

// Draw the start menu
void displayStart() {

    // draw the buttons and text
    startBackground.draw();

    menuButtonsVector[0]->draw(); // startButton
    menuButtonsVector[1]->draw(); // loadButton
    menuButtonsVector[4]->draw(); // exitButton
    menuButtonsVector[7]->draw(); // settingsButton
    displayTitle();
    displayControls();

    string menuMessage = "MAIN MENU";
    glColor3f(1, 1, 1);
    glRasterPos2i(BUTTON_X_POSITION + 25, 150);
    for (int i = 0; i < menuMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, menuMessage[i]);
    }

    // Draw labels for buttons
    string startMessage = "New Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(startButton.get_x() + 25, startButton.get_y() + 45);
    for (int i = 0; i < startMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, startMessage[i]);
    }

    string loadMessage = "Load Game";
    glRasterPos2i(loadButton.get_x() + 25, loadButton.get_y() + 45);
    for (int i = 0; i < loadMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, loadMessage[i]);
    }

    string exitMessage = "Exit Game";
    glRasterPos2i(exitButton.get_x() + 25, exitButton.get_y() + 45);
    for (int i = 0; i < exitMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exitMessage[i]);
    }

    string settingsMessage = "Settings Menu";
    glRasterPos2i(settingsButton.get_x() + 25, settingsButton.get_y() + 45);
    for (int i = 0; i < settingsMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, settingsMessage[i]);
    }


}

// Draw the game
void displayGame() {



    // Drawing Order: Background, Nukes, Enemies, Bullets, player, pickups, HUD
    startBackground.draw();

//    hollow.draw();

    // for every nuke, draw it
    for (int circle = 0; circle < nukes.size(); circle++) {
        nukes[circle].draw();
    }

    // For every enemy in the enemies vector, draw the enemy
    for (int enemy = 0; enemy < enemies.size(); enemy++) {
        enemies[enemy]->draw();
    }

    // for every bullet in the bullet vector, draw the bullet
    for (Bullet b: bulletsVector) {
        b.draw();
    }

    // draw the player
    player.draw();

    // for every pickup, draw the pickup
    for (int pickup = 0; pickup < pickups.size(); pickup++) {
        pickups[pickup]->draw();
        string pickupString = pickups[pickup]->getString();
        glColor3f(1, 1, 1);
        glRasterPos2i(pickups[pickup]->getCircle().get_x() - pickups[pickup]->getCircle().get_radius(),
                      pickups[pickup]->getCircle().get_y());

        for (int i = 0; i < pickupString.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, pickupString[i]);
        }
    }


    // Check for player colliding with enemy
    for (int i = 0; i < enemies.size(); ++i) {
        if (player.getCircle().is_overlapping(enemies[i]->getCircle())) {
            enemies.erase(enemies.begin() + i);
            player.setHealth(player.getHealth() - 1);
            if (player.getHealth() <= 0) {
                screen = endGame;
            }
        }

    }

    // Check for player colliding with pickups
    for (int i = 0; i < pickups.size(); ++i) {
        if (player.getCircle().is_overlapping(pickups[i]->getCircle())) {

            pickups[i]->pickup(player);

            if (pickups[i]->getType() == NukeType) {
                HollowCircle nukeHollowCircle(NUKE_HOLLOW_CIRCLE);
                nukeHollowCircle.set_position(player.getX(), player.getY());
                nukes.push_back(nukeHollowCircle);
            }

            pickups.erase(pickups.begin() + i);
        }

    }

    // Check for all bullets colliding with any enemy
    for (int bullet = 0; bullet < bulletsVector.size(); ++bullet) {
        for (int enemy = 0; enemy < enemies.size(); ++enemy) {
            // If a bullet collides with any enemy, damage the enemy, delete the bullet, and set hit to true.
            if (bulletsVector[bullet].getCircle().is_overlapping(enemies[enemy]->getCircle())) {
                enemies[enemy]->setHealth(enemies[enemy]->getHealth() - bulletsVector[bullet].getDamage());
                bulletsVector.erase(bulletsVector.begin() + bullet);
                enemies[enemy]->setHit(true);
                // If this enemy's health is 0 or less, determine if a drop spawns, then delete the enemy
                if (enemies[enemy]->getHealth() <= 0) {
                    // Use random number to determine if a drop spawns
                    if ((rand() % 100) < DROP_RATE) {
                        // Use random number to determine which drop spawns
                        int dropNumber = rand() % NUMBER_PICKUPS_IMPLEMENTED;
                        switch (dropNumber) {
                            case 0:
                                pickups.push_back(make_unique<SpeedIncrease>(
                                        SpeedIncrease(SPEED_UP_CIRCLE, SPEED_STRING, PICKUP_LIFETIME, SPEED_BUFF,
                                                      SPEED_BUFF_TIME, enemies[enemy]->getX(),
                                                      enemies[enemy]->getY())));
                                break;
                            case 1:
                                pickups.push_back(make_unique<Shotgun>(
                                        Shotgun(SHOTGUN_CIRCLE, SHOTGUN_STRING, PICKUP_LIFETIME, SHOTGUN_TIME,
                                                enemies[enemy]->getX(), enemies[enemy]->getY())));
                                break;
                            case 2:
                                pickups.push_back(make_unique<Ammo>(
                                        Ammo(AMMO_CIRCLE, AMMO_STRING, PICKUP_LIFETIME, AMMO_REGAINED,
                                             enemies[enemy]->getX(), enemies[enemy]->getY())));
                                break;
                            case 3:
                                pickups.push_back(make_unique<Health>(
                                        Health(HEALTH_CIRCLE, HEALTH_STRING, PICKUP_LIFETIME, HEALTH_REGAINED,
                                               enemies[enemy]->getX(), enemies[enemy]->getY())));
                                break;
                            case 4:
                                pickups.push_back(make_unique<Nuke>(
                                        Nuke(NUKE_CIRCLE, NUKE_STRING, PICKUP_LIFETIME, enemies[enemy]->getX(),
                                             enemies[enemy]->getY())));
                                break;
                        }
                    }
                    player.setScore(player.getScore() + enemies[enemy]->getScore());
                    enemies.erase(enemies.begin() + enemy);

                }
                break;
            }

        }

        // If bullet is outside of the screen, delete it
        if (bulletsVector[bullet].getX() < 0 || bulletsVector[bullet].getX() > (int) width ||
            bulletsVector[bullet].getY() < 0 || bulletsVector[bullet].getY() > (int) height) {

            bulletsVector.erase(bulletsVector.begin() + bullet);
        }
    }

    // expand the radius of each "nuke"
    for (int circle = 0; circle < nukes.size(); circle++) {
        nukes[circle].setRadiusInner(nukes[circle].getRadiusInner() + NUKE_EXPANSION_RATE);
        nukes[circle].setRadiusOuter(nukes[circle].getRadiusOuter() + NUKE_EXPANSION_RATE);

        // Once each nuke is outside the screen, delete it

      //  if (!(nukes[circle].is_overlapping(startBackground))) { // This is the more proper way to do the if statement


        if (WIDTH > HEIGHT){
            if (nukes[circle].getRadiusInner() > WIDTH){
                nukes.erase(nukes.begin() + circle);
            }
        }
        else {
            if (nukes[circle].getRadiusInner() > HEIGHT){
                nukes.erase(nukes.begin() + circle);
            }
        }
    }

    // for every nuke, Check for overlap with enemies
    for (int nuke = 0; nuke < nukes.size(); ++nuke) {
        for (int enemy = 0; enemy < enemies.size(); ++enemy) {
            if (nukes[nuke].is_overlapping(enemies[enemy]->getCircle())){
                player.changeScore(enemies[enemy]->getScore());
                enemies.erase(enemies.begin() + enemy);
            }
        }
    }

    // for every enemy, do stuff
    for (int enemy = 0; enemy < enemies.size(); ++enemy){
        // update each enemies' hit circle position
        enemies[enemy]->getHitCircle().set_position(enemies[enemy]->getX(), enemies[enemy]->getY());
        // if the enemy was hit, draw its hit circle
        if (enemies[enemy]->getHit()){
            enemies[enemy]->drawHitCircle();
        }

    }

    // Print out Heads Up Display
    displayHUD();
}

// Function to show the title text
void displayTitle() {
    string titleMessage = "CIRCLE-MANIA";
    glColor3f(1, 1, 1);
    glRasterPos2i(BUTTON_X_POSITION + 25, 100);
    for (int i = 0; i < titleMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, titleMessage[i]);
    }
}

// Function to show the controls text
void displayControls() {
    string message = "After starting a game,";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 150);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    string healthMessage = "Avoid enemies,";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 125);
    for (int i = 0; i < healthMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, healthMessage[i]);
    }

    string shootMessage = "Use left click to shoot,";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 100);
    for (int i = 0; i < shootMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, shootMessage[i]);
    }

    string specialMessage = "Use right click for a special attack";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 75);
    for (int i = 0; i < specialMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, specialMessage[i]);
    }

    string movementMessage = "Use W - A - S - D to move,";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 50);
    for (int i = 0; i < movementMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, movementMessage[i]);
    }

    string pauseMessage = "Use space or 'p' to pause";
    glColor3f(1, 1, 1);
    glRasterPos2i(25, height - 25);
    for (int i = 0; i < pauseMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pauseMessage[i]);
    }

}

// Function to display Heads Up Display when playing the game
void displayHUD() {

    string specialsMessage = "Specials Remaining: " + to_string(player.getSpecialAttacks());
    glColor3f(1, 1, 1);
    glRasterPos2i(width - 240, 30);
    for (int i = 0; i < specialsMessage.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, specialsMessage[i]);
    }

    string scorePrint = "Score: " + to_string(player.getScore());
    glColor3f(1, 1, 1);
    glRasterPos2i(20, 30);
    for (int i = 0; i < scorePrint.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorePrint[i]);
    }

    if (player.getBoostBool()) {
        string boostPrint = "Boost Time: " + to_string(player.getBoostTime());
        glColor3f(1, 1, 1);
        glRasterPos2i(20, 50);
        for (int i = 0; i < boostPrint.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, boostPrint[i]);
        }
    }

    if (player.getShotgunBool()) {
        string shotgunPrint = "Shotgun Time: " + to_string(player.getShotgunTime());
        glColor3f(1, 1, 1);
        glRasterPos2i(20, 70);
        for (int i = 0; i < shotgunPrint.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, shotgunPrint[i]);
        }
    }

    string healthPrint = "Health: " + to_string(player.getHealth());
    glColor3f(1, 1, 1);
    glRasterPos2i(20, height - 20);
    for (int i = 0; i < healthPrint.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, healthPrint[i]);
    }

};

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
// primary display method
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    // Display the screen that "screen" is set to
    switch (screen) {
        case start:
            displayStart();
            break;
        case game:
            displayGame();
            break;
        case endGame:
            displayEnd();
            break;
        case pauseGame:
            displayPause();
            break;
        case settings:
            displaySettings();
            break;

    }

    glFlush();  // Render now
}


#endif //CIRCLE_MANIA_GRAPHICSDISPLAY_H
