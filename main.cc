#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "allCards.h"

using namespace std;

void loadDeck(vector<shared_ptr<Card>> &deck, std::string filename){
    ifstream deckfile {filename};
    string cardName;
    while (getline(deckfile, cardName)) {
        if(cardName == "Air Elemental") deck.push_back();
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
    return deck;
}

int main(int argc, char *argv[]){
    shared_ptr<Player> player1 = make_shared<Player>();
    shared_ptr<Player> player2 = make_shared<Player>();
    shared_ptr<Board> board = make_shared<Board>();
    vector<string> preInitArguments;
    for(int i = 1; i<argc; i++){
        if(argv[i] == "-deck1"){
            cout<<"Loading deck from: "<<argv[i+1]<<endl;
            //player1->giveDeck(loadDeck(argv[i+1]), "notOut");
            cout<<argv[i]<<endl;
            i++;
        }
        if(argv[i] == "-deck2"){
            cout<<"Loading deck from: "<<argv[i+1]<<endl;
            //player2->giveDeck(loadDeck(argv[i+1]), "notOut");
            cout<<argv[i]<<endl;
            i++;
        }
        if(argv[i] == "-init"){
            cout<<"Initializing from: "<<argv[i+1]<<endl;
            /*string source = argv[i+1];
             string cmd;
             ifstream fs{source};
             while(getline(fs, cmd)) {
             preInitArguments.emplace_back(cmd);
             }*/
            cout<<argv[i]<<endl;
            i++;
        }
        if(argv[i] == "-testing"){
            //boardPtr->enterTesting();
            cout<<argv[i]<<endl;
        }
        if(argv[i] = "-graphics"){
            //boardPtr->enterGraphics();
            cout<<argv[i]<<endl;
        }
    }
    /*if(!preInitArguments.empty()){
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
     //player1->playCard(num);
     }
     }
     }
     }*/
    string cmd;
    while(getline(cin,cmd)){
        if (cmd == "help") {
            cout << "Commands: help -- Display this message." << endl;
            cout << "          end  -- End the current player's turn." << endl;
            cout << "          quit -- End the game." << endl;
            cout << "          attack minion other-minion -- Orders minion to attack other-minion." << endl;
            cout << "          attack minion -- Orders minion to attack the opponent." << endl;
            cout << "          play card [target-player target-card] -- Play card, optionally targing" << endl;
            cout << "                                              target-card owned by target-player" << endl;
            cout << "          use minion [target-player target-card] -- Use minion's special ability," << endl;
            cout << "                          optionally targeting target-card owned by target-player" << endl;
            cout << "          inspect minion -- View a minion's card and all enchantments on that minion" << endl;
            cout << "          hand -- Describe all cards in your hand." << endl;
            cout << "          board -- Describe all cards on the board." << endl;
        }else if(cmd == "end"){
            cout<<"end"<<endl;
        } else if(cmd == "quit"){
            cout<<cmd<<endl;
        } else if(cmd == "draw"){
            cout<<"this has to be testing "<< cmd <<endl;
        } else if(cmd == "hand"){
            cout<<cmd<<endl;
        } else if(cmd == "board"){
            cout<<cmd<<endl;
        } else {
            istringstream iss {cmd};
            string temp;
            iss>>temp;
            if(temp == "attack"){
                int attacker, defender;
                iss>>attacker;
                if(iss>>defender){
                    cout<<"attack between "<<attacker<<"and "<<defender<<endl;
                } else {
                    cout<<"attack from "<<attacker<<endl;
                }
            } else if(temp == "play"){
                int cardNum, playerNum, targetNum;
                iss>>cardNum;
                if(iss>>playerNum&&iss>>targetNum){
                    cout<<temp<<" "<<cardNum<<"to player"<<playerNum<<"'s "<<targetNum<<endl;
                } else {
                    cout<<temp<<" "<<cardNum<<"to player"<<endl;
                }
            } else if(temp == "use"){
                int cardNum, playerNum, targetNum;
                iss>>cardNum;
                if(iss>>playerNum&&iss>>targetNum){
                    cout<<temp<< " "<<cardNum<<"to player"<<playerNum<<"'s "<<targetNum<<endl;
                } else {
                    cout<<temp<< " "<<cardNum<<"to player"<<endl;
                }
            } else if(temp == "inspect"){
                int cardNum;
                iss>>cardNum;
                cout << "Inspecting minion " << cardNum << endl;
            } else if(temp == "discard"){
                int cardNum;
                iss>>cardNum;
                cout << "discarding card number "<< cardNum << endl;
            } else {
                cout << "Invalid command, too see command help page please type \"help\"" << endl;
                continue;
            }
        }
    }
}
