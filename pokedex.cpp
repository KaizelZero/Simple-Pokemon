// Libraries and header file
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "pokedex.h"
using namespace std;

// Calls the bootUp function
Pokedex::Pokedex() {
    bootUp();
}

// Finds the pokemon based on the pokedex number
Pokemon Pokedex::findPokemon(int number) {
    // Checks through the pokedex
	int index = 0;
    for (unsigned int i = 0; i < pokedex.size(); i++) {
        // if the input number is the same number in pokedex
        if (pokedex[i].getPokedexNumber() == number) {
			index = i; // pokemon based on the index
        }
    }
	return pokedex[index];
}

// get pokemon based on pokedex number
Pokemon Pokedex::getPokemon(int number) {
    return pokedex[number];
}

// bootUp function
void Pokedex::bootUp() {
    // File input
    ifstream fin("pokemon.txt");
    // Input error
    if (!fin) {
        cerr << "\nerror inputting file" << endl;
    }

    // Reads from the file
    string line[20]; // Creates array of string of size 20
    getline(fin, line[0]); // takes first line (example structure of data)
    // Getline for the delimiter
    while (getline(fin, line[0], ',')) {
        for (int i = 1; i < 20; i++) {
            getline(fin, line[i], ',');
        }
        // Sets temp to the lines
        Pokemon temp(stoi(line[0]), line[1], line[2], stoi(line[3]),
                     line[4], line[5], stoi(line[6]), stoi(line[7]),
                     line[8], line[9], stoi(line[10]), stoi(line[11]),
                     line[12], line[13], stoi(line[14]), stoi(line[15]),
                     line[16], line[17], stoi(line[18]), stoi(line[19])
        );
        pokedex.push_back(temp); // Push back temp to pokedex
    }

    fin.close(); // Close input file

    // ORIGINAL POKEDEX INPUT BUT I NEED FILE INPUT
    //Ash's Team
    /*
    Pokemon Pikachu(25, "Pikachu", "Electric", 180,                // Pokemon: Pokedex Number, Name, Type, HP
                    "Thunder Bolt", "Electric", 90, 15,            // Move 1: Name, Type, Power, PP
                    "Iron Tail", "Steel", 100, 15,                 // Move 2: Name, Type, Power, PP
                    "Quick Attack", "Normal", 40, 30,              // Move 3: Name, Type, Power, PP
                    "Thunder", "Electric", 110, 10);               // Move 4: Name, Type, Power, PP
    pokedex.push_back(Pikachu);        // add the Pokemon into the Pokedex using the push_back command



    Pokemon Staraptor(398, "Staraptor", "Flying", 280,
                      "Brave Bird", "Flying", 120, 15,
                      "Arial Ace", "Flying", 60, 20,
                      "Take Down", "Normal", 90, 20,
                      "Close Combat", "Fighting", 120, 5);
    pokedex.push_back(Staraptor);

    Pokemon Torterra(389, "Torterra", "Grass", 300,
                     "Earthquake", "Ground", 100, 10,
                     "Razor Leaf", "Grass", 55, 25,
                     "Crunch", "Dark", 80, 15,
                     "Leaf Storm", "Grass", 140, 5);
    pokedex.push_back(Torterra);


    Pokemon Infernape(392, "Infernape", "Fire", 262,
                      "Close Combat", "Fighting", 120, 5,
                      "Flame Wheel", "Fire", 60, 25,
                      "Flamethrower", "Fire", 95, 15,
                      "Fire Blitz", "Fire", 120, 15);
    pokedex.push_back(Infernape);

    Pokemon Buizel(418, "Buizel", "Water", 220,
                   "Aqua Tail", "Water", 90, 10,
                   "Water Gun", "Water", 40, 25,
                   "Razor Wind", "Normal", 80, 10,
                   "Hydro Pump", "Water", 110, 5);
    pokedex.push_back(Buizel);

    Pokemon Gible(443, "Gible", "Dragon", 226,
                  "Dragon Rush", "Dragon", 100, 10,
                  "Dragon Claw", "Dragon", 80, 15,
                  "Take Down", "Normal", 90, 20,
                  "Draco Meteor", "Dragon", 130, 5);
    pokedex.push_back(Gible);

    //Sinnoh Elite Four

    //Aaron (Bug)
    Pokemon Dustox(269, "Dustox", "Bug", 230,
                   "Bug Buzz", "Bug", 90, 10,
                   "Venoshock", "Poison", 65, 10,
                   "Silver Wind", "Normal", 60, 5,
                   "Psybeam", "Psychic", 65, 20);
    pokedex.push_back(Dustox);


    Pokemon Heracross(214, "Heracross", "Bug", 270,
                      "Close Combat", "Fighting", 120, 5,
                      "Megahorn", "Bug", 120, 10,
                      "Brick Break", "Fighting", 75, 15,
                      "Horn Attack", "Normal", 65, 25);
    pokedex.push_back(Heracross);

    Pokemon Vespiquen(416, "Vespiquen", "Bug", 250,
                      "Attack Order", "Bug", 90, 15,
                      "Air Slash", "Flying", 75, 15,
                      "Power Gem", "Rock", 80, 20,
                      "Pin Missile", "Bug", 25, 20);
    pokedex.push_back(Vespiquen);


    Pokemon Beautifly(267, "Beautifly", "Bug", 230,
                      "Bug Buzz", "Bug", 90, 10,
                      "Silver Wind", "Bug", 60, 5,
                      "Air Cutter", "Flying", 60, 25,
                      "Struggle Bug", "Bug", 50, 20);
    pokedex.push_back(Beautifly);


    Pokemon Drapion(452, "Drapion", "Poison", 250,
                    "X-Scissor", "Bug", 80, 25,
                    "Crunch", "Dark", 80, 15,
                    "Poison Fang", "Poison", 50, 15,
                    "Venoshock", "Poison", 65, 10);
    pokedex.push_back(Drapion);

    //Bertha (GROUND)
    Pokemon Quagsire(195, "Quagsire", "Water", 300,
                     "Earthquake", "Ground", 100, 10,
                     "Muddy Water", "Water", 90, 10,
                     "Aqua Tail", "Water", 90, 10,
                     "Mud Shot", "Water", 55, 15);
    pokedex.push_back(Quagsire);

    Pokemon Hippowdon(450, "Hippowdon", "Ground", 326,
                      "Earthquake", "Ground", 100, 10,
                      "Crunch", "Dark", 80, 15,
                      "Sand Tomb", "Ground", 35, 15,
                      "Tackle", "Normal", 40, 35);
    pokedex.push_back(Hippowdon);

    Pokemon Sudowoodo(185, "Sudowoodo", "Rock", 250,
                      "Rock Slide", "Rock", 75, 10,
                      "Sucker Punch", "70", 90, 5,
                      "Rock Throw", "Rock", 50, 15,
                      "Double-Edge", "Normal", 120, 15);
    pokedex.push_back(Sudowoodo);

    Pokemon Whiscash(340, "Whiscash", "Water", 330,
                     "Earthquake", "Ground", 100, 10,
                     "Muddy Water", "Water", 90, 10,
                     "Aqua Tail", "Water", 90, 10,
                     "Mud-Slap", "Water", 20, 10);
    pokedex.push_back(Whiscash);

    Pokemon Golem(195, "Golem", "Rock", 270,
                  "Earthquake", "Ground", 100, 10,
                  "Rock Slide", "Rock", 75, 10,
                  "Double-Edge", "Normal", 120, 15,
                  "Rock Throw", "Rock", 50, 15);
    pokedex.push_back(Golem);

    //Flint (FIRE)
    Pokemon Rapidash(78, "Rapidash", "Fire", 240,
                     "Flare Blitz", "Fire", 120, 15,
                     "Fire Spin", "Fire", 35, 15,
                     "Ember", "Fire", 40, 25,
                     "Stomp", "Normal", 65, 20);
    pokedex.push_back(Rapidash);

    Pokemon Steelix(208, "Steelix", "Fire", 260,
                    "Iron Tail", "Steel", 100, 15,
                    "Slam", "Normal", 80, 20,
                    "Rock Slide", "Rock", 75, 10,
                    "Sand Tomb", "Ground", 35, 15);
    pokedex.push_back(Steelix);

    Pokemon Lopunny(428, "Lopunny", "Normal", 240,
                    "High Jump Kick", "Fighting", 130, 10,
                    "Dizzy Punch", "Fire", 35, 15,
                    "Quick Attack", "Normal", 40, 30,
                    "Bounce", "Flying", 85, 5);
    pokedex.push_back(Lopunny);

    Pokemon Drifblim(426, "Drifblim", "Ghost", 410,
                     "Phantom Force", "Ghost", 90, 10,
                     "Shadow Ball", "Ghost", 80, 15,
                     "Hex", "Ghost", 65, 10,
                     "Ominous Wind", "Ghost", 60, 5);
    pokedex.push_back(Drifblim);

    //Lucian (PSYCHIC)
    Pokemon Mime(122, "Mr. Mime", "Psychic", 190,
                 "Psychic", "Psychic", 90, 10,
                 "Psybeam", "Psychic", 65, 20,
                 "Brick Break", "Fighting", 75, 15,
                 "Focus Punch", "Fighting", 150, 20);
    pokedex.push_back(Mime);

    Pokemon Girafarig(203, "Girafarig", "Psychic", 250,
                      "Psychic", "Psychic", 90, 10,
                      "Psybeam", "Psychic", 65, 20,
                      "Crunch", "Dark", 80, 15,
                      "Zen Headbutt", "Psychic", 90, 10);
    pokedex.push_back(Girafarig);

    Pokemon Medicham(308, "Medicham", "Psychic", 250,
                     "High Jump Kick", "Fighting", 130, 10,
                     "Force Palm", "Fighting", 60, 10,
                     "Feint", "Normal", 50, 10,
                     "Zen Headbutt", "Psychic", 90, 10);
    pokedex.push_back(Medicham);

    Pokemon Alakazam(65, "Alakazam", "Psychic", 220,
                     "High Jump Kick", "Fighting", 130, 10,
                     "Psybeam", "Psychic", 65, 20,
                     "Psycho Cut", "Psychic", 70, 20,
                     "Future Sight", "Psychic", 80, 15);
    pokedex.push_back(Alakazam);

    Pokemon Bronzong(437, "Bronzong", "Steel", 244,
                     "Payback", "Dark", 50, 10,
                     "Extrasensory", "Psychic", 80, 30,
                     "Faint Attack", "Dark", 60, 20,
                     "Future Sight", "Psychic", 80, 15);
    pokedex.push_back(Bronzong);

    //Cynthia (CHAMPION)
    Pokemon Spiritomb(442, "Spiritomb", "Ghost", 244,
                      "Dark Pulse", "Dark", 80, 15,
                      "Psychic", "Psychic", 90, 10,
                      "Silver Wind", "Normal", 60, 5,
                      "Ominous Wind", "Ghost", 60, 5);
    pokedex.push_back(Spiritomb);

    Pokemon Roserade(407, "Roserade", "Grass", 230,
                     "Energy Ball", "Grass", 90, 10,
                     "Sludge Bomb", "Poison", 90, 10,
                     "Shadow Ball", "Ghost", 80, 15,
                     "Extrasensory", "Psychic", 80, 30);
    pokedex.push_back(Roserade);

    Pokemon Gastrodon(423, "Gastrodon", "Water", 332,
                      "Muddy Water", "Water", 90, 10,
                      "Earthquake", "Ground", 100, 10,
                      "Stone Edge", "Rock", 100, 5,
                      "Sludge Bomb", "Poison", 90, 10);
    pokedex.push_back(Gastrodon);

    Pokemon Lucario(448, "Gastrodon", "Fighting", 250,
                    "Aura Sphere", "Fighting", 80, 20,
                    "Dragon Pulse", "Dragon", 85, 10,
                    "Psychic", "Psychic", 90, 10,
                    "Earthquake", "Ground", 100, 10);
    pokedex.push_back(Lucario);

    Pokemon Milotic(350, "Milotic", "Water", 300,
                    "Surf", "Water", 90, 15,
                    "Ice Beam", "Ice", 90, 10,
                    "Hydro Pump", "Water", 110, 5,
                    "Aqua Tail", "Water", 90, 10);
    pokedex.push_back(Milotic);

    Pokemon Garchomp(445, "Garchomp", "Dragon", 326,
                     "Dragon Rush", "Dragon", 100, 10,
                     "Earthquake", "Ground", 100, 10,
                     "Brick Break", "Fighting", 75, 15,
                     "Giga Impact", "Normal", 150, 5);
    pokedex.push_back(Garchomp);
    */
}
