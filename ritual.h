#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "player.h"

class Ritual: public Card{
    int playCost, usage, usageCap;
    TriggerType triggerType;
public:
    Ritual(std::string name, std::shared_ptr<Player> owner);
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
    int getDefenceCap();
    bool died();
    void checkTrigger(TriggerType trigger,Player& opponent, int index);
    void setAction(int action);
    void editActionCap(int action);
    int getActionCap();
    ~Ritual(){}
};

#endif
