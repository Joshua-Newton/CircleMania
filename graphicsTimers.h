//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSTIMERS_H
#define CIRCLE_MANIA_GRAPHICSTIMERS_H

#include "graphicsConstants.h"
#include "Enemy.h"
//#include "graphicsPlay.h"

// Timer to take care of movement
void timer(int extra) {

    if(screen == game) {
        // Loop through bullets vector, make them move
        for (int i = 0; i < bulletsVector.size(); ++i) {
            bulletsVector[i].move(bulletsVector[i].getIncrementX(), bulletsVector[i].getIncrementY());
        }

        // loop through enemies vector to determine increments of movement for ALL enemies

        for (int i = 0; i < enemies.size(); ++i) {
            // Determine how far to move the enemy in x and y directions
            double differenceX = player.getX() - enemies[i]->getX();
            double differenceY = player.getY() - enemies[i]->getY();
            double hypotenuse = sqrt((differenceX * differenceX) + (differenceY * differenceY));
            differenceX /= hypotenuse;
            differenceY /= hypotenuse;
            int incrementX = int(differenceX * enemies[i]->getSpeed());
            int incrementY = int(differenceY * enemies[i]->getSpeed());

            // Move the enemy
            enemies[i]->move(incrementX, incrementY);
        }

        // TODO: Adjust movement with the XOR operator (^) to make it so that player does not move faster when
        // TODO: holding two keys (moving diagonally)
        // Move the player according to booleans
        if ( moveDown && ( (height - player.getY() ) >= ( player.getSpeed() + player.getRadius() ) ) ){
            player.move(0, player.getSpeed());
        }
        if ( moveUp && ( player.getY() >= ( player.getSpeed() + player.getRadius() ) ) ){
            player.move(0, -player.getSpeed());
        }
        if ( moveLeft && ( player.getX() >= ( player.getSpeed() + player.getRadius() ) ) ){
            player.move(-player.getSpeed(), 0);
        }
        if ( moveRight && ( ( width - player.getX() ) >= ( player.getSpeed() + player.getRadius() ) ) ){
            player.move(player.getSpeed(), 0);
        }



    }



    glutPostRedisplay();
    glutTimerFunc(0, timer, 0);
}

// Timer to make the enemies spawn
void enemySpawnTimer(int extra) {

    if(screen == game) {
        // Randomize a number 0-2 to determine which enemy to spawn
        int enemyNumber = rand() % 3;
        // determines side of screen (clockwise 0 is top)
        int side = rand() % 4;

        Circle enemyCircle;
        int distance;
        int position;

        // Based on random number, spawn a slow, medium, or fast enemy
        switch (enemyNumber) {
            case 0:
                distance = rand() % 50 + SLOW_RADIUS;

                if (side == 0) {
                    position = rand() % (int) width;
                    enemyCircle = SLOW_CIRCLE;
                    enemyCircle.set_position(position, -distance);
                } else if (side == 1) {
                    position = rand() % (int) height;
                    enemyCircle = SLOW_CIRCLE;
                    enemyCircle.set_position((int) width + distance, position);
                } else if (side == 2) {
                    position = rand() % (int) width;
                    enemyCircle = SLOW_CIRCLE;
                    enemyCircle.set_position(position, (int) height + distance);
                } else if (side == 3) {
                    position = rand() % (int) height;
                    enemyCircle = SLOW_CIRCLE;
                    enemyCircle.set_position(-distance, position);
                }
                enemies.push_back(make_unique<Slow>(Slow(SLOW_HEALTH, SLOW_SPEED, SLOW_SCORE, enemyCircle, SLOW_HIT_CIRCLE)));

                break;
            case 1:
                distance = rand() % 50 + MEDIUM_RADIUS;
                if (side == 0) {
                    position = rand() % (int) width;
                    enemyCircle = MEDIUM_CIRCLE;
                    enemyCircle.set_position(position, -distance);
                } else if (side == 1) {
                    position = rand() % (int) height;
                    enemyCircle = MEDIUM_CIRCLE;
                    enemyCircle.set_position((int) width + distance, position);
                } else if (side == 2) {
                    position = rand() % (int) width;
                    enemyCircle = MEDIUM_CIRCLE;
                    enemyCircle.set_position(position, (int) height + distance);
                } else if (side == 3) {
                    position = rand() % (int) height;
                    enemyCircle = MEDIUM_CIRCLE;
                    enemyCircle.set_position(-distance, position);
                }
                enemies.push_back(make_unique<Medium>(Medium(MEDIUM_HEALTH, MEDIUM_SPEED, MEDIUM_SCORE, enemyCircle, MEDIUM_HIT_CIRCLE)));
                break;
            case 2:
                distance = rand() % 50 + FAST_RADIUS;
                if (side == 0) {
                    position = rand() % (int) width;
                    enemyCircle = FAST_CIRCLE;
                    enemyCircle.set_position(position, -distance);
                } else if (side == 1) {
                    position = rand() % (int) height;
                    enemyCircle = FAST_CIRCLE;
                    enemyCircle.set_position((int) width + distance, position);
                } else if (side == 2) {
                    position = rand() % (int) width;
                    enemyCircle = FAST_CIRCLE;
                    enemyCircle.set_position(position, (int) height + distance);
                } else if (side == 3) {
                    position = rand() % (int) height;
                    enemyCircle = FAST_CIRCLE;
                    enemyCircle.set_position(-distance, position);
                }
                enemies.push_back(make_unique<Fast>(Fast(FAST_HEALTH, FAST_SPEED, FAST_SCORE, enemyCircle, FAST_HIT_CIRCLE)));
                break;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(ENEMY_SPAWNRATE, enemySpawnTimer, 0);


}

// Timer that triggers every second, handles time based events that occur every second
void pickupHandlerTimer(int extra){

    if (screen == game) {
        // Reduce the life time of every pickup by 1 second
        for (int i = 0; i < pickups.size(); i++) {
            pickups[i]->setLifeTime(pickups[i]->getLifeTime() - 1);
            // If the pickup life time is at 0, delete it
            if (pickups[i]->getLifeTime() <= 0){
                pickups.erase(pickups.begin() + i);
                //i--
            }
        }

        // If the player has a shotgun, reduce the remaining time by 1 second
        if (player.getShotgunBool()) {
            player.setShotgunTime(player.getShotgunTime() - 1);
            // If the player is out of shotgun time, remove the shotgun
            if (player.getShotgunTime() <= 0) {
                player.setShotgunBool(false);
            }

        }

        // If the player has a speed boost, reduce the remaining time by 1 second
        if (player.getBoostBool()) {
            player.setBoostTime(player.getBoostTime() - 1);
            // If the player is out of boost time, remove the boost and reduce their speed to normal
            if (player.getBoostTime() <= 0) {
                player.setBoostBool(false);
                player.setSpeed(player.getSpeed() - SPEED_BUFF);
            }
        }

    }

    glutPostRedisplay();
    // This timer should occur every second (1000 milliseconds)
    glutTimerFunc(1000, pickupHandlerTimer, 0);
}

void fireRateTimer(int extra){

    if (shooting){
        player.shoot(MOUSE_X, MOUSE_Y, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
    }

    if (shooting && player.getShotgunBool()){
        // Treat player as origin
        // Targeting 1st and third quadrant
        if ( ( (MOUSE_X - player.getX() > 0) && (MOUSE_Y - player.getY() < 0) ) || ( (MOUSE_X - player.getX() < 0) && (MOUSE_Y - player.getY() > 0) ) ) {
            player.shoot(MOUSE_X + 50, MOUSE_Y + 50, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                         BULLET_RADIUS);
            player.shoot(MOUSE_X, MOUSE_Y, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
            player.shoot(MOUSE_X - 50, MOUSE_Y - 50, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                         BULLET_RADIUS);
        }
        // Targeting any other quadrant
        else {
            player.shoot(MOUSE_X + 50, MOUSE_Y - 50, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                         BULLET_RADIUS);
            player.shoot(MOUSE_X, MOUSE_Y, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR, BULLET_RADIUS);
            player.shoot(MOUSE_X - 50, MOUSE_Y + 50, bulletsVector, BULLET_SPEED, BULLET_DAMAGE, BULLET_COLOR,
                         BULLET_RADIUS);
        }
    }

    glutPostRedisplay();
    // This timer should occur every FIRE_RATE milliseconds
    glutTimerFunc(FIRE_RATE, fireRateTimer, 0);
}


#endif //CIRCLE_MANIA_GRAPHICSTIMERS_H
