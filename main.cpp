/*
 *  CSCI 261 FINAL PROJECT - Simple Pokemon by Jimmy Truong
 */

// Libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
// Headers
#include "battle.h"
#include "pokedex.h"
#include "pokemon.h"
#include "trainers.h"

using namespace std;

// Create Team Function Declarations
void createAsh(Pokedex pokedex, string &name, vector<Pokemon> &playerTeam);

void createLeader(Pokedex pokedex, string &leaderName, vector<Pokemon> &leaderTeam);

int main()
{
    // Class Declarations
    Pokedex pokedex;
    battle battleArena;
    trainers Red;
    trainers Blue;
    
    // Main Variables
    bool lost = false;
    char decision;
    int victory = 1;
    char choosen;
    string name;
    vector<Pokemon> playerTeam;
    string leaderName;
    vector<Pokemon> leaderTeam;
    vector<string> defeatedMons;
    
    // Welcome Message
    cout << "\n"
    << setw(30) << setfill('=') << "" << endl;
    cout << "WELCOME TO THE SINNOH LEAGUE!" << endl;
    cout << setw(30) << setfill('=') << "" << endl;
    
    // Choose to battle
    cout << "Are You Ready to Battle?! [Y]es or [N]o" << endl;
    cin >> choosen;
    choosen = toupper(choosen);
    // Will keep asking if Y isn't inputted
    if (choosen == 'C')
    {
        // Cheating for debugging so you don't have to fight everyone
        int cheat;
        cin >> cheat;
        if (cheat == 0){
            lost = true;
        } else {
            victory = cheat;
        }
        choosen = 0;
    }
    else
    {
        while (choosen != 'Y')
        {
            choosen = 0;
            cout << "Are You Ready to Battle?! [Y]es or [N]o" << endl;
            cin >> choosen;
            choosen = toupper(choosen);
        }
    }
    
    // Very big while loop that will continue looping until lost is true and victor <= 5
    while (lost != true && (victory <= 5))
    {
        // Will switch leaders depending on victory count
        switch (victory)
        {
            case 1:
                leaderName = "Aaron";
                break;
            case 2:
                leaderName = "Bertha";
                break;
            case 3:
                leaderName = "Flint";
                break;
            case 4:
                leaderName = "Lucian";
                break;
            case 5:
                leaderName = "Cynthia";
                break;
        }
        
        // Clears and creates new teams
        leaderTeam.clear();
        playerTeam.clear();
        createAsh(pokedex, name, playerTeam);
        Red = trainers(name, playerTeam);
        createLeader(pokedex, leaderName, leaderTeam);
        Blue = trainers(leaderName, leaderTeam);
        
        // Displays Leader's team
        for (int i = 0; i < leaderTeam.size(); i++)
        {
            cout << leaderTeam[i].getName() << endl;
        }
        
        battleArena = battle(Blue, Red); // Creates Blue and Red player
        
        battleArena.chooseBluePokemon(); // Chooses opponent Pokemon randomly
        
        battleArena.chooseRedPokemon(); // Allows the user to pick their Pokemon
        
        // While continueBattle is true from battle.cpp
        while (battleArena.continueBattle())
        {
            // Display "Pokemon [HP: ] vs. Opponent [HP: ]"
            cout << "\n\n"
            << endl;
            cout << battleArena.getRedPokemon().getName() << " [HP: " << battleArena.getRedPokemon().getHPRemaining()
            << "/" << battleArena.getRedPokemon().getTotalHP() << "]"
            << " vs. "
            << battleArena.getBluePokemon().getName() << " [HP: " << battleArena.getBluePokemon().getHPRemaining()
            << "/" << battleArena.getBluePokemon().getTotalHP() << "]" << endl;
            
            // Decision to Attack or Switch Pokemon
            cout << "What would you like to do? [A]ttack or [S]witch Pokemon?\n> ";
            cin >> decision;
            decision = toupper(decision); // Makes the letter uppercase
            
            // If the input is incorrect ask again
            while (cin.fail() || (decision != 'A' && decision != 'S'))
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Your selection was invalid. Please try again.\n> ";
                cin >> decision;
                decision = toupper(decision);
            }
            
            // Attack or Switch Pokemon
            if (decision == 'A')
            {
                battleArena.redAttack(); // Attacks opponent Pokemon from battle.cpp
            }
            else
            {
                battleArena.chooseRedPokemon(); // Chooses Pokemon from battle.cpp
            }
            cout << "\n\n"
            << endl; // Spacer
            
            // If there is still opponent Pokemon Remaining
            if (battleArena.getBluePokemonRemaining() > 0)
            {
                // Display "Pokemon [HP: ] vs. Opponent [HP: ]"
                cout << battleArena.getRedPokemon().getName() << " [HP: "
                << battleArena.getRedPokemon().getHPRemaining() << "/" << battleArena.getRedPokemon().getTotalHP()
                << "]"
                << " vs. "
                << battleArena.getBluePokemon().getName() << " [HP: "
                << battleArena.getBluePokemon().getHPRemaining() << "/"
                << battleArena.getBluePokemon().getTotalHP() << "]"
                << endl;
                battleArena.blueAttack(); // Opponent Attack
            }
        }
        
        // If opponent has no Pokemon
        if (battleArena.getBluePokemonRemaining() == 0)
        {
            // Display winning message
            cout << name << " defeated " << leaderName << "!" << endl;
            cout << name << " got $" << rand() % 10000 + 1000 << " for winning!\n\n"
            << endl; // Displays unnecessary money because theres no money implemented yet
            victory += 1; // Increase count by 1
        }
        else
        {
            // Display loss message
            cout << "\n\n"
            << leaderName << " defeated " << name << "!" << endl;
            lost = true; // Lost becomes true and exits main while loop
        }
        
        // Gives a break so users can look back and know when the next battle is
        if (!lost && victory <= 5)
        {
            choosen = 0;
            cout << "Are you ready to continue? [Y]es or [N]o" << endl;
            cin >> choosen;
            choosen = toupper(choosen);
            // Will display message again if invalid input
            while (choosen != 'Y')
            {
                choosen = 0;
                cout << "Are you ready to continue? [Y]es or [N]o" << endl;
                cin >> choosen;
                choosen = toupper(choosen);
            }
        }
        
        // Defeated pokemon vector
        defeatedMons.push_back(leaderName + ": "); // Shows the leader
        for (int i = 0; i < battleArena.getDefeated().size(); ++i)
        {
            defeatedMons.push_back(battleArena.getDefeated()[i]); // Adds a Pokemon to defeated pokemon vector
        }
    }
    
    playerTeam.clear();                   // Clears playerTeam because it got wonky towards the end
    createAsh(pokedex, name, playerTeam); // Recreates playTeam
    string file;                          // File name
    
    // File name based on win or lose
    if (lost)
    {
        file = "Losing_Team.txt";
    }
    else if (victory == 6)
    {
        file = "Winning_Team.txt";
    }
    
    ofstream fout(file); //File output
    
    // Writes lose or win
    if (lost)
    {
        cout << "You lost! Good luck next time!" << endl;
        fout << "You lost with this team!" << endl;
    }
    else
    {
        cout << "Congratulations! You've defeated the Elite Four and became the Champion!" << endl;
        fout << "You won with this team!" << endl;
    }
    // Writes playerTeam
    for (int i = 0; i < playerTeam.size(); i++)
    {
        fout << playerTeam[i].getName() << endl;
    }
    
    // Writes the pokemon you've defeated
    fout << "\nYou've defeated these Pokemon!\n";
    for (int i = 0; i < defeatedMons.size(); i++)
    {
        fout << defeatedMons[i] << endl;
    }
    
    fout.close(); // Closes file
    
    // Exit prompt for mainly for SimplePokmon.exe
    char button;
    cout << "Press ENTER to exit " << endl;
    cin.ignore();
    cin.get(button);
    
    if (button == '\n')
    {
        return 1;
    }
}

// create playerTeam function
void createAsh(Pokedex pokedex, string &name, vector<Pokemon> &playerTeam)
{
    name = "Ash";                                   // Name displayed when you defeat or are defeated
    playerTeam.push_back(pokedex.findPokemon(25));  //Pikachu
    playerTeam.push_back(pokedex.findPokemon(398)); //Staraptor
    playerTeam.push_back(pokedex.findPokemon(389)); //Torterra
    playerTeam.push_back(pokedex.findPokemon(392)); //Infernape
    playerTeam.push_back(pokedex.findPokemon(418)); //Buizel
    playerTeam.push_back(pokedex.findPokemon(443)); //Gible
}

void createLeader(Pokedex pokedex, string &leaderName, vector<Pokemon> &leaderTeam)
{
    cout << "\nLEADER - "; // Displays leader before their pokemon
    // Pokemon chosen based on leaderName
    if (leaderName == "Aaron")
    {
        leaderTeam.push_back(pokedex.findPokemon(269)); //Dustox
        leaderTeam.push_back(pokedex.findPokemon(214)); //Heracross
        leaderTeam.push_back(pokedex.findPokemon(416)); //Vespiqueen
        leaderTeam.push_back(pokedex.findPokemon(267)); //Beautifly
        leaderTeam.push_back(pokedex.findPokemon(452)); //Drapion
        cout << "Aaron" << endl;                        // Displays leader name
    }
    else if (leaderName == "Bertha")
    {
        leaderTeam.push_back(pokedex.findPokemon(195)); //Quadsire
        leaderTeam.push_back(pokedex.findPokemon(450)); //Hippowdon
        leaderTeam.push_back(pokedex.findPokemon(185)); //Sudowoodo
        leaderTeam.push_back(pokedex.findPokemon(340)); //Whiscash
        leaderTeam.push_back(pokedex.findPokemon(76));  //Golem
        cout << "Bertha" << endl;
    }
    else if (leaderName == "Flint")
    {
        leaderTeam.push_back(pokedex.findPokemon(78));  //Rapidash
        leaderTeam.push_back(pokedex.findPokemon(392)); //Infernape
        leaderTeam.push_back(pokedex.findPokemon(208)); //Steelix
        leaderTeam.push_back(pokedex.findPokemon(428)); //Lopunny
        leaderTeam.push_back(pokedex.findPokemon(426)); //Driftblim
        cout << "Flint" << endl;                        // Weird pokemon for a FIRE gym
    }
    else if (leaderName == "Lucian")
    {
        leaderTeam.push_back(pokedex.findPokemon(122)); //Mr.Mime
        leaderTeam.push_back(pokedex.findPokemon(203)); //Girafarig
        leaderTeam.push_back(pokedex.findPokemon(308)); //Medicham
        leaderTeam.push_back(pokedex.findPokemon(65));  //Alakazam
        leaderTeam.push_back(pokedex.findPokemon(437)); //Bronzong
        cout << "Lucian" << endl;
    }
    else if (leaderName == "Cynthia")
    {
        leaderTeam.push_back(pokedex.findPokemon(442)); //Spiritomb
        leaderTeam.push_back(pokedex.findPokemon(407)); //Roserade
        leaderTeam.push_back(pokedex.findPokemon(423)); //Gastrodon
        leaderTeam.push_back(pokedex.findPokemon(448)); //Lucario
        leaderTeam.push_back(pokedex.findPokemon(350)); //Milotic
        leaderTeam.push_back(pokedex.findPokemon(445)); //Garchomp
        cout << "Cynthia" << endl;
    }
    else
    {
        return;
    }
}
