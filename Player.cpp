//
// Created by Joshua Newton on 11/14/17.
//

#include "Player.h"
#include <vector>
using namespace std;

Player::Player(){
    health = 10;
    speed = 10;
    totalScore = 0;
    Circle cir(30, {1,0,0});
    cir.set_position(400,400);
    circle = cir;
    shotgun = false;
    boost = false;
    shotgunTime = 0;
    boostTime = 0;
}

Player::Player (int hp, int spd, Circle cir){
    health = hp;
    speed = spd;
    totalScore = 0;
    circle = cir;
    specialAttacks = 10;
    shotgun = false;
    boost = false;
    shotgunTime = 0;
    boostTime = 0;
}

Player::Player (int hp, int spd, int specials, Circle cir){
    health = hp;
    speed = spd;
    totalScore = 0;
    circle = cir;
    specialAttacks = specials;
    shotgun = false;
    boost = false;
    shotgunTime = 0;
    boostTime = 0;
}

Player::~Player(){
    // does nothing special, just destructs the player
}
void Player::move(int x, int y){
    // If we use the circle class from in-class code, this will call move on the circle, and player will not have a position
    circle.move(x,y);
}

void Player::shoot(int targetX, int targetY, vector<Bullet> &b, int bulletSpeed, int bulletDamage, color bulletColor, int bulletRadius){
    // Create the circle for the bullet
    Circle bulletCircle(bulletRadius, bulletColor);

    // Create bullet and set its targets
    Bullet bullet(bulletCircle, bulletSpeed, bulletDamage, circle.get_x(), circle.get_y());
    bullet.setTargetX(targetX);
    bullet.setTargetY(targetY);

    // Calculate increments by obtaining a unit vector and multiplying each of its components by
    // the bullet's speed
    double differenceX = bullet.getTargetX() - bullet.getX();
    double differenceY = bullet.getTargetY() - bullet.getY();
    double hypotenuse = sqrt( ( differenceX * differenceX ) + ( differenceY * differenceY ) );
    differenceX /= hypotenuse;
    differenceY /= hypotenuse;
    int incrementX = int(differenceX * bullet.getSpeed());
    int incrementY = int(differenceY * bullet.getSpeed());

    bullet.setIncrementX(incrementX);
    bullet.setIncrementY(incrementY);

    b.push_back(bullet);
}

void Player::changeScore(int scoreChange){
    totalScore += scoreChange;
}

void Player::draw(){
    circle.draw();
}


/**
 * Getters
 */
/*
Shield Player::getShield() const{
    return shield;
}
 */
int Player::getHealth() const{
    return health;
}
int Player::getSpeed() const{
    return speed;
}
int Player::getScore() const{
    return totalScore;
}
Circle& Player::getCircle(){
    return circle;
}
int Player::getX() const{
    return circle.get_x();
}
int Player::getY() const{
    return circle.get_y();
}
double Player::getRed() const{
    return circle.get_fill().red;
}
double Player::getGreen() const{
    return circle.get_fill().green;
}
double Player::getBlue() const{
    return circle.get_fill().blue;
}
color Player::getFill() const{
    return circle.get_fill();
}
int Player::getRadius() const{
    return circle.get_radius();
}
int Player::getSpecialAttacks() const{
    return specialAttacks;
}
int Player::getShotgunTime() const{
    return shotgunTime;
}
int Player::getBoostTime() const{
    return boostTime;
}
bool Player::getShotgunBool() const{
    return shotgun;
}
bool Player::getBoostBool() const{
    return boost;
}

/**
 * Setters
 */
/*
void Player::setShield(Shield newShield){
    shield = newShield;
}
 */
void Player::setHealth(int newHealth){
    health = newHealth;
}
void Player::setSpeed(int newSpeed){
    speed = newSpeed;
}
void Player::setScore(int newScore){
    totalScore = newScore;
}
void Player::setCircle(Circle newCircle){
    circle = newCircle;
}

void Player::setPosition(int x, int y){
    circle.set_position(x,y);
}

void Player::setFill(int r, int g, int b){
    circle.set_fill(r, g, b);
}
void Player::setSpecialAttacks(int newNumber) {
    specialAttacks = newNumber;
}
void Player::setShotgunTime(int newTime){
    shotgunTime = newTime;
}
void Player::setBoostTime(int newTime){
    boostTime = newTime;
}
void Player::setShotgunBool(bool newTruth){
    shotgun = newTruth;
}
void Player::setBoostBool(bool newTruth){
    boost = newTruth;
}
void Player::setRadius(int newRadius){
    circle.set_radius(newRadius);
}

