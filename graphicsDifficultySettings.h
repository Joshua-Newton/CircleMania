//
// Created by Joshua Newton on 11/7/18.
//

#ifndef CIRCLE_MANIA_GRAPHICSDIFFICULTYSETTINGS_H
#define CIRCLE_MANIA_GRAPHICSDIFFICULTYSETTINGS_H

#include "graphicsConstants.h"

void saveDefaultSettings(){
    //TODO: fill out this function to be used at program execution
    //TODO: (this will make sure the default settings are consistent)
    // Open file
    ofstream settingsFile(DEFAULT_SETTINGS_FILE);

    if (settingsFile){
        settingsFile << PLAYER_RADIUS << endl
                     << SLOW_RADIUS << endl
                     << MEDIUM_RADIUS << endl
                     << FAST_RADIUS << endl
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
    }
    settingsFile.close();

}

void loadSettings(string fileName){
    // Open file
    ifstream settingsFile(fileName);
    int playerRadius, slowRadius, mediumRadius, fastRadius, pickupRadius, playerSpeed, slowSpeed, mediumSpeed,
            fastSpeed, bulletSpeed, playerHealth, slowHealth, mediumHealth, fastHealth, playerInitialAmmo,
            pickupDropRate, enemySpawnRate;

    settingsFile >> playerRadius >> slowRadius >> mediumRadius >> fastRadius >> pickupRadius >> playerSpeed >> slowSpeed
                 >> mediumSpeed >> fastSpeed >> bulletSpeed >> playerHealth >> slowHealth >> mediumHealth >> fastHealth
                 >> playerInitialAmmo >> pickupDropRate >> enemySpawnRate;

    // Apply settings to proper variables
    PLAYER_RADIUS = playerRadius;
    SLOW_RADIUS = slowRadius;
    MEDIUM_RADIUS = mediumRadius;
    FAST_RADIUS = fastRadius;
    PICKUP_RADIUS = pickupRadius;
    PLAYER_SPEED = playerSpeed;
    SLOW_SPEED = slowSpeed;
    MEDIUM_SPEED = mediumSpeed;
    FAST_SPEED = fastSpeed;
    BULLET_SPEED = bulletSpeed;
    PLAYER_HEALTH = playerHealth;
    SLOW_HEALTH = slowHealth;
    MEDIUM_HEALTH = mediumHealth;
    FAST_HEALTH = fastHealth;
    PLAYER_SPECIALS = playerInitialAmmo;
    DROP_RATE = pickupDropRate;
    ENEMY_SPAWNRATE = enemySpawnRate;

    // Update necessary values associated with the above settings
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

    settingsFile.close();
}

#endif //CIRCLE_MANIA_GRAPHICSDIFFICULTYSETTINGS_H
