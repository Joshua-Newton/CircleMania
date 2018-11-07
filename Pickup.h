//
// Created by Joshua Newton on 1/18/18.
//

#ifndef CIRCLE_MANIA_PICKUP_H
#define CIRCLE_MANIA_PICKUP_H

#include "Shapes.h"
#include "Player.h"
#include <fstream>

// Enum to hold the type of pickup
enum pickupType{SpeedType, AmmoType, HealthType, ShotgunType, NukeType};
/******************* Abstract Pickup Class *******************/

class Pickup{
protected:
    // The pickup's circle
    Circle circle;
    // The pickup's string
    string pickupString;
    // The pickup's lifetime
    int lifeTime;
    // The pickup's type
    pickupType type;
public:
    // constructors

    /**
     * Default Constructor
     */
    Pickup();

    /**
     * Constructor that fills the Pickup's fields
     * R: A circle object, a String, an integer
     * M: circle, pickupString, lifeTime
     * E: Creates a new Pickup with the given circle and string
     */
    Pickup(Circle circle, string pickupString, int pickupLifeTime);
    Pickup(const Pickup &pickup);

    // Getters
    Circle getCircle() const;
    string getString() const;
    int getLifeTime() const;
    color getColor() const;
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    int getRadius() const;
    point getPosition() const;
    int getX() const;
    int getY() const;
    pickupType getType() const;
    string getTypeString() const;

    // Setters
    void setCircle(Circle newCircle);
    void setString(string newString);
    void setLifeTime(int time);
    void setPosition(int x, int y);
    void setType(pickupType newType);

    // Methods
    virtual void pickup(Player &player) = 0;
    virtual void save(ofstream &outs) = 0;
    void draw();


};

/******************* End of Abstract Class *******************/

/******************* Child Class (Speed Up) *******************/

class SpeedIncrease : public Pickup{
protected:
    // The amount that the player's speed will be increased
    int speedBuff;
    //
    int speedTime;
public:
    // Constructors

    /**
     * Default Constructor
     */
    SpeedIncrease();

    /**
     *  Constructor that fills all the Pickup's fields
     *  R: Circle object, string, 2 integers
     *  M: circle, pickupString, lifeTime, speedBuff
     *  E: Creates a SpeedIncrease Pickup witht eh given circle, string, and speedBuff integer
     */
    SpeedIncrease(Circle circle, string pickupString, int pickupLifeTime, int speedBuff, int newLifetime, int posX, int posY);
    SpeedIncrease(const SpeedIncrease &speed);
    // Getters
    int getSpeedBuff() const;
    int getSpeedTime() const;

    // Setters
    void setSpeedBuff(int newSpeedBuff);
    void setSpeedTime(int newLifetime);

    // Methods
    void pickup(Player &player) override;

    void save(ofstream &outs) override;
};

/******************* End of Child Class (Speed Up) *******************/

/******************* Child Class (Ammo) *******************/

class Ammo : public Pickup{
protected:
    // The amount that the player's speed will be increased
    int ammoRegained;
public:
    // Constructors

    /**
     * Default Constructor
     */
    Ammo();

    /**
     *  Constructor that fills all the Pickup's fields
     *  R: Circle object, string, integer
     *  M: circle, pickupString, lifeTime, ammoRegained
     *  E: Creates a Ammo Pickup with the given circle, string, and ammo integer
     */
    Ammo(Circle circle, string pickupString, int pickupLifeTime, int ammo, int posX, int posY);
    Ammo(const Ammo &ammo);
    // Getters
    int getAmmoRegained() const;

    // Setters
    void setAmmoRegained(int newAmmoRegained);

    // Methods
    void pickup(Player &player) override;

    void save(ofstream &outs) override;

};

/******************* End of Child Class (Ammo) *******************/

/******************* Child Class (Health) *******************/

class Health : public Pickup{
protected:
    // The amount that the player's speed will be increased
    int healthRegained;
public:
    // Constructors

    /**
     * Default Constructor
     */
    Health();

    /**
     *  Constructor that fills all the Pickup's fields
     *  R: Circle object, string, 2 integers
     *  M: circle, pickupString, lifeTime, healthRegained
     *  E: Creates a Health Pickup with the given circle, string, and health integer
     */
    Health(Circle circle, string pickupString, int pickupLifeTime, int health, int posX, int posY);
    Health(const Health &health);
    // Getters
    int getHealthRegained() const;

    // Setters
    void setHealthRegained(int newHealthRegained);

    // Methods
    void pickup(Player &player) override;

    void save(ofstream &outs) override;

};

/******************* End of Child Class (Health) *******************/

/******************* Child Class (Shotgun) *******************/

class Shotgun: public Pickup{
protected:
    // The time that the shotgun will last
    int time;
public:

    Shotgun();
    /**
     *  Constructor that fill all the Pickup's fields
     *  R: Circle object, string, 2 integers
     *  M: circle, pickupString, lifeTime, healthRegained
     *  E: Creates a Health Pickup with the given circle, string, and health integer
     */
    Shotgun(Circle circle, string pickupString, int pickupLifeTime, int timeLength, int posX, int posY);
    Shotgun(const Shotgun &shotgun);
    // Getters
    int getTimeLength() const;

    // Setters
    void setTimeLength(int newTimeLength);

    // Methods
    void pickup(Player &player) override;

    void save(ofstream &outs) override;

};

/******************* End of Child Class (Shotgun) *******************/

/******************* Child Class (Nuke) *****************************/

class Nuke: public Pickup{
public:
    // Constructors
    Nuke();
    Nuke(Circle circle, string pickupString, int pickupLifeTime);
    Nuke(Circle circle, string pickupString, int pickupLifeTime, int x, int y);
    Nuke(const Nuke &nuke);
    // Overridden methods
    void pickup(Player &player) override;
    void save(ofstream &outs) override;

};

/******************* End of Child Class (Nuke) **********************/

/** TO DO:
 *  Bullet Speed Pickup ????????
 *  Penetration Pickup ??????
 */

#endif //CIRCLE_MANIA_PICKUP_H
