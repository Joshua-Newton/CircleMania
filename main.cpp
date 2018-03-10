//
// Created by Gavin Gunkle on 11/13/17.
//
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Shapes.h"
#include "graphics.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

void gameDescription();
/*
void saving (const vector<Player> &players, const vector<unique_ptr<Enemy>> &enemies, const vector<Bullet> &bullets, string fileName);
void loading (vector<Player> &players, vector<unique_ptr<Enemy>> &enemies, vector<Bullet> &bullets, string fileName);
*/

int main(int argc, char** argv){

    graphicsPlay(argc, argv);
// BELOW IS TESTING, UNCOMMENT BLOCK COMMENT TO TEST
/**
    gameDescription();


    // Make vectors for saving and loading
    vector<Player> players;
    vector<unique_ptr<Enemy>> enemies;
    vector<Bullet> bullets;

    //Create the player
    Player player(10, 2, Circle(3));
    player.setPosition(200,150);
    player.setFill(0,1,0);

    void setSpeed(int newSpeed);
    void setScore(int newScore);
    void setCircle(Circle newCircle);

    // Create the Enemies
    Slow slowEnemy(5, 1, 1, Circle(5, {1,0,0}));
    slowEnemy.setPosition(50,50);
    Medium mediumEnemy(3, 2, 2, Circle(5, {0,1,0}));
    mediumEnemy.setPosition(100,100);
    Fast fastEnemy(1, 3, 3, Circle(5, {0,0,1}));
    fastEnemy.setPosition(50,100);

    // Create a bullet
    Bullet bullet1 = Bullet(Circle(1, {1,1,0}), 10, 1, 20, 20);

    // tests the shoot method to spawn a bullet
    Bullet bullet2 = player.shoot();

    // Put all of the objects in their vectors
    players.push_back(player);
    enemies.push_back(make_unique<Slow>(slowEnemy));
    enemies.push_back(make_unique<Medium>(mediumEnemy));
    enemies.push_back(make_unique<Fast>(fastEnemy));
    bullets.push_back(bullet1);
    bullets.push_back(bullet2);


    // Test saving
    saving(players, enemies, bullets, "SavedFile.txt");

    // Test loading
    vector<Player> players2;
    vector<unique_ptr<Enemy>> enemies2;
    vector<Bullet> bullets2;

    loading(players2, enemies2, bullets2, "SavedFile.txt");

    // Save the loaded vectors, if the two files match then loading works
    saving(players2, enemies2, bullets2, "SavedFile2.txt");

    cout << "Player's current position: (" << player.getX() << ", " << player.getY() << ")" <<endl;
    cout << "Moving the player." << endl;
    player.move(5,5);
    cout << "Now the player's position is: (" << player.getX() << ", " << player.getY() << ")" <<endl;
    cout << endl;

    cout << "The Slow Enemy's current position: (" << slowEnemy.getX() << ", " << slowEnemy.getY() << ")" <<endl;
    cout << "Moving the Slow Enemy." << endl;
    slowEnemy.move(5,5);
    cout << "Now the Slow Enemy's position is: (" << slowEnemy.getX() << ", " << slowEnemy.getY() << ")" <<endl;
    cout << endl;

    //Testing if the player was hit
    slowEnemy.hitPlayer();
    cout << endl;

    cout << "The player's score is currently: " << player.getScore() << endl;
    cout << "The player hit an enemy!" << endl;
    player.changeScore(5);
    player.setScore(5); // Need only one of these. Fix later
    cout << "Now the player's score is: " << player.getScore() << endl;
    cout << endl;

    cout << "The bullet's fill, speed, damage, and position are: (" << bullet1.getRed() << ", " << bullet1.getGreen() << ", " << bullet1.getBlue() << ") "
         << bullet1.getSpeed() << ", "
         << bullet1.getDamage() << ", ("
         << bullet1.getX() << ", "
         << bullet1.getY() << ")" << endl;
    cout << "Now let's change all this." << endl;
    bullet1.setCircle(Circle(1,bullet1.getFill()));
    bullet1.setCircle(bullet1.getCircle());
    bullet1.setPosition(3,10);
    bullet1.setSpeed(10);
    bullet1.setDamage(3);
    cout << "Now the bullet's fill, speed, damage, and position are: (" << bullet1.getRed() << ", " << bullet1.getGreen() << ", " << bullet1.getBlue() << ") "
         << bullet1.getSpeed() << ", "
         << bullet1.getDamage() << ", ("
         << bullet1.getX() << ", "
         << bullet1.getY() << ")" << endl;
    cout << endl;

    cout << "The bullet's current position is: (" << bullet1.getX() << ", " << bullet1.getY() << ")" << endl;
    cout << "The bullet is moving..." << endl;
    bullet1.move(10,10);
    cout << "Now the bullet's position is: (" << bullet1.getX() << ", " << bullet1.getY() << ")" << endl;
    cout << endl;

    cout << "The player's bullet hit an enemy!" << endl;
    bullet1.hitEnemy(slowEnemy);

    //Test out of bounds function
    bullet1.outOfBounds();

    cout << "The player's current health is: " << player.getHealth() << endl;
    cout << "An enemy reached the player!" << endl;
    player.setHealth(5);
    cout << "Now the player's health is: " << player.getHealth() << endl;
    cout << endl;

    cout << "The player's speed is: " << player.getSpeed() << endl;
    cout << "Let's change the player's speed." << endl;
    player.setSpeed(10);
    cout << "Now the player's speed is: " << player.getSpeed() << endl;
    cout << endl;

    cout << "The player's current radius is: " << player.getRadius() << endl;
    cout << "Let's make the player bigger." << endl;
    player.setCircle(mediumEnemy.getCircle()); //Not sure where to use this, just testing getCircle method
    player.setCircle(Circle(15,player.getFill()));
    cout << "Now, the player's radius is: " << player.getRadius() << endl;
    cout << endl;

    cout << "The slow enemy's current radius is: " << slowEnemy.getRadius() << endl;
    cout << "Let's make the slow enemy bigger." << endl;
    slowEnemy.setCircle(player.getCircle());//Not sure where to use this, just testing getCircle method
    slowEnemy.setCircle(Circle(15,slowEnemy.getFill()));
    cout << "Now, the slow enemy's radius is: " << slowEnemy.getRadius() << endl;
    cout << endl;
*/

    return 0;

}

/*
 * Requires: nothing
 * Modifies: nothing
 * Effects: Prints out the game description
 */
void gameDescription(){

    cout << "-----------------------------------------Game Description-----------------------------------------------------" << endl;
    cout << "Game type: Top Down Shooter" << endl;
    cout << "Game objects: Player, Enemies, Bullets" << endl;
    cout << endl;
    cout << "How it works: The Player is trying to shoot the Enemies as they come towards him/her." << endl;
    cout << "              There are three types of Enemies: Slow, Medium, Fast which move at varying speeds." << endl;
    cout << "              When the Player shoots an Enemy, it is destroyed and points are added to the Player's score." << endl;
    cout << "              If an Enemy reaches the Player before it is killed, the Player loses health points and the Enemy" << endl;
    cout << "              is destroyed." << endl;
    cout << "              When the Player completely runs out of health points, it is game over." << endl;
    cout << "              The goal is to survive as long as you can and accumulate the highest score." << endl;
    cout << endl;
    cout << "Saving the game: If the user decides they want to save the game at its current game state they can." << endl;
    cout << "                 The Player, Enemies, and Bullets along with their corresponding fields will be saved to a file." << endl;
    cout << "                 The game pieces can then be loaded from the file to resume the game state." << endl;
    cout << endl;
    cout << "-------------------------------------------Playing the Game-----------------------------------------------------" << endl;

}

/**
 *
 * @param players
 * @param enemies
 * @param bullets
 * @param fileName
 * Modifies: nothing
 * Effects: saves game objects' information to a file
 */
//void saving (const vector<Player> &players, const vector<unique_ptr<Enemy>> &enemies, const vector<Bullet> &bullets, string fileName){
//    // Saving
//
//    ofstream gameObjects(fileName); // Open file
//
//    if (gameObjects) {
//        gameObjects << players.size() << endl;
//        gameObjects << enemies.size() << endl;
//        gameObjects << bullets.size() << endl;
//
//        // for every player, save their stats
//        for (Player p: players) {
//            gameObjects << p.getHealth() << endl
//                        << p.getSpeed() << endl
//                        << p.getRadius() << endl
//                        << p.getRed() << endl
//                        << p.getGreen() << endl
//                        << p.getBlue()<< endl
//                        << p.getX() << endl
//                        << p.getY() << endl;
//        }
//
//        // for every enemy, save their stats
//        for (int i = 0; i < enemies.size(); ++i){
//            gameObjects << enemies[i]->getHealth() << endl
//                        << enemies[i]->getSpeed() << endl
//                        << enemies[i]->getScore() << endl
//                        << enemies[i]->getRadius() << endl
//                        << enemies[i]->getRed() << endl
//                        << enemies[i]->getGreen() << endl
//                        << enemies[i]->getBlue() << endl
//                        << enemies[i]->getX() << endl
//                        << enemies[i]->getY() << endl;
//        }
//
//
//        for (Bullet b: bullets) {
//            gameObjects << b.getRadius() << endl
//                        << b.getRed() << endl
//                        << b.getGreen() << endl
//                        << b.getBlue() << endl
//                        << b.getX() << endl
//                        << b.getY() << endl
//                        << b.getSpeed() << endl
//                        << b.getDamage() << endl;
//
//        }
//    }
//
//    gameObjects.close();
//}

/**
 * @param players
 * @param enemies
 * @param bullets
 * @param fileName
 * Modifies: players, enemies, bullets vectors
 * Effects: loads game objects' information from a file and saves it to corresponding vectors "players", "enemies", and "bullets"
 */
//
//void loading (vector<Player> &players, vector<unique_ptr<Enemy>> &enemies, vector<Bullet> &bullets, string fileName){
//
//    ifstream gameObjects(fileName); // Open file
//
//    int numPlayers;
//    int numEnemies;
//    int numBullets;
//    // Load the sizes of vectors
//    gameObjects >> numPlayers >> numEnemies >> numBullets;
//    // Load the player
//    // for every player.....
//    for (int i = 0; i < numPlayers; i++) {
//        int health;
//        int speed;
//        double radius;
//        double r, g, b;
//        int x, y;
//        gameObjects >> health >> speed >> radius >> r >> g >> b >> x >> y;
//        Circle circle = Circle(radius, {r,g,b});
//        circle.set_position(x,y);
//        players.push_back(Player(health,speed, circle));
//
//    }
//    // Load the enemies
//    // for every enemy.....
//    for (int i = 0; i < numEnemies; i++) {
//        int health;
//        int speed;
//        int score;
//        double radius;
//        double r, g, b;
//        int x, y;
//        gameObjects >> health >> speed >> score >> radius >> r >> g >> b >> x >> y;
//        Circle circle = Circle(radius, {r,g,b});
//        circle.set_position(x,y);
//        switch (speed){
//            /** MAKE SURE SPEEDS MATCH THAT OF SLOW, MEDIUM, FAST ENEMIES **/
//            case 1:
//                enemies.push_back(make_unique<Slow>( Slow(health, speed, score, circle) ) );
//                break;
//            case 2:
//                enemies.push_back(make_unique<Medium> ( Medium(health, speed, score, circle) ) );
//                break;
//            case 3:
//                enemies.push_back(make_unique<Fast> ( Fast(health, speed, score, circle) ) );
//                break;
//        }
//
//    }
//    // Load the bullets
//    for (int i = 0; i < numBullets; i++) {
//        int speed;
//        int damage;
//        double radius;
//        double r, g, b;
//        int x, y;
//        gameObjects >> radius >> r >> g >> b >> x >> y >> speed >> damage;
//        Circle circle = Circle(radius, {r,g,b});
//        circle.set_position(x,y);
//        bullets.push_back(Bullet(circle, speed, damage));
//    }
//
//    gameObjects.close();
//
//}
//