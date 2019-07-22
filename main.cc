#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;

int main(int argc, char *argv[]){
    unique_ptr<Deck> deck1 = std::make_unique<Deck>(Deck{});
    unique_ptr<Deck> deck2 = std::make_unique<Deck>(Deck{});
    unique_ptr<Player> player1 = std::make_unique<Player>(Player{});
    unique_ptr<Player> player2 = std::make_unique<Player>(Player{});
    unique_ptr<Board> boardPtr = std::make_unique<Board>(Board{});
    int i = 1;
    while(i<argc){
        if(argv[i] == "-deck1"){
            string filename = argv[i+1];
            i++;
            ifstream ifs{filename};
            string cardName;
            while(ifs>>cardName){
                
            }
        }
    }
}
