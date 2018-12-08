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