#include "cardgraphics.h"

void printCard(Xwindow &temp, std::shared_ptr<Card> card, int x,int y, int colour){
    std::string name = card->getName();
    if(name == "Air Elemental"|| name == "Earth Elemental"){
        int attack = card->getAttack();
        int defence = card->getDefence();
        int cost = card->getPlayCost();
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
    } else if(name == "Apprentice Summoner"||name == "Novice Pyromancer"
              || name == "Master Summoner"){
        int attack = card->getAttack();
        int defence = card->getDefence();
        int cost = card->getPlayCost();
        int active = card->getAbilityCost();
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
    }
}
