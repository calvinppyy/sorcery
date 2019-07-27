#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "trigger.h"

using namespace std;

void loadDeck(shared_ptr<Player> player, vector<shared_ptr<Card>> &deck, std::string filename){
    deck.clear();
    vector<shared_ptr<Card>> temp;
    ifstream deckfile {filename};
    string cardName;
    while (getline(deckfile, cardName)) {
        if(cardName == "Air Elemental") temp.emplace_back(make_shared<Minion>(Minion{"Air Elemental", player}));
        if(cardName == "Earth Elemental") temp.emplace_back(make_shared<Minion>(Minion{"Earth Elemental", player}));
        if(cardName == "Bone Golem") temp.emplace_back(make_shared<Minion>(Minion{"Bone Golem", player}));
        if(cardName == "Fire Elemental") temp.emplace_back(make_shared<Minion>(Minion{"Fire Elemental", player}));
        if(cardName == "Potion Seller") temp.emplace_back(make_shared<Minion>(Minion{"Potion Seller", player}));
        if(cardName == "Novice Pyromancer") temp.emplace_back(make_shared<Minion>(Minion{"Novice Pyromancer", player}));
        if(cardName == "Apprentice Summoner") temp.emplace_back(make_shared<Minion>(Minion{"Apprentice Summoner", player}));
        if(cardName == "Master Summoner") temp.emplace_back(make_shared<Minion>(Minion{"Master Summoner", player}));
        if(cardName == "Banish") temp.emplace_back(make_shared<Spell>(Spell{"Banish", player}));
        if(cardName == "Unsummon") temp.emplace_back(make_shared<Spell>(Spell{"Unsummon", player}));
        if(cardName == "Recharge") temp.emplace_back(make_shared<Spell>(Spell{"Recharge", player}));
        if(cardName == "Disenchant") temp.emplace_back(make_shared<Spell>(Spell{"Disenchant", player}));
        if(cardName == "Raise Dead") temp.emplace_back(make_shared<Spell>(Spell{"Raise Dead", player}));
        if(cardName == "Blizzard") temp.emplace_back(make_shared<Spell>(Spell{"Blizzard", player}));
        if(cardName == "Giant Strength") temp.emplace_back(make_shared<Enchantment>(Enchantment{"Giant Strength", player}));
        if(cardName == "Enrage") temp.emplace_back(make_shared<Enchantment>(Enchantment{"Enrage", player}));
        if(cardName == "Haste") temp.emplace_back(make_shared<Enchantment>(Enchantment{"Haste", player}));
        if(cardName == "Magic Fatigue") temp.emplace_back(make_shared<Enchantment>(Enchantment{"Magic Fatigue", player}));
        if(cardName == "Silence") temp.emplace_back(make_shared<Enchantment>(Enchantment{"Silence", player}));
        if(cardName == "Dark Ritual") temp.emplace_back(make_shared<Ritual>(Ritual{"Dark Ritual", player}));
        if(cardName == "Aura of Power") temp.emplace_back(make_shared<Ritual>(Ritual{"Aura of Power", player}));
        if(cardName == "Standstill") temp.emplace_back(make_shared<Ritual>(Ritual{"Standstill", player}));
    }
    while(!temp.empty()){
        deck.emplace_back(temp.back());
        temp.pop_back();
    }
}

int main(int argc, char *argv[]){
    vector<shared_ptr<Card>> deck1;
    vector<shared_ptr<Card>> deck2;
    shared_ptr<Player> player1 = make_shared<Player>(Player{deck1, ""});
    shared_ptr<Player> player2 = make_shared<Player>(Player{deck2, ""});
    loadDeck(player1,deck1,"default.deck");
    deck1.emplace_back(make_shared<Minion>(Minion{"Air Elemental", player1}));//hard code
    deck1.emplace_back(make_shared<Minion>(Minion{"Earth Elemental", player1}));//hard code
    deck1.emplace_back(make_shared<Ritual>(Ritual{"Dark Ritual", player1}));//hard code
    player1->giveDeck(deck1);
    loadDeck(player2,deck2, "default.deck");
    deck2.emplace_back(make_shared<Enchantment>(Enchantment{"Giant Strength", player2}));//hard code
    deck2.emplace_back(make_shared<Spell>(Spell{"Blizzard", player2}));//hard code
    deck2.emplace_back(make_shared<Minion>(Minion{"Apprentice Summoner", player2}));//hard code
    player2->giveDeck(deck2);
    shared_ptr<Board> board = make_shared<Board>(Board{player1, player2});
    player1->setOpponent(player2);
    player2->setOpponent(player1);
    vector<string> preInitArguments;
    for(int i = 1; i<argc; i++){
        if(argv[i] == "-deck1"){
            cout<<"Loading deck from: "<<argv[i+1]<<endl;
            loadDeck(player1, deck1, argv[i+1]);
            player1->giveDeck(deck1);
            i++;
        }
        if(argv[i] == "-deck2"){
            cout<<"Loading deck from: "<<argv[i+1]<<endl;
            loadDeck(player2, deck2, argv[i+1]);
            player2->giveDeck(deck2);
            i++;
        }
        if(argv[i] == "-init"){
            string source = argv[i+1];
            cout<<"Initializing from: "<<source<<endl;
            string cmd;
            ifstream fs{source};
            vector<string> temp;
            while(getline(fs, cmd)) {
                temp.emplace_back(cmd);
            }
            while(!temp.empty()){
                preInitArguments.emplace_back(temp.back());
                temp.pop_back();
            }
            i++;
        }
        if(argv[i] == "-testing"){
            board->enterTesting();
        }
        if(argv[i] == "-graphics"){
            board->enterGraphics();
        }
    }
    string cmd;
    int start = 0;
    board->setCurrentPlayer(player1);
    while(!preInitArguments.empty()){
        if(start == 0){
            player1->giveName(preInitArguments.back());
            preInitArguments.pop_back();
            start++;
            continue;
        } else if(start == 1){
            player2->giveName(preInitArguments.back());
            preInitArguments.pop_back();
            start++;
            continue;
        } else {
            string cmd = preInitArguments.back();
            if(start == 0){
                player1->giveName(cmd);
                start++;
                continue;
            } else if(start == 1){
                player2->giveName(cmd);
                start++;
                continue;
            }
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
                board->checkTrigger(TriggerType::endOfTurn);
                board->switchCurrentPlayer();
                board->print();
                board->checkTrigger(TriggerType::startOfTurn);
            } else if(cmd == "quit"){
                cout<<"That's a TIE!"<<endl;
                return 0;
            } else if(cmd == "draw"){
                try{
                    board->draw();
                }
                catch(InvalidCommandException e) {
                    e.prettyprint();
                }
            } else if(cmd == "hand"){
                board->printHand();
            } else if(cmd == "board"){
                board->print();
            } else {
                istringstream iss {cmd};
                string temp;
                iss>>temp;
                if(temp == "attack"){
                    int attacker = 0,player = 0,defender = 0;
                    iss>>attacker;
                    bool i = (bool)iss>>player;
                    bool j = (bool)iss>>defender;
                    if(i&&j){
                        board->attack(attacker, defender);
                    } else if(i){
                        cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                    } else {
                        board->attack(attacker);
                    }
                } else if(temp == "play"){
                    int cardNum = 0, playerNum = 0, targetNum = 0;
                    iss>>cardNum;
                    bool i = (bool)iss>>playerNum;
                    bool j = (bool)iss>>targetNum;
                    if(i&&j){
                        if(playerNum == 1){
                            board->play(cardNum, player1, targetNum);
                        } else {
                            board->play(cardNum, player2, targetNum);
                        }
                    } else if(i){
                        cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                    } else {
                        board->play(cardNum);
                    }
                } else if(temp == "use"){
                    int cardNum = 0, playerNum = 0, targetNum = 0;
                    iss>>cardNum;
                    bool i = (bool)iss>>playerNum;
                    bool j = (bool)iss>>targetNum;
                    if(i&&j){
                        if(playerNum == 1){
                            board->useAbility(cardNum, player1, targetNum);
                        } else {
                            board->useAbility(cardNum, player2, targetNum);
                        }
                    } else if(i){
                        cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                    } else {
                        board->useAbility(cardNum);
                    }
                } else if(temp == "inspect"){
                    int cardNum;
                    iss>>cardNum;
                    board->inspect(cardNum);
                } else if(temp == "discard"){
                    int cardNum;
                    iss>>cardNum;
                    try{
                        board->discard(cardNum);
                    }
                    catch(InvalidCommandException e){
                        e.prettyprint();
                    }
                } else {
                    cerr << "Invalid command, too see command help page please type \"help\"" << endl;
                    continue;
                }
            }
            preInitArguments.pop_back();
        }
    }
    if(start == 0){
        cout<<"please enter player1's name: ";
        getline(cin,cmd);
        player1->giveName(cmd);
        start++;
    }
    if(start == 1){
        cout<<"please enter player2's name: ";
        getline(cin, cmd);
        player2->giveName(cmd);
        start++;
        player1->draw();
        player1->draw();
        player1->draw();
        player2->draw();
        player2->draw();
        player2->draw();
    }
    cout<<player1->getName()<< ": ";
    shared_ptr<Player> current = player1;
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
            board->checkTrigger(TriggerType::endOfTurn);
            board->switchCurrentPlayer();
            for (int i = 0; i < (CENTRE_GRAPHIC.at(0).length()/EXTERNAL_BORDER_CHAR_LEFT_RIGHT.size()); ++i) {
                cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
            }
            cout<<endl;
            current = current->getOpponent();
            current->addMagicCap();
            board->checkTrigger(TriggerType::startOfTurn);
            try{
                current->draw();
            }
            catch(int e){
                cout<<"There is no more card in your deck!"<<endl;
            }
        } else if(cmd == "quit"){
            cout<<"That's a TIE!"<<endl;
            return 0;
        } else if(cmd == "draw"){
            try{
                board->draw();
            }
            catch(int e) {
                cout<<"There is no more card in your deck!"<<endl;
            }
        } else if(cmd == "hand"){
            board->printHand();
        } else if(cmd == "board"){
            board->print();
        } else {
            istringstream iss {cmd};
            string temp;
            iss>>temp;
            if(temp == "attack"){
                int attacker = 0,player = 0,defender = 0;
                iss>>attacker;
                iss>>player;
                iss>>defender;
                if(player&&defender){
                    board->attack(attacker, defender);
                } else if(player){
                    cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                } else {
                    board->attack(attacker);
                }
            } else if(temp == "play"){
                int cardNum = 0, playerNum = 0, targetNum = 0;
                iss>>cardNum;
                iss>>playerNum;
                iss>>targetNum;
                cout<<playerNum<<targetNum<<endl;
                if(playerNum&&targetNum){
                    try{
                        if(playerNum == 1){
                            board->play(cardNum, player1, targetNum);
                        } else {
                            board->play(cardNum, player2, targetNum);
                        }
                    }
                    catch(InvalidCommandException e){
                        e.prettyprint();
                    }
                } else if(playerNum){
                    cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                } else {
                    cout<<"here"<<endl;
                    try{
                        board->play(cardNum);
                    }
                    catch(InvalidCommandException e){
                        e.prettyprint();
                    }
                }
            } else if(temp == "use"){
                int cardNum = 0, playerNum = 0, targetNum = 0;
                iss>>cardNum;
                iss>>playerNum;
                iss>>targetNum;
                if(playerNum&&targetNum){
                    if(playerNum == 1){
                        board->useAbility(cardNum, player1, targetNum);
                    } else {
                        board->useAbility(cardNum, player2, targetNum);
                    }
                } else if(playerNum){
                    cerr<<"Invalid number/type of Commands. Type \"-help\" for more help on Commands"<<endl;
                } else {
                    board->useAbility(cardNum);
                }
            } else if(temp == "inspect"){
                int cardNum;
                iss>>cardNum;
                board->inspect(cardNum);
            } else if(temp == "discard"){
                int cardNum;
                iss>>cardNum;
                try{
                    board->discard(cardNum);
                }
                catch(InvalidCommandException e){
                    e.prettyprint();
                }
            } else {
                cerr << "Invalid command, too see command help page please type \"help\"" << endl;
            }
        }
        cout<<current->getName()<<": ";
    }
}
