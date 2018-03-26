//
// Created by Joshua Newton on 11/13/17.
//

#ifndef CIRCLE_MANIA_PLAYER_H
#define CIRCLE_MANIA_PLAYER_H

#include "Shapes.h"
#include "Bullet.h"
#include <vector>

class Player{
private:
    /*
     // the shield that the player has, should start as null
     Shield shield;
    */
    // the player's remaining health
    int health;
    // the speed that the player moves with
    int speed;
    // the total score that the player has accumulated, should start as 0
    int totalScore;
    // the player's current position will be held in the circle
    // the circle that will represent the player in graphics
    Circle circle;
    // the number of special attacks remaining
    int specialAttacks;
    // Boolean to keep track of whether the player has a speed boost
    bool boost;
    // Boolean to keep track of whether the player has a shotgun
    bool shotgun;
    // int showing time left on boost
    int boostTime;
    // int showing time left on shotgun
    int shotgunTime;

public:
    /**
     * Default constructor
     * R: nothing
     * M: shield, health, speed, totalScore, circle, specialAttacks
     * E: creates a player with default values, should use in combination with setters
     */
    Player();

    /**
     * R: health, speed, and circle variables
     * M: shield, health, speed, totalScore, circle, specialAttacks
     * E: Creates an instance of the player, initializing all of its variables
     */
    Player (int hp, int spd, Circle cir);

    /**
     * R: health, speed, specials, and circle variables
     * M: shield, health, speed, totalScore, circle, specialAttacks
     * E: Creates an instance of the player, initializing all of its variables
     */
    Player (int hp, int spd, int specials, Circle cir);

    // Destructor
    ~Player();

    /**
     * R: x and y variables
     * M: position
     * E: Makes the player move the given amount in the x and y direction
     */
    void move(int x, int y);

    /**
     * R: Two integers for the targes
     * M: Bullet's target variables.
     * E: The player shoots a bullet in the direction of the mouse location. This will create a bullet at the position
     *    of the player and send it towards the mouses position at the time of firing.
     */
    void shoot(int targetX, int targetY, vector<Bullet> &b, int bulletSpeed, int bulletDamage, color bulletColore, int bulletRadius);

    /**
     * R: an int that represents the amount that the score will change by
     * M: score
     * E: Changes the score that the player has by the given number. The number CAN be negative. This would mean the
     *    score would decrease instead of increase.
     */
    void changeScore(int scoreChange);

    void draw();

    /**
     * Getters
     */
    int getHealth() const;
    int getSpeed() const;
    int getScore() const;
    Circle& getCircle();
    int getX() const;
    int getY() const;
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;
    int getRadius() const;
    int getSpecialAttacks() const;
    int getShotgunTime() const;
    int getBoostTime() const;
    bool getShotgunBool() const;
    bool getBoostBool() const;

    /**
     * Setters
     */
    //void setShield(Shield newShield);
    void setHealth(int newHealth);
    void setSpeed(int newSpeed);
    void setScore(int newScore);
    void setCircle(Circle newCircle);
    void setPosition(int x, int y);
    void setFill(int r, int g, int b);
    void setSpecialAttacks(int newNumber);
    void setShotgunTime(int newTime);
    void setBoostTime(int newTime);
    void setShotgunBool(bool newTruth);
    void setBoostBool(bool newTruth);
    void setRadius(int newRadius);


};


#endif //CIRCLE_MANIA_PLAYER_H
