/*This time, you are required to create a text-based game called "Monster Battle Arena" using C++. The game should allow players to choose a monster from a selection and engage in battles against other monsters. You are required to employ classes and inheritance while developing the game. Below are the requirements:

Create a base class called "Monster" with the following attributes:
Name (string)
Health Points (int)
Attack Points (int)

Implement derived classes for different types of monsters, such as "Dragon," "Goblin," and "Vampire." Each derived class should inherit from the "Monster" class and have unique characteristics, such as increased attack points or special abilities. Additionally, the game should allow the player to select a monster from the available types and assign a name to it. Create a function to simulate battles between two monsters. The battle should take place in turns, where each monster attacks the other until one's health points reach zero. Implement a basic AI opponent that randomly selects a monster from the available types.

The game should display relevant information such as the monsters' names, health points, and attack points during battles. The purpose of the Health Points (HP) in the code is to represent the current health status of a monster during the battle. Each monster has an initial amount of Health Points, which determines how much damage it can sustain before being defeated. When a monster is attacked by another monster, the attack inflicts a certain amount of damage, which is deducted from its Health Points. If a monster's Health Points reach 0 or less, it is considered defeated in the battle.

The Health Points provide a way to track and determine the outcome of the battle by checking if a monster's Health Points have dropped to 0 or below. By using the Health Points, the code can simulate the battles between monsters, track their damage taken, and determine when a monster is defeated. The Attack Points (AP) in the code represent the offensive capability or strength of a monster's attack during the battle. Each monster has a certain number of Attack Points, which determines how much damage it can inflict on its opponent when it performs an attack. When a monster initiates an attack, a random amount of damage within its Attack Points range is calculated and inflicted on the opponent. Higher Attack Points indicate a stronger attack, resulting in potentially higher damage inflicted on the opponent. The Attack Points provide a way to simulate the varying strength of attacks among different monsters, adding variability and strategy to the battles. In summary, the Health Points (HP) represent the current health status of a monster, while the Attack Points (AP) determine the strength of a monster's attack. These attributes are crucial in simulating the battles, tracking damage, and determining the outcome of the game.

In the current problem, the attack points are static values specific to each monster type and do not change during battles or the course of the game.*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
char choice;
int Options();
string monName;
int aiChoice = 1;
int damage = 0;


class Monster{
private:
    int HP;
    int AP;
    string Name;

public:
    void setHP(int health);
    void setAP(int attack);
    int getHP();
    int getAP();
    void setName();
    string getName();
    int attackMonster();
    void takeDamage(int a);
    Monster(int a, int b, string c){
        a = getHP();
        b = getAP();
        c = getName();
    }

};

void Monster::setHP(int health){
    HP = health;
}

int Monster::getHP(){
    return HP = 100;
}

void Monster::setAP(int attack){
    AP = attack;
}

int Monster::getAP(){
    return AP = 10;
}

void Monster::setName(){
    cout << "What would you like to name the Vampire? ";
    cin >> Name;
}

string Monster::getName(){
    return Name;
}
/*int Monster::attackMonster(){
    attack = rand() % getAP();
    return attack;
}*/

void Monster::takeDamage(int a){
    HP = HP - a;
}

class Vampire:public Monster{
public:
    int vampHP;
    int vampAttack;
    int vampTrueHP();
    int vampTrueAttack();
    Vampire(int a, int b, string c): Monster(a, b, c){}
};

int Vampire::vampTrueHP(){
    return vampHP = getHP() + 25;
}

int Vampire::vampTrueAttack(){
    return vampAttack = getAP() + 15;
}

void battle(){
    Vampire aa(125, 15, monName);
    string x = aa.getName();
    cout << x;
    //string y = bb.getName();
    //string z = cc.getName();
    cout << "Your opponent is: ";
    //aiChoice = rand() % 3 + 1;
    if(aiChoice == 1)
        cout << "Vampire" << endl;
        Vampire AV(AV.vampTrueHP(), AV.vampTrueAttack(), "Vampire Bot");
        cout << "Battle Start!" << endl;
        cout << "Name: " <<  aa.getName() << endl;
        cout << "Health Points: " << aa.vampTrueHP() << endl;
        cout << "Attack Points: " << aa.vampTrueAttack() << endl;
        cout << "----------- VS -----------" << endl;
        cout << "Name: " <<  AV.getName() << endl;
        cout << "Health Points: " << AV.vampTrueHP() << endl;
        cout << "Attack Points: " << AV.vampTrueAttack() << endl;

        /*/while (aa.getHP() > 0 && AV.getHP() > 0) {
            cout << damage << " is the damage number.";
            if(AV.getHP() > 0) {
                cout << AV.getHP() << "\n";
            }
            else{
                cout << AV.getName() << "is now dead.\n";
            }
        }*/

    if(aiChoice == 2)
        cout << "Dragon";
        //Dragon AI(200, 20, "Dragon");
    if(aiChoice == 3)
        cout << "Goblin";
}

int main()
{
    srand(time(NULL));
    int menu = 0;
    cout << "Welcome to Monster Battle Arena! Please choose your monster." << endl;
    do
    {
        menu = Options();
        switch(menu)
        {
            case 1:
                cout << "Vampire.\n";
                cout << "Would you like to choose the Vampire? ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y')
                {
                    cout << endl;
                    //cout << "What would you like to name the Vampire? ";
                    //cin >> monName;
                    battle();
                }
                break;
            case 2:
                cout << "Dragon.\n";
                cout << "Would you like to choose the Dragon? ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y')
                {
                    cout << endl;
                    cout << "What would you like to name the Dragon? ";
                    //cin >> monName;
                    //Dragon monName;
                    battle();
                }
                break;
            case 3:
                cout << "Goblin.\n";
                cout << "Would you like to choose the Goblin? ";
                cin >> choice;
                if(choice == 'y' || choice == 'Y')
                {
                    cout << endl;
                    cout << "What would you like to name the Demon? ";
                    //cin >> monName;
                    //Goblin monName;
                    battle();
                }
                break;
            case 4:
                cout << "Guess you don't wanna pit monsters against each other then..." << endl;
                break;
            default: cout << "Please choose a number.";
        }
    }while(menu == 0);

    return 0;
}

int Options()
{
    int MenuChoice;
        cout << endl << endl;
        cout << "Monster Choices\n";
        cout << "1. Vampire.\n";
        cout << "2. Dragon.\n";
        cout << "3. Demon.\n";
        cout << "4. Never mind.\n";
        cin >> MenuChoice;
        cout << endl << endl;
    return MenuChoice;
};
