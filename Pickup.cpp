//
// Created by Joshua Newton on 1/18/18.
//

#include "Pickup.h"

// TODO: Bullet Speed Pickup
// TODO: Penetration Pickup

/******************* Abstract Pickup Class *******************/
// constructors

Pickup::Pickup() {
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setType(AmmoType);
}

Pickup::Pickup(Circle circle, string pickupString, int pickupLifeTime) {
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setType(AmmoType);
}

// Getters
Circle Pickup::getCircle() const{
    return circle;
}

string Pickup::getString() const{
    return pickupString;
}

int Pickup::getLifeTime() const{
    return lifeTime;
}

color Pickup::getColor() const{
    return circle.get_fill();
}
int Pickup::getRed() const{
    return circle.get_fill().red;
}
int Pickup::getGreen() const{
    return circle.get_fill().green;
}
int Pickup::getBlue() const{
    return circle.get_fill().blue;
}
int Pickup::getRadius() const{
    return circle.get_radius();
}
point Pickup::getPosition() const{
    return circle.get_position();
}
int Pickup::getX() const{
    return circle.get_x();
}
int Pickup::getY() const{
    return circle.get_y();
}
pickupType Pickup::getType() const{
    return type;
}
string Pickup::getTypeString() const{
    switch (type){
        case SpeedType:
            return "SpeedType";
        case AmmoType:
            return "AmmoType";
        case HealthType:
            return "HealthType";
        case ShotgunType:
            return "ShotgunType";
        case NukeType:
            return "NukeType";
    }
}

// Setters
void Pickup::setCircle(Circle newCircle) {
    circle = newCircle;
}

void Pickup::setString(string newString) {
    pickupString = newString;
}

void Pickup::setLifeTime(int time) {
    lifeTime = time;
}

void Pickup::setPosition(int x, int y){
    circle.set_position(x,y);
}
void Pickup::setType(pickupType newType){
    type = newType;
}

// Methods
// (Two abstract methods overwritten in children)
void Pickup::draw(){
    circle.draw();
}

/******************* End of Abstract Class *******************/

/******************* Child Class (Speed Up) *******************/

// Constructors

SpeedIncrease::SpeedIncrease() {
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setSpeedBuff(2);
    setType(SpeedType);
}

SpeedIncrease::SpeedIncrease(Circle circle, string pickupString, int pickupLifeTime, int speedBuff, int newLifetime, int posX, int posY) {
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setSpeedBuff(speedBuff);
    setSpeedTime(newLifetime);
    setPosition(posX,posY);
    setType(SpeedType);
}

// Getters
int SpeedIncrease::getSpeedBuff() const{
    return speedBuff;
}
int SpeedIncrease::getSpeedTime() const{
    return speedTime;
}


// Setters
void SpeedIncrease::setSpeedBuff(int newSpeedBuff) {
    speedBuff = newSpeedBuff;
}
void SpeedIncrease::setSpeedTime(int newLifeTime){
    speedTime = newLifeTime;
}

// Methods
void SpeedIncrease::pickup(Player &player) {
    // If the player, already has a boost, just reset time. This prevents speed boosts from stacking too much
    if (player.getBoostBool()){
        player.setBoostTime(speedTime);
    }
    else {
        player.setBoostBool(true);
        player.setBoostTime(speedTime);
        player.setSpeed(player.getSpeed() + speedBuff);
    }

}

void SpeedIncrease::save(ofstream &outs){
    outs << this->getType() << endl
         << this->getLifeTime() << endl
         << this->getString() << endl
         << this->getRadius() << endl
         << this->getRed() << endl
         << this->getGreen() << endl
         << this->getBlue() << endl
         << this->getX() << endl
         << this->getY() << endl
         << this->getSpeedBuff() << endl
         << this->getSpeedTime() << endl;
}

/******************* End of Child Class (Speed Up) *******************/

/******************* Child Class (Ammo) *******************/

// Constructors

Ammo::Ammo() {
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setAmmoRegained(2);
    setType(AmmoType);
}

Ammo::Ammo(Circle circle, string pickupString, int pickupLifeTime, int ammo, int posX, int posY) {
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setAmmoRegained(ammo);
    setPosition(posX,posY);
    setType(AmmoType);
}

// Getters
int Ammo::getAmmoRegained() const{
    return ammoRegained;
}

// Setters
void Ammo::setAmmoRegained(int newAmmoRegained) {
    ammoRegained = newAmmoRegained;
}

// Methods
void Ammo::pickup(Player &player) {
    player.setSpecialAttacks(player.getSpecialAttacks() + ammoRegained);
}

void Ammo::save(ofstream &outs){
    outs << this->getType() << endl
         << this->getLifeTime() << endl
         << this->getString() << endl
         << this->getRadius() << endl
         << this->getRed() << endl
         << this->getGreen() << endl
         << this->getBlue() << endl
         << this->getX() << endl
         << this->getY() << endl
         << this->getAmmoRegained() << endl;
}
/******************* End of Child Class (Ammo) *******************/

/******************* Child Class (Health) *******************/

// Constructors

Health::Health() {
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setHealthRegained(1);
    setType(HealthType);
}

Health::Health(Circle circle, string pickupString, int pickupLifeTime, int health, int posX, int posY) {
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setHealthRegained(health);
    setPosition(posX,posY);
    setType(HealthType);
}

// Getters
int Health::getHealthRegained() const{
    return healthRegained;
}

// Setters
void Health::setHealthRegained(int newHealthRegained) {
    healthRegained = newHealthRegained;
}

// Methods
void Health::pickup(Player &player) {
    player.setHealth(player.getHealth() + healthRegained);
}

void Health::save(ofstream &outs){
    outs << this->getType() << endl
         << this->getLifeTime() << endl
         << this->getString() << endl
         << this->getRadius() << endl
         << this->getRed() << endl
         << this->getGreen() << endl
         << this->getBlue() << endl
         << this->getX() << endl
         << this->getY() << endl
         << this->getHealthRegained() << endl;
}

/******************* End of Child Class (Health) *******************/

/******************* Child Class (Shotgun) *******************/


Shotgun::Shotgun() {
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setTimeLength(2);
    setType(ShotgunType);
}

/**
 *  Constructor that fill all the Pickup's fields
 *  R: Circle object, string, integer
 *  M: circle, pickupString, healthRegained
 *  E: Creates a Health Pickup with the given circle, string, and health integer
 */
Shotgun::Shotgun(Circle circle, string pickupString, int pickupLifeTime, int timeLength, int posX, int posY) {
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setTimeLength(timeLength);
    setPosition(posX,posY);
    setType(ShotgunType);
}

// Getters
int Shotgun::getTimeLength() const{
    return time;
}

// Setters
void Shotgun::setTimeLength(int newTimeLength) {
    time = newTimeLength;
}

// Methods
void Shotgun::pickup(Player &player) {
    if (player.getShotgunBool()){
        player.setShotgunTime(time);
    }
    else {
        player.setShotgunBool(true);
        player.setShotgunTime(time);
    }

}

void Shotgun::save(ofstream &outs){
    outs << this->getType() << endl
         << this->getLifeTime() << endl
         << this->getString() << endl
         << this->getRadius() << endl
         << this->getRed() << endl
         << this->getGreen() << endl
         << this->getBlue() << endl
         << this->getX() << endl
         << this->getY() << endl
         << this->getTimeLength() << endl;
}

/******************* End of Child Class (Shotgun) *******************/

/******************* Child Class (Nuke) *******************/

Nuke::Nuke(){
    setCircle(Circle(3, {0, 0, 0}));
    setString("Pickup");
    setLifeTime(60);
    setType(NukeType);
}
Nuke::Nuke(Circle circle, string pickupString, int pickupLifeTime){
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setType(NukeType);
}
Nuke::Nuke(Circle circle, string pickupString, int pickupLifeTime, int x, int y){
    setCircle(circle);
    setString(pickupString);
    setLifeTime(pickupLifeTime);
    setType(NukeType);
    setPosition(x,y);
}

// Overridden methods
void Nuke::pickup(Player &player) {
    // This pickup does nothing to the player, and therefore this method will do nothing.
}
void Nuke::save(ofstream &outs) {
    // TODO: complete the save function here
}

/******************* End of Child Class (Nuke) *******************/
