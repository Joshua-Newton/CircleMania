//
// Created by Margaret on 11/14/2017.
//
#include "Enemy.h"
/*
 * Default constructor
 */
Enemy::Enemy() {
    setHealth(10);
    setSpeed(10);
    setScore(5);
    circle = (Circle(5, {0,1,0}));
}


/*
 * Requires: health, speed, score, circle
 * Modifies: health, speed, score, circle
 * Effects: Creates an enemy with the given field values
 */
Enemy::Enemy(int hlth, int spd, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
}

Enemy::Enemy(int hlth, int spd, int scr, Circle cir, HollowCircle hitCir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
    setHitCircle(hitCir);
    setHit(false);
}


Enemy::Enemy(int hlth, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(getSpeedConstant());
    setScore(scr);
    setCircle(cir);
}


/*
 * Destructor
 */
Enemy::~Enemy(){
}

void Enemy::draw(){
    circle.draw();
}
void Enemy::drawHitCircle() {
    hitCircle.draw();
}


/*
 * Getters
 */
int Enemy::getHealth() const{
    return health;
}

int Enemy::getSpeed() const{
    return speed;
}

int Enemy::getScore() const{
    return score;
}

Circle& Enemy::getCircle(){
    return circle;
}
int Enemy::getSpeedConstant() const{
    return SPEED_CONSTANT;
}
int Enemy::getX() const{
    return circle.get_x();
}
int Enemy::getY() const{
    return circle.get_y();
}
double Enemy::getRed() const{
    return circle.get_fill().red;
}
double Enemy::getGreen() const{
    return circle.get_fill().green;
}
double Enemy::getBlue() const{
    return circle.get_fill().blue;
}
color Enemy::getFill() const{
    return circle.get_fill();
}
int Enemy::getRadius() const{
    return circle.get_radius();
}
bool Enemy::getHit() const{
    return hit;
}
HollowCircle& Enemy::getHitCircle() {
    return hitCircle;
}
/*
 * Setters
 */
void Enemy::setHealth(int hlth){
    health = hlth;
}

void Enemy::setSpeed(int spd){
    speed = spd;
}

void Enemy::setScore(int scr){
    score = scr;
}

void Enemy::setCircle(Circle cir){
    circle = cir;
}

void Enemy::setPosition(int x, int y){
    circle.set_position(x,y);
}
void Enemy::setHit(bool newHitTruth){
    hit = newHitTruth;
}
void Enemy::setHitCircle(HollowCircle newHitCircle) {
    hitCircle = newHitCircle;
}


/*
 * Overwritten in child class
 * Requires: nothing
 * Modifies: reduces player's health, and totalScore
 * Effects: reduces player's health/score
 */
void Enemy::hitPlayer() {
    cout << "Player was hit" << endl;
    //Reduce player's health
    //Reduce player's score
    //Reset player's position away from enemy so it doesn't get continuously hit
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/*
 * Default constructor
 */
Slow::Slow() {
    setHealth(10);
    setSpeed(10);
    setScore(5);
    setCircle(Circle(5, {0,1,0}));
}


/*
 * Requires: health, speed, score, circle
 * Modifies: health, speed, score, circle
 * Effects: Creates an enemy with the given field values
 */
Slow::Slow(int hlth, int spd, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
}


Slow::Slow(int hlth, int spd, int scr, Circle cir, HollowCircle hitCir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
    setHitCircle(hitCir);
    setHit(false);
}


Slow::Slow(int hlth, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(getSpeedConstant());
    setScore(scr);
    setCircle(cir);
}


/*
 * Destructor
 */

/*
 * Overwrites parent class
 * Requires: integer x and y values
 * Modifies: point
 * Effects: Moves the enemy x spots in the x-plain and y spots in the y-plain
 */
void Slow::move(int x, int y)  {
    circle.move(x, y);
}




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/*
 * Default constructor
 */
Medium::Medium() {
    setHealth(10);
    setSpeed(10);
    setScore(5);
    setCircle(Circle(5, {0,1,0}));
}


/*
 * Requires: health, speed, score, circle
 * Modifies: health, speed, score, circle
 * Effects: Creates an enemy with the given field values
 */
Medium::Medium(int hlth, int spd, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
}

Medium::Medium(int hlth, int spd, int scr, Circle cir, HollowCircle hitCir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
    setHitCircle(hitCir);
    setHit(false);
}

Medium::Medium(int hlth, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(getSpeedConstant());
    setScore(scr);
    setCircle(cir);
}
/*
 * Overwrites parent class
 * Requires: integer x and y values
 * Modifies: point
 * Effects: Moves the enemy x spots in the x-plain and y spots in the y-plain
 */
void Medium::move(int x, int y) {
    circle.move(x, y);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/*
 * Default constructor
 */
Fast::Fast() {
    setHealth(10);
    setSpeed(10);
    setScore(5);
    setCircle(Circle(5, {0,1,0}));
}


/*
 * Requires: health, speed, score, circle
 * Modifies: health, speed, score, circle
 * Effects: Creates an enemy with the given field values
 */
Fast::Fast(int hlth, int spd, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
}

Fast::Fast(int hlth, int spd, int scr, Circle cir, HollowCircle hitCir){
    setHealth(hlth);
    setSpeed(spd);
    setScore(scr);
    setCircle(cir);
    setHitCircle(hitCir);
    setHit(false);
}

Fast::Fast(int hlth, int scr, Circle cir){
    setHealth(hlth);
    setSpeed(getSpeedConstant());
    setScore(scr);
    setCircle(cir);
}

/*
 * Overwrites parent class
 * Requires: integer x and y values
 * Modifies: point
 * Effects: Moves the enemy x spots in the x-plain and y spots in the y-plain
 */
void Fast::move(int x, int y) {
    circle.move(x, y);
}

