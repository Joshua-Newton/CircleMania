//
// Created by Joshua Newton on 2/21/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSSAVINGLOADING_H
#define CIRCLE_MANIA_GRAPHICSSAVINGLOADING_H

#include "enemy.h"
#include "player.h"
#include "pickup.h"
#include <iostream>
#include <vector>
#include <fstream>

void saving(const Player &players, const vector<unique_ptr<Enemy>> &enemies, const vector<Bullet> &bullets,
            const vector<unique_ptr<Pickup>> &pickups, string fileName) {

    // Saving

    ofstream gameObjects(fileName); // Open file

    if (gameObjects) {
        // Save the current Settings
        gameObjects << PLAYER_RADIUS << endl
                    << SLOW_RADIUS << endl
                    << MEDIUM_RADIUS << endl
                    << PICKUP_RADIUS << endl
                    << PLAYER_SPEED << endl
                    << SLOW_SPEED << endl
                    << MEDIUM_SPEED << endl
                    << FAST_SPEED << endl
                    << BULLET_SPEED << endl
                    << PLAYER_HEALTH << endl
                    << SLOW_HEALTH << endl
                    << MEDIUM_HEALTH << endl
                    << FAST_HEALTH << endl
                    << PLAYER_SPECIALS << endl
                    << DROP_RATE << endl
                    << ENEMY_SPAWNRATE << endl;

        // Save the numbers for each type of entity
        gameObjects << enemies.size() << endl;
        gameObjects << bullets.size() << endl;
        gameObjects << pickups.size() << endl;

        // Save the player's stats
        gameObjects << players.getHealth() << endl
                    << players.getSpeed() << endl
                    << players.getRadius() << endl
                    << players.getRed() << endl
                    << players.getGreen() << endl
                    << players.getBlue() << endl
                    << players.getX() << endl
                    << players.getY() << endl
                    << players.getScore() << endl
                    << players.getSpecialAttacks() << endl;
        if (players.getShotgunBool()) {
            gameObjects << 1 << endl;
        } else {
            gameObjects << 0 << endl;
        }
        gameObjects << players.getShotgunTime() << endl;
        if (players.getBoostBool()) {
            gameObjects << 1 << endl;
        } else {
            gameObjects << 0 << endl;
        }
        gameObjects << players.getBoostTime() << endl;

        // for every enemy, save their stats
        for (int i = 0; i < enemies.size(); ++i) {
            gameObjects << enemies[i]->getHealth() << endl
                        << enemies[i]->getSpeed() << endl
                        << enemies[i]->getScore() << endl
                        << enemies[i]->getRadius() << endl
                        << enemies[i]->getRed() << endl
                        << enemies[i]->getGreen() << endl
                        << enemies[i]->getBlue() << endl
                        << enemies[i]->getX() << endl
                        << enemies[i]->getY() << endl;
        }

        // for every bullet, save their stats
        for (Bullet b: bullets) {
            gameObjects << b.getRadius() << endl
                        << b.getRed() << endl
                        << b.getGreen() << endl
                        << b.getBlue() << endl
                        << b.getX() << endl
                        << b.getY() << endl
                        << b.getSpeed() << endl
                        << b.getDamage() << endl
                        << b.getIncrementX() << endl
                        << b.getIncrementY() << endl;

        }
        // for every pickup, save their stats
        for (int i = 0; i < pickups.size(); ++i) {
            pickups[i]->save(gameObjects);
        }

    }

    gameObjects.close();
}

void loading(Player &players, vector<unique_ptr<Enemy>> &enemies, vector<Bullet> &bullets,
             vector<unique_ptr<Pickup>> &pickups, string fileName) {

    ifstream gameObjects(fileName); // Open file

    // load the custom settings
    gameObjects >> PLAYER_RADIUS
                >> SLOW_RADIUS
                >> MEDIUM_RADIUS
                >> PICKUP_RADIUS
                >> PLAYER_SPEED
                >> SLOW_SPEED
                >> MEDIUM_SPEED
                >> FAST_SPEED
                >> BULLET_SPEED
                >> PLAYER_HEALTH
                >> SLOW_HEALTH
                >> MEDIUM_HEALTH
                >> FAST_HEALTH
                >> PLAYER_SPECIALS
                >> DROP_RATE
                >> ENEMY_SPAWNRATE;

    int numEnemies;
    int numBullets;
    int numPickups;
    // Load the sizes of vectors
    gameObjects >> numEnemies >> numBullets >> numPickups;
    // Load the player
    // for the player.....
    int health;
    int speed;
    double radius;
    double r, g, b;
    int x, y;
    int score;
    int specials;
    int shotgun, boost;
    int shotgunTime, boostTime;

    gameObjects >> health >> speed >> radius >> r >> g >> b >> x >> y >> score >> specials >> shotgun >> shotgunTime
                >> boost >> boostTime;
    Circle circle = Circle(radius, {r, g, b});
    player = Player(health, speed, specials, circle);
    player.setPosition(x, y);
    player.setScore(score);
    if (shotgun == 0) {
        player.setShotgunBool(false);
        player.setShotgunTime(0);
    } else {
        player.setShotgunBool(true);
        player.setShotgunTime(shotgunTime);
    }

    if (boost == 0) {
        player.setBoostBool(false);
        player.setBoostTime(0);
    } else {
        player.setBoostBool(true);
        player.setBoostTime(boostTime);
    }

    // Load the enemies
    // for every enemy.....
    for (int i = 0; i < numEnemies; i++) {
        int health;
        int speed;
        int score;
        double radius;
        double r, g, b;
        int x, y;

        gameObjects >> health >> speed >> score >> radius >> r >> g >> b >> x >> y;
        Circle circle = Circle(radius, {r, g, b});
        circle.set_position(x, y);

        if (speed == SLOW_SPEED) {
            enemies.push_back(make_unique<Slow>(Slow(health, speed, score, circle, SLOW_HIT_CIRCLE)));
        } else if (speed == MEDIUM_SPEED) {
            enemies.push_back(make_unique<Medium>(Medium(health, speed, score, circle, MEDIUM_HIT_CIRCLE)));
        } else if (speed == FAST_SPEED) {
            enemies.push_back(make_unique<Fast>(Fast(health, speed, score, circle, FAST_HIT_CIRCLE)));
        }
    }
    // Load the bullets
    for (int i = 0; i < numBullets; i++) {
        int speed;
        int damage;
        double radius;
        double r, g, b;
        int x, y, xInc, yInc;
        gameObjects >> radius >> r >> g >> b >> x >> y >> speed >> damage >> xInc >> yInc;
        Circle circle = Circle(radius, {r, g, b});
        circle.set_position(x, y);
        bullets.push_back(Bullet(speed, damage, xInc, yInc, circle));
    }

    // Load the pickups
    for (int i = 0; i < numPickups; i++) {
        string type, pickupString;
        int lifetime, radius;
        int speedBuff, speedBuffTime;
        int ammoRegained;
        int healthRegained;
        int shotgunTime;
        double r, g, b;
        int x, y;

        gameObjects >> type;
        if (type == "AmmoType") {
            gameObjects >> lifetime >> pickupString >> radius >> r >> g >> b >> x >> y >> ammoRegained;
            pickups.push_back(
                    make_unique<Ammo>(Ammo((Circle(radius, {r, g, b})), pickupString, lifetime, ammoRegained, x, y)));
        } else if (type == "HealthType") {
            gameObjects >> lifetime >> pickupString >> radius >> r >> g >> b >> x >> y >> healthRegained;
            pickups.push_back(make_unique<Health>(
                    Health((Circle(radius, {r, g, b})), pickupString, lifetime, healthRegained, x, y)));
        } else if (type == "SpeedType") {
            gameObjects >> lifetime >> pickupString >> radius >> r >> g >> b >> x >> y >> speedBuff >> speedBuffTime;
            pickups.push_back(make_unique<SpeedIncrease>(
                    SpeedIncrease((Circle(radius, {r, g, b})), pickupString, lifetime, speedBuff, speedBuffTime, x,
                                  y)));
        } else if (type == "ShotgunType") {
            gameObjects >> lifetime >> pickupString >> radius >> r >> g >> b >> x >> y >> shotgunTime;
            pickups.push_back(
                    make_unique<Shotgun>(Shotgun((Circle(radius, {r, g, b})), pickupString, lifetime, shotgunTime, x, y)));
        } else if (type == "NukeType") {
            gameObjects >> lifetime >> pickupString >> radius >> r >> g >> b >> x >> y;
            pickups.push_back(make_unique<Nuke>(Nuke((Circle(radius, {r,g,b})), pickupString, lifetime, x, y)));
        }

    }

    gameObjects.close();
}


#endif //CIRCLE_MANIA_GRAPHICSSAVINGLOADING_H
