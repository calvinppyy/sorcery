#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "player.h"
#include "enchantment.h"

class Enchantment;

class Minion : public Card{
    int attack, defence,defenceCap, playCost, abilityCost, action,actionCap;
    bool silenced;
    std::vector<std::shared_ptr<Enchantment>> enchantments;
    
public:
    Minion(std::string name);
    void silence(bool);
    void playCard(std::shared_ptr<Player> target, int index);
    void addEnchantment(std::shared_ptr<Enchantment> echantment);
    void popEnchantment();
    void clearEnchantment();
    void cast(Player& opponent, int index);
    void inspect(bool graphicsEnabled);
    std::string getDescription();
    int getDefence();
    void editDefence(int defence);
    int getPlayCost();
    void editPlayCost(int playCost);
    int getAttack();
    void editAttack(int attack);
    int getAbilityCost(); //ritual, minion
    void editAbilityCost(int ac); //ritual minion
    int getUsage(); //for ritual
    void editUsage(int); //for ritual
    int getAction();
    void editAction(int action);
    int getUsageCap();
    bool died();
    void checkTrigger(TriggerType trigger,Player& opponent, int index);
    int getDefenceCap();
    void setAction(int action);
    void editActionCap(int action);
    int getActionCap();
    ~Minion(){}
};

#endif
