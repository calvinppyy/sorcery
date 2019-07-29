#include "card.h"

Card::Card(std::string name, std::shared_ptr<Player> owner) : name{name}, triggerType{TriggerType::noTrigger}, owner{owner} {}

std::string Card::getName(){
    return name;
}

void printCard(Xwindow &temp, std::shared_ptr<Card> card, int x,int y, int colour){
    std::string name = card->getName();
    if(name == "Air Elemental"|| name == "Earth Elemental"){
        int attack = card->getAttack();
        int defence = card->getDefence();
        int cost = card->getPlayCost();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Minion");
        temp.drawLine(x, y+100, x+35, y+100);
        temp.drawLine(x+35, y+100, x+35, y+119);
        temp.drawLine(x+166, y+100, x+200, y+100);
        temp.drawLine(x+166, y+100, x+166, y+119);
        temp.drawString(x+13, y+112, std::to_string(attack));
        temp.drawString(x+179, y+112, std::to_string(defence));
        temp.drawString(x+179, y+12, std::to_string(cost));
        for(int i = 0; i*31 < description.length(); i++){
            if(description.length()-i*31>31){
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,31));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,description.length()-i*31));
            }
        }
    } else if(name == "Apprentice Summoner"||name == "Novice Pyromancer"
              || name == "Master Summoner"){
        int attack = card->getAttack();
        int defence = card->getDefence();
        int cost = card->getPlayCost();
        int active = card->getAbilityCost();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Minion");
        temp.drawString(x+179, y+12, std::to_string(cost));
        
        temp.drawLine(x, y+100, x+35, y+100);
        temp.drawLine(x+35, y+100, x+35, y+119);
        temp.drawString(x+13, y+112, std::to_string(attack));
        
        temp.drawLine(x+166, y+100, x+200, y+100);
        temp.drawLine(x+166, y+100, x+166, y+119);
        temp.drawString(x+179, y+112, std::to_string(defence));
        
        temp.drawLine(x, y+60, x+35, y+60);
        temp.drawLine(x+35, y+40, x+35, y+60);
        temp.drawString(x+13, y+52, std::to_string(active));
        for(int i = 0; i*26 < description.length(); i++){
            if(description.length()-i*26>26){
                temp.drawString(x+8, y+52+i*12, description.substr(i*26,26));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*26,description.length()-i*26));
            }
        }
    } else if(name == "Giant Strength" || name == "Enrage"){
        int cost = card->getPlayCost();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Enchantment");
        temp.drawLine(x, y+100, x+35, y+100);
        temp.drawLine(x+35, y+100, x+35, y+119);
        temp.drawLine(x+166, y+100, x+200, y+100);
        temp.drawLine(x+166, y+100, x+166, y+119);
        if(name == "Giant Strength"){
            temp.drawString(x+13, y+112, "+2");
        } else {
            temp.drawString(x+13, y+112, "*2");
        }
        if(name == "Giant Strength"){
            temp.drawString(x+179, y+112, "+2");
        } else {
            temp.drawString(x+179, y+112, "*2");
        }
        temp.drawString(x+179, y+12, std::to_string(cost));
    } else if(name == "Bone Golem"||name == "Fire Elemental"||"Potion Seller"){
        int attack = card->getAttack();
        int defence = card->getDefence();
        int cost = card->getPlayCost();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Minion");
        temp.drawString(x+179, y+12, std::to_string(cost));
        
        temp.drawLine(x, y+100, x+35, y+100);
        temp.drawLine(x+35, y+100, x+35, y+119);
        temp.drawString(x+13, y+112, std::to_string(attack));
        
        temp.drawLine(x+166, y+100, x+200, y+100);
        temp.drawLine(x+166, y+100, x+166, y+119);
        temp.drawString(x+179, y+112, std::to_string(defence));
        for(int i = 0; i*31 < description.length(); i++){
            if(description.length()-i*31>31){
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,31));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,description.length()-i*31));
            }
        }
    } else if(name == "Haste"||name == "Magic Fatigue"||
              name == "Silence"){
        int cost = card->getPlayCost();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Enchantment");
        temp.drawString(x+179, y+12, std::to_string(cost));
        for(int i = 0; i*31 < description.length(); i++){
            if(description.length()-i*31>31){
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,31));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,description.length()-i*31));
            }
        }
    } else if(name == "Dark Ritual" || name == "Aura of Power"||
              name == "Standstill"){
        int usage = card->getUsage();
        int cost = card->getPlayCost();
        int cap = card->getUsageCap();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Ritual");
        temp.drawString(x+179, y+12, std::to_string(cost));
        
        temp.drawLine(x+166, y+100, x+200, y+100);
        temp.drawLine(x+166, y+100, x+166, y+119);
        temp.drawString(x+179, y+112, std::to_string(usage));
        
        temp.drawLine(x, y+60, x+35, y+60);
        temp.drawLine(x+35, y+40, x+35, y+60);
        temp.drawString(x+13, y+52, std::to_string(cap));
        for(int i = 0; i*26 < description.length(); i++){
            if(description.length()-i*26>26){
                temp.drawString(x+8, y+52+i*12, description.substr(i*26,26));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*26,description.length()-i*26));
            }
        }
    } else {
        int cost = card->getPlayCost();
        std::string description = card->getDescription();
        temp.fillRectangle(x, y , 201, 120, colour);
        temp.drawLine(x, y+20, x+200, y+20);
        temp.drawString(x+5, y+12, name);
        temp.drawLine(x, y+40, x+200, y+40);
        temp.drawLine(x+170, y, x+170, y+20);
        temp.drawString(x+135, y+32, "Spell");
        temp.drawString(x+179, y+12, std::to_string(cost));
        for(int i = 0; i*31 < description.length(); i++){
            if(description.length()-i*31>31){
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,31));
            } else {
                temp.drawString(x+8, y+52+i*12, description.substr(i*31,description.length()-i*31));
            }
        }
    }
}
