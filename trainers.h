// Header guard
#ifndef FINAL_PROJECT_TRAINERS_H
#define FINAL_PROJECT_TRAINERS_H

// Header and header file
#include <iostream>
#include <vector>
#include "pokemon.h"
using namespace std;

// trainers class
class trainers {
public:
    trainers(); // Default constructor
    trainers(string newName, vector<Pokemon> newPokemonTeam); // Constructor with parameters
    void setName(string newName); // set name Function
    string getName(); // Gets the name of the trainer
    int getNumPokemon(); // Gets the amount of pokemon for the trainer
    Pokemon getPokemon(int i); // Gets pokemon from the pokedex number
    Pokemon getPokemon(string name); // Gets pokemon with the pokemon name
    void setPokemon(int temp);
    bool isInRoster(string name); // Checks if the pokemon is in the team
    void removePokemon(string name); // Removes pokemon from pokemonTeam
private:
    string name; // variable name as string
    int numPokemon; // Amount of pokemon int
    vector<Pokemon> pokemonTeam; // pokemon team vector
};


#endif //FINAL_PROJECT_TRAINERS_H
