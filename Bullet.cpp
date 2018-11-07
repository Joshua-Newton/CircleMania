//
// Created by Gavin Gunkle on 11/16/17.
//

#include "Bullet.h"

/*
 * Constructors
 */
Bullet::Bullet(){
    speed = 2;
    damage = 10;
    Circle cir(40, {0,0,1});
    cir.set_position(600,600);
    circle = cir;
    targetX = 0;
    targetY = 0;
}
Bullet::Bullet(Circle cir, int spd, int dmg){
    speed = spd;
    damage = dmg;
    circle = cir;
}

Bullet::Bullet(int spd, int dmg, int xIncrement, int yIncrement, Circle cir) : Bullet(cir, spd, dmg) {
    setIncrementX(xIncrement);
    setIncrementY(yIncrement);
}

Bullet::Bullet(Circle cir, int spd, int dmg, int xPosition, int yPosition){
    speed = spd;
    damage = dmg;
    cir.set_position(xPosition, yPosition);
    circle = cir;
}

Bullet::Bullet(int xPosition, int yPosition){
    speed = 2;
    damage = 10;
    Circle cir = Circle(20, {1,0,1});
    cir.set_position(xPosition, yPosition);
    circle = cir;
}

Bullet::Bullet(Circle cir, int spd, int dmg, int xPosition, int yPosition, int xIncrement, int yIncrement): Bullet( cir, spd, dmg, xPosition, yPosition){
    setIncrementX(xIncrement);
    setIncrementY(yIncrement);
}


/*
 * Destructor
 */
Bullet::~Bullet(){
}

/*
 * Getters
 */

int Bullet::getTargetX() const{
    return targetX;
}

int Bullet::getTargetY() const{
    return targetY;
}


int Bullet::getSpeed() const{
    return speed;
}
int Bullet::getDamage() const{
    return damage;
}
Circle Bullet::getCircle() const {
    return circle;
}

int Bullet::getX() const{
    return circle.get_x();
}

int Bullet::getY() const{
    return circle.get_y();
}
double Bullet::getRed() const{
    return circle.get_fill().red;
}
double Bullet::getGreen() const{
    return circle.get_fill().green;
}
double Bullet::getBlue() const{
    return circle.get_fill().blue;
}
color Bullet::getFill() const{
    return circle.get_fill();
}
int Bullet::getRadius() const{
    return circle.get_radius();
}

int Bullet::getIncrementX() const {
    return incrementX;
}
int Bullet::getIncrementY() const {
    return incrementY;
}

/*
 * Setters
 */
void Bullet::setTargetX(int x){
    targetX = x;
}
void Bullet::setTargetY(int y){
    targetY = y;
}


void Bullet::setSpeed(int spd){
    speed = spd;
}
void Bullet::setDamage(int dmg){
    damage = dmg;
}
void Bullet::setCircle(Circle newCircle) {
    circle = newCircle;
}

void Bullet::move(int x, int y){
    circle.move(x, y);
}

void Bullet::hitEnemy(Enemy &e){
    e.setHealth(e.getHealth() - damage);
    if(e.getHealth() <= 0){
        e.~Enemy(); //destroys enemy object if health is 0 or below
        //~Bullet(); //destroys bullet object
    }
    else{
        //~Bullet();
    }
}

void Bullet::outOfBounds(){
    cout << "Bullet out of bounds" << endl;
    //unsure what to add here before we begin graphics
}

void Bullet::draw(){
    circle.draw();
}

void Bullet::setPosition(int x, int y){
    circle.set_position(x,y);
}

void Bullet::setIncrementX(int increment) {
    incrementX = increment;
}
void Bullet::setIncrementY(int increment)  {
    incrementY = increment;
}

void Bullet::setFill(int r, int g, int b) {
    circle.set_fill(r, g, b);
}
