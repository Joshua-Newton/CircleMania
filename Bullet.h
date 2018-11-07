//
// Created by Gavin Gunkle on 11/16/17.
//

#ifndef CIRCLE_MANIA_BULLET_H
#define CIRCLE_MANIA_BULLET_H


#include "Shapes.h"
#include "Enemy.h"

//shape class edition?

class Bullet{
public:
    /*
     * Constructors
     * Variables: speed (spd) and damage (dmg), object circle (cir)
     * Requires: nothing, or
     * Modifies: nothing
     * Effects: creates bullet objects
     */
    Bullet();
    Bullet(Circle cir, int spd, int dmg);
    Bullet(int spd, int dmg, int xIncrement, int yIncrement, Circle cir);
    Bullet(Circle cir, int spd, int dmg, int xPosition, int yPosition);
    Bullet(int xPosition, int yPosition);
    Bullet(Circle cir, int spd, int dmg, int xPosition, int yPosition, int xIncrement, int yIncrement);

    /*
     * Destructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: deletes bullet object
     */
    ~Bullet();

    /*
     * Getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns speed or damage value
     */
    int getTargetX() const;
    int getTargetY() const;
    int getSpeed() const;
    int getDamage() const;
    Circle getCircle() const;
    int getX() const;
    int getY() const;
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;
    int getRadius() const;
    int getIncrementX() const;
    int getIncrementY() const;
    /*
     * Setters
     * Requires: integer input
     * Modifies: speed or damage
     * Effects: sets the speed or damage value or circle object
     */
    void setTargetX(int x);
    void setTargetY(int y);
    void setSpeed(int spd);
    void setDamage(int dmg);
    void setCircle(Circle newCircle);
    void setPosition(int x, int y);
    void setIncrementX(int increment);
    void setIncrementY(int increment);
    void setFill(int r, int g, int b);

    /*
     * Requires: two integer inputs
     * Modifies: position of bullet
     * Effects: moves the bullet
     */
    void move(int x, int y);

    /*
     * Requires: bullet, enemy objects
     * Modifies: nothing
     * Effects: destructs enemy, bullet and gives points
     */
    void hitEnemy(Enemy &e);

    /*
     * Requires: bullet object, window size
     * Modifies: nothing
     * Effects: destructs bullet object
     */
    void outOfBounds();

    void draw();

private:
    int speed;
    int damage;
    Circle circle;
    int targetX;
    int targetY;
    int incrementX;
    int incrementY;
};


/*
 * Shield class is additional portion of project
 * not necessary, leaving in case there is time at the end to add


class Shield{
public:

    Shield();
    Shield(int hlth);

    ~Shield();



private:
    int health;

};
*/


#endif //CIRCLE_MANIA_BULLET_H
