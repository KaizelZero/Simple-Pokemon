// Library and header file
#include <iostream>
#include "pokemon.h"

using namespace std;

// Default constructor
Pokemon::Pokemon() {}

// Constructor with parameters
Pokemon::Pokemon(int newPokemonNumber, string newName, string newType, int newHP,
                 string newMoveName1, string newMoveType1, int newPower1, int newPP1,
                 string newMoveName2, string newMoveType2, int newPower2, int newPP2,
                 string newMoveName3, string newMoveType3, int newPower3, int newPP3,
                 string newMoveName4, string newMoveType4, int newPower4, int newPP4) {

    // Sets variables as the value defined in Pokemon::Pokemon
    pokedexNumber = newPokemonNumber;
    name = newName;
    type = newType;
    hpRemaining = newHP;
    hpTotal = newHP;

    move1.name = newMoveName1;
    move1.type = newMoveType1;
    move1.power = newPower1;
    move1.ppRemaining = newPP1;
    move1.ppTotal = newPP1;

    move2.name = newMoveName2;
    move2.type = newMoveType2;
    move2.power = newPower2;
    move2.ppRemaining = newPP2;
    move2.ppTotal = newPP2;

    move3.name = newMoveName3;
    move3.type = newMoveType3;
    move3.power = newPower3;
    move3.ppRemaining = newPP3;
    move3.ppTotal = newPP3;

    move4.name = newMoveName4;
    move4.type = newMoveType4;
    move4.power = newPower4;
    move4.ppRemaining = newPP4;
    move4.ppTotal = newPP4;

}
// Setters
int Pokemon::getPokedexNumber() {
    return pokedexNumber;
}
string Pokemon::getName() {
    return name;
}
string Pokemon::getType() { // Useless
    return type;
}
void Pokemon::setHP(int newHP) {
    hpRemaining = newHP;
}
int Pokemon::getHPRemaining() {
    return hpRemaining;
}
int Pokemon::getTotalHP() {
    return hpTotal;
}

// Returns the move
moveSet Pokemon::getMove(int move) {
    moveSet Temp; // creates a Temp move set
    Temp.ppRemaining = -1; // Subtracts 1 from pp
    // Switch case for move int
    switch (move) {
        case 1:
            return move1;
        case 2:
            return move2;
        case 3:
            return move3;
        case 4:
            return move4;
        default:
            return Temp; // So game doesn't break
    }

}

// Use PP function
void Pokemon::usePP(int move) {
    // Subtracts PP from specified move
    switch (move) {
        case 1:
            move1.ppRemaining--;
            break;
        case 2:
            move2.ppRemaining--;
            break;
        case 3:
            move3.ppRemaining--;
            break;
        case 4:
            move4.ppRemaining--;
            break;
    }
}

