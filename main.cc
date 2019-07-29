#include <fstream>
#include <sstream>
#include "board.h"

using namespace std;

void loadDeck(shared_ptr<Player> player, vector<shared_ptr<Card>>& deck, std::string filename) {
	deck.clear();
	vector<shared_ptr<Card>> temp;
	ifstream deckfile{ filename };
	string cardName;
	while (getline(deckfile, cardName)) {
		if (cardName == "Air Elemental") temp.emplace_back(make_shared<Minion>(Minion{ "Air Elemental", player }));
		if (cardName == "Earth Elemental") temp.emplace_back(make_shared<Minion>(Minion{ "Earth Elemental", player }));
		if (cardName == "Bone Golem") temp.emplace_back(make_shared<Minion>(Minion{ "Bone Golem", player }));
		if (cardName == "Fire Elemental") temp.emplace_back(make_shared<Minion>(Minion{ "Fire Elemental", player }));
		if (cardName == "Potion Seller") temp.emplace_back(make_shared<Minion>(Minion{ "Potion Seller", player }));
		if (cardName == "Novice Pyromancer") temp.emplace_back(make_shared<Minion>(Minion{ "Novice Pyromancer", player }));
		if (cardName == "Apprentice Summoner") temp.emplace_back(make_shared<Minion>(Minion{ "Apprentice Summoner", player }));
		if (cardName == "Master Summoner") temp.emplace_back(make_shared<Minion>(Minion{ "Master Summoner", player }));
		if (cardName == "Banish") temp.emplace_back(make_shared<Spell>(Spell{ "Banish", player }));
		if (cardName == "Unsummon") temp.emplace_back(make_shared<Spell>(Spell{ "Unsummon", player }));
		if (cardName == "Recharge") temp.emplace_back(make_shared<Spell>(Spell{ "Recharge", player }));
		if (cardName == "Disenchant") temp.emplace_back(make_shared<Spell>(Spell{ "Disenchant", player }));
		if (cardName == "Raise Dead") temp.emplace_back(make_shared<Spell>(Spell{ "Raise Dead", player }));
		if (cardName == "Blizzard") temp.emplace_back(make_shared<Spell>(Spell{ "Blizzard", player }));
		if (cardName == "Giant Strength") temp.emplace_back(make_shared<Enchantment>(Enchantment{ "Giant Strength", player }));
		if (cardName == "Enrage") temp.emplace_back(make_shared<Enchantment>(Enchantment{ "Enrage", player }));
		if (cardName == "Haste") temp.emplace_back(make_shared<Enchantment>(Enchantment{ "Haste", player }));
		if (cardName == "Magic Fatigue") temp.emplace_back(make_shared<Enchantment>(Enchantment{ "Magic Fatigue", player }));
		if (cardName == "Silence") temp.emplace_back(make_shared<Enchantment>(Enchantment{ "Silence", player }));
		if (cardName == "Dark Ritual") temp.emplace_back(make_shared<Ritual>(Ritual{ "Dark Ritual", player }));
		if (cardName == "Aura of Power") temp.emplace_back(make_shared<Ritual>(Ritual{ "Aura of Power", player }));
		if (cardName == "Standstill") temp.emplace_back(make_shared<Ritual>(Ritual{ "Standstill", player }));
	}
	while (!temp.empty()) {
		deck.emplace_back(temp.back());
		temp.pop_back();
	}
}

int main(int argc, char* argv[]) {
	vector<shared_ptr<Card>> deck1;
	vector<shared_ptr<Card>> deck2;
	shared_ptr<Player> player1 = make_shared<Player>(Player{ deck1, "" });
	shared_ptr<Player> player2 = make_shared<Player>(Player{ deck2, "" });
	deck1.push_back(make_shared<Ritual>(Ritual{ "Aura of Power", player1 }));
	deck1.push_back(make_shared<Minion>(Minion{ "Bone Golem", player1 }));
    deck1.push_back(make_shared<Minion>(Minion{ "Fire Elemental", player1 }));
    deck1.push_back(make_shared<Spell>(Spell{ "Blizzard", player1 }));
	player1->giveDeck(deck1);
	deck2.push_back(make_shared<Minion>(Minion{ "Bone Golem", player2 }));
	deck2.push_back(make_shared<Spell>(Spell{ "Unsummon", player2 }));
    deck2.push_back(make_shared<Spell>(Spell{ "Raise Dead", player2 }));
    deck2.push_back(make_shared<Enchantment>(Enchantment{ "Haste", player2 }));
    deck2.push_back(make_shared<Enchantment>(Enchantment{ "Silence", player2 }));
    deck2.push_back(make_shared<Spell>(Spell{ "Raise Dead", player2 }));
	player2->giveDeck(deck2);
	shared_ptr<Board> board = make_shared<Board>(Board{ player1, player2 });
	player1->setOpponent(player2);
	player2->setOpponent(player1);
	shared_ptr<Player> current = player1;
	vector<string> preInitArguments;
    bool graphic = false;
    shared_ptr<Xwindow> window = nullptr;
	for (int i = 1; i < argc; i++) {
		string cmd = argv[i];
		if (cmd == "-deck1") {
			cout << "Loading deck from: " << argv[i + 1] << endl;
			loadDeck(player1, deck1, argv[i + 1]);
			player1->giveDeck(deck1);
			i++;
		}
		if (cmd == "-deck2") {
			cout << "Loading deck from: " << argv[i + 1] << endl;
			loadDeck(player2, deck2, argv[i + 1]);
			player2->giveDeck(deck2);
			i++;
		}
		if (cmd == "-init") {
			string source = argv[i + 1];
			cout << "Initializing from: " << source << endl;
			string cmd;
			ifstream fs{ source };
			vector<string> temp;
			while (getline(fs, cmd)) {
				temp.emplace_back(cmd);
			}
			while (!temp.empty()) {
				preInitArguments.emplace_back(temp.back());
				temp.pop_back();
			}
			i++;
		}
		if (cmd == "-testing") {
			board->enterTesting();
		}
		if (cmd == "-graphics") {
			board->enterGraphics();
            graphic = true;
		}
	}
    player1->shuffleDeck();
	player2->shuffleDeck();
	string cmd;
	int start = 0;
	board->setCurrentPlayer(player1);
	while (!preInitArguments.empty()) {
		string cmd = preInitArguments.back();
		if (start == 0) {
			player1->giveName(cmd);
			start++;
			continue;
		}
		if (start == 1) {
			player2->giveName(cmd);
			start++;
			player1->draw();
			player1->draw();
			player1->draw();
			player2->draw();
			player2->draw();
            if(graphic){
                window = make_shared<Xwindow>(Xwindow{1400,900});
                board->printGraphics(*window);
            }
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
		}
		else if (cmd == "end") {
			board->checkTrigger(TriggerType::endOfTurn);
			board->switchCurrentPlayer();
			for (int i = 0; i < (CENTRE_GRAPHIC.at(0).length() / EXTERNAL_BORDER_CHAR_LEFT_RIGHT.size()); ++i) {
				cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
			}
			cout << endl;
            current->resumeAction();
			current = current->getOpponent();
			current->addMagicCap();
			board->checkTrigger(TriggerType::startOfTurn);
            board->printGraphics(*window);
			try {
				current->draw();
			}
			catch (int e) {
				if (e == 3) {
					cout << "There is no more card in your deck!" << endl;
				}
				else if (e == 1) {
					cout << "You already have 5 cards in your hand!" << endl;
				}
			}
		}
		else if (cmd == "quit") {
			cout << "GG!" << endl;
			return 0;
		}
		else if (cmd == "draw") {
			try {
				board->draw();
			}
			catch (int e) {
				if (e == 3) {
					cout << "There is no more card in your deck!" << endl;
				}
				else if (e == 1) {
					cout << "You already have 5 cards in your hand!" << endl;
				}
			}
		}
		else if (cmd == "hand") {
			board->printHand();
		}
		else if (cmd == "board") {
			board->print();
            board->printGraphics(*window);
		}
		else {
			istringstream iss{ cmd };
			string temp;
			iss >> temp;
			if (temp == "attack") {
				int attacker = 0, player = 0, defender = 0;
				iss >> attacker;
				iss >> player;
				iss >> defender;
				if (player && defender) {
					board->attack(attacker, defender);
				}
				else if (player) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					board->attack(attacker);
				}
                board->printGraphics(*window);
			}
			else if (temp == "play") {
				int cardNum = 0, playerNum = 0, targetNum = 0;
				iss >> cardNum;
				iss >> playerNum;
				iss >> targetNum;
				if (playerNum && targetNum) {
					try {
						if (playerNum == 1) {
							board->play(cardNum, player1, targetNum);
						}
						else {
							board->play(cardNum, player2, targetNum);
						}
					}
					catch (InvalidCommandException e) {
						e.prettyprint();
					}
				}
				else if (playerNum) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					try {
						board->play(cardNum);
					}
					catch (InvalidCommandException e) {
						e.prettyprint();
					}
				}
                board->printGraphics(*window);
			}
			else if (temp == "use") {
				int cardNum = 0, playerNum = 0, targetNum = 0;
				iss >> cardNum;
				iss >> playerNum;
				iss >> targetNum;
				if (playerNum && targetNum) {
					if (playerNum == 1) {
						board->useAbility(cardNum, player1, targetNum);
					}
					else {
						board->useAbility(cardNum, player2, targetNum);
					}
				}
				else if (playerNum) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					board->useAbility(cardNum);
				}
                board->printGraphics(*window);
			}
			else if (temp == "inspect") {
				int cardNum;
				iss >> cardNum;
				board->inspect(cardNum);
			}
			else if (temp == "discard") {
				int cardNum;
				iss >> cardNum;
				try {
					board->discard(cardNum);
				}
				catch (InvalidCommandException e) {
					e.prettyprint();
				}
                board->printGraphics(*window);
			}
			else {
				cerr << "Invalid command, too see command help page please type \"help\"" << endl;
			}
		}
		preInitArguments.pop_back();
	}
	if (start == 0) {
		cout << "please enter player1's name: ";
		getline(cin, cmd);
		player1->giveName(cmd);
		start++;
	}
	if (start == 1) {
		cout << "please enter player2's name: ";
		getline(cin, cmd);
		player2->giveName(cmd);
		start++;
		player1->draw();
		player1->draw();
		player1->draw();
		player2->draw();
		player2->draw();
        if(graphic){
            window = make_shared<Xwindow>(Xwindow{1400,900});
            board->printGraphics(*window);
        }
	}
	cout << player1->getName() << ": ";
	bool graphics = board->isGraphics();
	while (getline(cin, cmd)) {
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
		}
		else if (cmd == "end") {
			board->checkTrigger(TriggerType::endOfTurn);
			board->switchCurrentPlayer();
			for (int i = 0; i < (CENTRE_GRAPHIC.at(0).length() / EXTERNAL_BORDER_CHAR_LEFT_RIGHT.size()); ++i) {
				cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
			}
			cout << endl;
            current->resumeAction();
			current = current->getOpponent();
			current->addMagicCap();
			board->checkTrigger(TriggerType::startOfTurn);
			try {
				current->draw();
			}
			catch (int e) {
				if (e == 3) {
					cout << "There is no more card in your deck!" << endl;
				}
				else if (e == 1) {
					cout << "You already have 5 cards in your hand!" << endl;
				}
			}
            board->printGraphics(*window);
		}
		else if (cmd == "quit") {
			cout << "GG!" << endl;
			return 0;
		}
		else if (cmd == "draw") {
			try {
				board->draw();
			}
			catch (int e) {
				if (e == 3) {
					cout << "There is no more card in your deck!" << endl;
				}
				else if (e == 1) {
					cout << "You already have 5 cards in your hand!" << endl;
				}
			}
            board->printGraphics(*window);
		}
		else if (cmd == "hand") {
			board->printHand();
		}
		else if (cmd == "board") {
			board->print();
            board->printGraphics(*window);
		}
		else {
			istringstream iss{ cmd };
			string temp;
			iss >> temp;
			if (temp == "attack") {
				int attacker = 0, player = 0, defender = 0;
				iss >> attacker;
				iss >> player;
				iss >> defender;
				if (player && defender) {
					board->attack(attacker, defender);
				}
				else if (player) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					board->attack(attacker);
					if (current->getOpponent()->died()) {
						cout << "Congratulation, " << current->getName() << " ! You have defeated your opponent!" << std::endl;
						return 0;
					}
				}
                board->printGraphics(*window);
			}
			else if (temp == "play") {
				int cardNum = 0, playerNum = 0, targetNum = 0;
				iss >> cardNum;
				iss >> playerNum;
				iss >> targetNum;
				if (playerNum && targetNum) {
					try {
						if (playerNum == 1) {
							board->play(cardNum, player1, targetNum);
						}
						else {
							board->play(cardNum, player2, targetNum);
						}
					}
					catch (InvalidCommandException e) {
						e.prettyprint();
					}
				}
				else if (playerNum) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					try {
						board->play(cardNum);
					}
					catch (InvalidCommandException e) {
						e.prettyprint();
					}
				}
                board->printGraphics(*window);
			}
			else if (temp == "use") {
				int cardNum = 0, playerNum = 0, targetNum = 0;
				iss >> cardNum;
				iss >> playerNum;
				iss >> targetNum;
				if (playerNum && targetNum) {
					if (playerNum == 1) {
						board->useAbility(cardNum, player1, targetNum);
					}
					else {
						board->useAbility(cardNum, player2, targetNum);
					}
				}
				else if (playerNum) {
					cerr << "Invalid number/type of Commands. Type \"-help\" for more help on Commands" << endl;
				}
				else {
					board->useAbility(cardNum);
				}
                board->printGraphics(*window);
			}
			else if (temp == "inspect") {
				int cardNum;
				iss >> cardNum;
				board->inspect(cardNum);
			}
			else if (temp == "discard") {
				int cardNum;
				iss >> cardNum;
				try {
					board->discard(cardNum);
				}
				catch (InvalidCommandException e) {
					e.prettyprint();
				}
                board->printGraphics(*window);
			}
			else {
				cerr << "Invalid command, too see command help page please type \"help\"" << endl;
			}
		}
		cout << current->getName() << ": ";
	}
}
