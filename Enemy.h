//
// Created by Margaret Caron on 11/13/17.
//

#ifndef CIRCLE_MANIA_ENEMY_H
#define CIRCLE_MANIA_ENEMY_H

#include "Shapes.h"

class Enemy {
protected:
    //The enemy's health
    int health;
    //The enemy's speed
    int speed;
    //The score that the player earns for killing this type of enemy
    int score;
    //The enemy's circle (shape)
    Circle circle;
    //The enemy's default speed
    int SPEED_CONSTANT;
    //Boolean that shows if the enemy was recently hit
    bool hit;
    //The hollow circle that will be drawn if the enemy is hit
    HollowCircle hitCircle;
public:
    /*
     * Default constructor
     */
    Enemy();

    /*
     * Requires: health, speed, score, circle
     * Modifies: health, speed, score, circle
     * Effects: Creates an enemy with the given field values
     */
    Enemy(int hlth, int spd, int scr, Circle cir);

    /**
     * R: health, score, circle
     * M: health, score, circle, speed
     * E: Creates an enemy with given parameters and default speed.
     */
    Enemy(int hlth, int scr, Circle cir);

    /*
     * Destructor
     */
    ~Enemy();

    void draw();
    void drawHitCircle();

    /*
     * Getters
     */
    int getHealth() const;
    int getSpeed() const;
    int getScore() const;
    Circle &getCircle();
    int getSpeedConstant() const;
    int getX() const;
    int getY() const;
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;
    int getRadius() const;
    bool getHit() const;
    HollowCircle getHitCircle() const;

    /*
     * Setters
     */
    void setHealth(int h);
    void setSpeed(int sp);
    void setScore(int sc);
    void setCircle(Circle cir);
    void setPosition(int x, int y);
    void setHit(bool newHitTruth);
    void setHitCircle(HollowCircle newHitCircle);

    /*
     * Overwritten in child class
     * Requires: integer x and y values
     * Modifies: point
     * Effects: Moves the enemy to the given position
     */
    virtual void move(int x, int y) = 0;


    /*
     * Overwritten in child class
     * Requires: nothing
     * Modifies: reduces player's health, and totalScore
     * Effects: reduces player's health/score
     */
    void hitPlayer();


};

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// Child class
class Slow : public Enemy {
public:
    /*
     * Default constructor
     */
    Slow();

    /*
     * Requires: health, speed, score, Circle
     * Modifies: health, speed, score, Circle
     * Effects: Creates an enemy with the given field values
     */
    Slow(int hlth, int spd, int scr, Circle cir);


    Slow(int hlth, int scr, Circle cir);

    /*
     * Overwrites parent class
     * Requires: integer x and y values
     * Modifies: point
     * Effects: Moves the enemy to the given position
     */
    virtual void move(int x, int y) override;

private:
    int SPEED_CONSTANT = 1;
};

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// Child class
class Medium : public Enemy {
public:
    /*
     * Default constructor
     */
    Medium();

    /*
     * Requires: health, speed, score, circle
     * Modifies: health, speed, score, circle
     * Effects: Creates an enemy with the given field values
     */
    Medium(int hlth, int spd, int scr, Circle cir);

    /*
     * Requires: health, score, circle
     * Modifies: health, speed, score, circle
     * Effects: Creates an enemy with the given field values and default speed
     */
    Medium(int hlth, int scr, Circle cir);

    /*
     * Overwrites parent class
     * Requires: integer x and y values
     * Modifies: point
     * Effects: Moves the enemy to the given position
     */
    void move(int x, int y) override;

private:
    int SPEED_CONSTANT = 2;
};

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// Child class
class Fast : public Enemy {
public:
    /*
     * Default constructor
     */
    Fast();

    /*
     * Requires: health, speed, score, circle
     * Modifies: health, speed, score, circle
     * Effects: Creates an enemy with the given field values
     */
    Fast(int hlth, int spd, int scr, Circle cir);

    /*
     * Requires: health, score, circle
     * Modifies: health, speed, score, circle
     * Effects: Creates an enemy with the given field values and default speed
     */
    Fast(int hlth, int scr, Circle cir);

    /*
     * Overwrites parent class
     * Requires: integer x and y values
     * Modifies: point
     * Effects: Moves the enemy to the given position
     */
    void move(int x, int y) override;


private:
    int SPEED_CONSTANT = 3;
};


#endif //CIRCLE_MANIA_ENEMY_H
