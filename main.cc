#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;

void notOutDeck(unique_ptr<Deck> &deck ,std::string filename){
    deck->Empty();
    ifstream deckfile {filename};
    string cardName;
    while (getline(deckfile, cardName)) {
        if(cardName == "Air Elemental") deck->pushCard({});
        if(cardName == "Earth Elemental") deck->pushCard({});
        if(cardName == "Bone Golem") deck->pushCard({});
        if(cardName == "Fire Elemental") deck->pushCard({});
        if(cardName == "Potion Seller") deck->pushCard({});
        if(cardName == "Novice Pyromancer") deck->pushCard({});
        if(cardName == "Apprentice Summoner") deck->pushCard({});
        if(cardName == "Master Summoner") deck->pushCard({});
        if(cardName == "Banish") deck->pushCard({});
        if(cardName == "Unsummon") deck->pushCard({});
        if(cardName == "Recharge") deck->pushCard({});
        if(cardName == "Disenchant") deck->pushCard({});
        if(cardName == "Raise Dead") deck->pushCard({});
        if(cardName == "Blizzard") deck->pushCard({});
        if(cardName == "Giant Strength") deck->pushCard({});
        if(cardName == "Enrage") deck->pushCard({});
        if(cardName == "Haste") deck->pushCard({});
        if(cardName == "Magic Fatigue") deck->pushCard({});
        if(cardName == "Silence") deck->pushCard({});
        if(cardName == "Dark Ritual") deck->pushCard({});
        if(cardName == "Aura of Power") deck->pushCard({});
        if(cardName == "Standstill") deck->pushCard({});
    }
}

int main(int argc, char *argv[]){
    unique_ptr<Deck> deck1 = std::make_unique<Deck>(Deck{});
    unique_ptr<Deck> deck2 = std::make_unique<Deck>(Deck{});
    unique_ptr<Player> player1 = std::make_unique<Player>(Player{});
    unique_ptr<Player> player2 = std::make_unique<Player>(Player{});
    unique_ptr<Board> boardPtr = std::make_unique<Board>(Board{});
    vector<string> preInitArguments;
    for(int i = 1; i<argc; i++){
        if(argv[i] == "-deck1"){
            notOutDeck(deck1, argv[i+1]);
            player1->giveDeck(deck1, "notOut");
            i++;
        }
        if(argv[i] == "-deck2"){
            notOutDeck(deck2, argv[i+1]);
            player2->giveDeck(deck2, "notOut");
            i++;
        }
        if(argv[i] == "-init"){
            char c;
            string source = argv[i+1];
            string cmd;
            ifstream fs{source};
            while(getline(fs, cmd)) {
                preInitArguments.emplace_back(cmd);
            }
            i++;
        }
    }
}
