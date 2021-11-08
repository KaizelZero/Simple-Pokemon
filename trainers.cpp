// Libraries and Header
#include <iostream>
#include <vector>
#include "trainers.h"
using namespace std;

// Default Constructor
trainers::trainers() : name("Ash"), numPokemon(0) {
}

// Constructor with Parameters
trainers::trainers(string newName, vector<Pokemon> newPokemonTeam) {
    name = newName;
    numPokemon = newPokemonTeam.size();
    pokemonTeam = newPokemonTeam;
}

// Removes pokemon from pokemonTeam from input name
void trainers::removePokemon(string name) {
    for (int i = 0; i < getNumPokemon(); i++) {
        if (pokemonTeam[i].getName() == name) {
            pokemonTeam.erase(pokemonTeam.begin() + i);
        }
    }
}

// Gets size of pokemonTeam
int trainers::getNumPokemon() {
    return pokemonTeam.size();
}

// Get pokemon from index
Pokemon trainers::getPokemon(int i) {
    return pokemonTeam[i];
}


// Get pokemon from pokemon Name
Pokemon trainers::getPokemon(string name) {
    int index = 0;
    for (int i = 0; i < getNumPokemon(); i++) {
        if (pokemonTeam[i].getName() == name) {
            index = i;
        }
    }
    return pokemonTeam[index];
}

// Checks if pokemon is in pokemonTeam
bool trainers::isInRoster(string name) {
    for (int i = 0; i < getNumPokemon(); i++) {
        if (pokemonTeam[i].getName() == name) {
            return true;
        }
    }
    return false;
}

// Sets the opponent and player names
void trainers::setName(string newName) {
    name = newName;
}

// Gets the name
string trainers::getName() {
    return name;
}
