// Header guard
#ifndef FINAL_PROJECT_POKEMON_H
#define FINAL_PROJECT_POKEMON_H

// Libraries
#include <iostream>

using namespace std;

// moveSet structure
struct moveSet {
    string name;
    string type;
    int power;
    int ppRemaining;
    int ppTotal;
};

// Pokemon class (Referenced alot throughout code)
class Pokemon {
public:
    Pokemon(); // Default constructor
    //Structure of pokemon data
    Pokemon(int newPokemonNumber, string newName, string newType, int newHP,
            string newMoveName1, string newMoveType1, int newPower1, int newPP1,
            string newMoveName2, string newMoveType2, int newPower2, int newPP2,
            string newMoveName3, string newMoveType3, int newPower3, int newPP3,
            string newMoveName4, string newMoveType4, int newPower4, int newPP4);
    int getPokedexNumber(); // Pokemdex number getter
    string getName(); // Get name of pokemon
    string getType(); // Not implemented use of typing
    void setHP(int newHP); // Set HP as the hp
    int getHPRemaining(); // Remaining HP
    int getTotalHP(); // Total hp
    moveSet getMove(int move); // get move for different moves
    void usePP(int move); // Use pp

protected: // Uses protected so other classes can use these variables
    int pokedexNumber; // pokedex Number
    string name; // name of pokemon
    string type; // type of pokemon
    int hpRemaining; // remaining hp
    int hpTotal; //total hp
    // Move set declarations
    moveSet move1;
    moveSet move2;
    moveSet move3;
    moveSet move4;
};


#endif //FINAL_PROJECT_POKEMON_H
