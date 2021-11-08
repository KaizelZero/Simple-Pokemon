// Header guard
#ifndef FINAL_PROJECT_POKEDEX_H
#define FINAL_PROJECT_POKEDEX_H

// Library and header file
#include <vector>
#include "pokemon.h"

using namespace std;

// Pokedex class
class Pokedex {
public:
    Pokedex(); // Default constructor

    Pokemon findPokemon(int number); // finds pokemon based on pokedex number
    Pokemon getPokemon(int number); // gets pokemon based on pokedex number

private:
    void bootUp(); // bootUp function
    vector<Pokemon> pokedex; // pokedex vector

};

#endif //FINAL_PROJECT_POKEDEX_H
