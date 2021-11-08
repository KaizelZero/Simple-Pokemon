
// Libraries and Header files
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "battle.h"

// Default Constructor
battle::battle() {

}

// Creates the player and opponent
battle::battle(trainers newBlue, trainers newRed) {
    blue = newBlue;
    red = newRed;
}

// Chooses opponent pokemon
void battle::chooseBluePokemon() {
    srand(time(0)); //Random time as seed
    currentBluePokemon = blue.getPokemon(rand() % blue.getNumPokemon()); // Picks a random pokemon
    cout << "\n" << blue.getName() << " has sent out " << currentBluePokemon.getName() << "." << endl; // Displays the selected pokemon
}

// Player chooses pokemon
void battle::chooseRedPokemon() {
    string selection; // selection variable as string
    cout << "Which Pokemon would you like to send out?" << endl;
    // Displays all pokemon on the team
    for (int i = 0; i < red.getNumPokemon(); i++) {
        cout << "\t" << red.getPokemon(i).getName() << endl;
    }
    cout << "Enter the name of the Pokemon: " << endl; // Asks for user input
    cin >> selection; // Selection input
    selection[0] = toupper(selection[0]); // Allows for lowercase input
    // Keeps asking if invalid input
    while (cin.fail() || red.isInRoster(selection) == false) {
        cout << "The Pokemon you selected was not found in your roster." << endl;
        cout << "Please enter the name of one of your Pokemon: " << endl;
        cin >> selection;
        selection[0] = toupper(selection[0]);
    }
    currentRedPokemon = red.getPokemon(selection); // Sets current pokemon as the selected pokemon
}

Pokemon battle::getBluePokemon() {
    return currentBluePokemon; // setter for current opponent pokemon
}

Pokemon battle::getRedPokemon() {
    return currentRedPokemon; // setter for current player pokemon
}

// Unneeded function
int battle::getRedPokemonRemaining() {
    return red.getNumPokemon();
}

int battle::getBluePokemonRemaining() {
    return blue.getNumPokemon(); //Returns the amount of opponent pokemon left
}

// Opponent attack
void battle::blueAttack() {
    srand(time(0)); // Random time seeded
    int moveChoice = rand() % 4 + 1; // Random number [1, 4]
    int damage; // damage int

    // Checks pokemon PP (doesn't really matter because pokemon will die before hand)
    if (currentBluePokemon.getMove(moveChoice).ppRemaining == 0) {
        blueAttack(); // Calls function again if move had 0
    }

    // Enemy attack message
    cout << "Enemy " << currentBluePokemon.getName() << " attacked " << currentRedPokemon.getName() << " using "
         << currentBluePokemon.getMove(moveChoice).name << "!" << endl;
    currentBluePokemon.usePP(moveChoice); // Uses the move pp

    damage = currentBluePokemon.getMove(moveChoice).power; // Sets damage as the move power

    // Enemy damage message
    cout << "Enemy " << currentBluePokemon.getName() << " did " << damage << " points of damage to "
         << currentRedPokemon.getName() << "!" << endl;

    currentRedPokemon.setHP(currentRedPokemon.getHPRemaining() - damage); // Sets new HP
    if (currentRedPokemon.getHPRemaining() <= 0) { // If pokemon fainted
        cout << currentRedPokemon.getName() << " fainted" << endl; // Display the pokemon name
        red.removePokemon(currentRedPokemon.getName()); // Remove the pokemon from playerTeam
        if (red.getNumPokemon() > 0) { // If there are still player pokemon
            chooseRedPokemon(); // Prompt user for pokemon
        }
    }
}

// Player attack
void battle::redAttack() {
    // Declared variables
    string moveChoice;
    int damage;

    cout << currentRedPokemon.getName() << " is going to attack enemy " << currentBluePokemon.getName() << "!" << endl; // Player attack message
    cout << "What move should " << currentRedPokemon.getName() << " use?" << endl; // Move choice prompt

    // Displays player pokemon moves and pp
    for (int i = 0; i < 4; i++) {
        cout << "\t" << i + 1 << ": " << currentRedPokemon.getMove(i + 1).name << " ["
             << currentRedPokemon.getMove(i + 1).ppRemaining << "/" << currentRedPokemon.getMove(i + 1).ppTotal << "]"
             << endl;
    }

    cout << "Please enter the number of the move you would like to use: "; // Prompt moveChoice
    cin >> moveChoice; // Input number for move choice
    if (moveChoice == "") { // If move is empty
        moveChoice = "0"; // Set move choice to "0"
    }

    // while (invalid input, moveChoice is out of bounds, not a number, or has zero PP)
    while (cin.fail() || moveChoice[0] - 48 > 4 || moveChoice[0] - 48 < 1 || currentRedPokemon.getMove(moveChoice[0] - 48).ppRemaining == 0) {
        // Call for a different move
        if (currentRedPokemon.getMove(moveChoice[0] - 48).ppRemaining == 0) {
            cout << "There are not enough Power Points (PP) remaining to perform that move!" << endl;
        } else {
            cout << "That was not a valid move choice." << endl;
        }
        cin.ignore();
        cout << "Please select a different move: ";
        cin >> moveChoice;
        if (moveChoice == "") {
            moveChoice = "0";
        }
    }

    // Attack message
    cout << currentRedPokemon.getName() << " attacked enemy " << currentBluePokemon.getName() << " using "
         << currentRedPokemon.getMove(moveChoice[0] - 48).name << "!" << endl;
    currentRedPokemon.usePP(moveChoice[0] - 48); // Uses move PP

    damage = currentRedPokemon.getMove(moveChoice[0] - 48).power; // Sets damage to move power

    // Damage message
    cout << currentRedPokemon.getName() << " did " << damage << " points of damage to enemy "
         << currentBluePokemon.getName() << "!" << endl;

    currentBluePokemon.setHP(currentBluePokemon.getHPRemaining() - damage); // Sets new hp based on damage

    // If pokemon has fainted
    if (currentBluePokemon.getHPRemaining() <= 0) {
        defeatedPokes.push_back(currentBluePokemon.getName()); // Add pokemon into defeated pokemon vector
    }

    // If pokemon has fainted
    if (currentBluePokemon.getHPRemaining() <= 0) {
        cout << currentBluePokemon.getName() << " fainted!" << endl; // Display faint message
        blue.removePokemon(currentBluePokemon.getName()); // Remove pokemon from opponent team
        if (blue.getNumPokemon() > 0) { // If opponent isnt out of pokemon
            chooseBluePokemon(); // call chooseBlue pokemon function
        }

    }
}

// Return defeated pokemon vector
vector<string> battle::getDefeated() {
    return defeatedPokes;
}

// Return true or false if battle is still continuing
bool battle::continueBattle() {
    return (blue.getNumPokemon() > 0 && red.getNumPokemon() > 0);
}