#include "enchantment.h"

void playCard() ;
void editAttack(int i) {}
void editHealth(int i) {}
void addEnchantment(std::unique_ptr<Enchantment> &enchantment) ;
void cast(std::unique_ptr<Player> &player, int i) ;
void inspect() ;
void print(bool) = 0;
std::string getDescription() {
    if (name == "Giant Strength") {
}

int getHealth() ;
void editHealth(int) ;
int getMagic() {
    
}

void editMagic(int) {
    
}

int getAttack() ;
void editAttack(int) ;
int getCost() ;
void editCost(int) ;
int getUsage() ;
void editUsage(int) ;
Info getInfo() ;
bool died() ;
