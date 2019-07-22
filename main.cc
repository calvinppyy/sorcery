#include <iostream>
#include <fstream>
#include <string>
#include "board.h"

using namespace std;

int main(int argc, char *argv[]){
    std::unique_ptr<Board> boardPtr = new Board{};
    int temp = 1;
    while(temp<argc){
        if(argv[temp] == "-deck1"){
            string filename = argv[temp+1];
            temp++;
            ifstream ifs{filename};
            string cardName;
            while(ifs>>cardName){
                
            }
        }
    }
}
