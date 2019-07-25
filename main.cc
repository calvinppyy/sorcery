#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "allCard.h"

using namespace std;

vector<unique_ptr<Card>> loadDeck(std::string filename){
    vector<unique_ptr<Card>> deck;
    ifstream deckfile {filename};
    string cardName;
    while (getline(deckfile, cardName)) {
        if(cardName == "Air Elemental") deck.push_back({});
        if(cardName == "Earth Elemental") deck.push_back({});
        if(cardName == "Bone Golem") deck.push_back({});
        if(cardName == "Fire Elemental") deck.push_back({});
        if(cardName == "Potion Seller") deck.push_back({});
        if(cardName == "Novice Pyromancer") deck.push_back({});
        if(cardName == "Apprentice Summoner") deck.push_back({});
        if(cardName == "Master Summoner") deck.push_back({});
        if(cardName == "Banish") deck.push_back({});
        if(cardName == "Unsummon") deck.push_back({});
        if(cardName == "Recharge") deck.push_back({});
        if(cardName == "Disenchant") deck.push_back({});
        if(cardName == "Raise Dead") deck.push_back({});
        if(cardName == "Blizzard") deck.push_back({});
        if(cardName == "Giant Strength") deck.push_back({});
        if(cardName == "Enrage") deck.push_back({});
        if(cardName == "Haste") deck.push_back({});
        if(cardName == "Magic Fatigue") deck.push_back({});
        if(cardName == "Silence") deck.push_back({});
        if(cardName == "Dark Ritual") deck.push_back({});
        if(cardName == "Aura of Power") deck.push_back({});
        if(cardName == "Standstill") deck.push_back({});
    }
}

int main(int argc, char *argv[]){
    unique_ptr<Player> player1 = std::make_unique<Player>(Player{});
    unique_ptr<Player> player2 = std::make_unique<Player>(Player{});
    unique_ptr<Board> boardPtr = std::make_unique<Board>(Board{});
    vector<string> preInitArguments;
    for(int i = 1; i<argc; i++){
        if(argv[i] == "-deck1"){
            player1->giveDeck(loadDeck(argv[i+1]), "notOut");
            i++;
        }
        if(argv[i] == "-deck2"){
            player2->giveDeck(loadDeck(argv[i+1]), "notOut");
            i++;
        }
        if(argv[i] == "-init"){
            string source = argv[i+1];
            string cmd;
            ifstream fs{source};
            while(getline(fs, cmd)) {
                preInitArguments.emplace_back(cmd);
            }
            i++;
        }
        if(argv[i] == "-testing"){
            boardPtr->enterTesting();
        }
        if(argv[i] = "-graphics"){
            boardPtr->enterGraphics();
        }
    }
    if(!preInitArguments.empty()){
        int temp = 0;
        int turn = 0;
        while(temp<preInitArguments.size()){
            if(temp == 0){
                player1->giveName(preInitArguments.at(temp));
                temp++;
                continue;
            }
            if(temp == 1){
                player1->giveName(preInitArguments.at(temp));
                temp++;
                continue;
            }
            istringstream iss{preInitArguments.at(temp)};
            int num;
            string arg;
            iss>>arg;
            if(arg == "play"){
                iss>>num;
                if(turn%2 == 0){
                    player1->playCard(num);
                }
            }
        }
    }
}
