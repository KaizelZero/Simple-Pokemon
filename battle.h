// Header guard
#ifndef FINAL_PROJECT_BATTLE_H
#define FINAL_PROJECT_BATTLE_H

//Referenced classes
#include "pokemon.h"
#include "pokedex.h"
#include "trainers.h"

//battle Class
class battle {
public:
    battle(); // Default Constructors
    battle(trainers Red, trainers Blue); // Constructor with parameters
    void chooseBluePokemon(); // Choose opponent pokemon
    void chooseRedPokemon(); // Choose player pokemon
    Pokemon getBluePokemon(); // Get opponent pokemon of type Pokemon
    Pokemon getRedPokemon(); // Get player pokemon of type Pokemon
    int getRedPokemonRemaining(); // Red pokemon remaining (unused because there is a lost bool)
    int getBluePokemonRemaining(); // Blue pokemon remaining
    void blueAttack(); // Opponent attack function
    void redAttack(); // Player attack function
    bool continueBattle(); // Checks if battle is ongoing
    vector<string> getDefeated(); //get defeated pokemon function
private:
    trainers blue; // Opponent
    trainers red; // Player
    Pokemon currentBluePokemon; // Current opponent pokemon
    Pokemon currentRedPokemon; // Current player pokemon
    vector<string> defeatedPokes; // Vector of strings for defeated pokemon
};


#endif //FINAL_PROJECT_BATTLE_H
