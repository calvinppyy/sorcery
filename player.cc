#include "player.h"

using namespace std;

Player::Player(vector<shared_ptr<Card>> notOut, string name)
{
    this->name = name;
    this->notOut = notOut;
    health = 20;
    magic = 1;
    magicCap = 1;
}

Player::~Player() {}

void Player::giveName(string name)
{
    this->name = name;
}

void Player::setOpponent(shared_ptr<Player> opponent)
{
    this->opponent = opponent;
}

void Player::giveDeck(vector<shared_ptr<Card>> deck, string what)
{
    if(what == "hand"){
        hand = deck;
    } else {
        this->notOut = deck;
    }
}

bool Player::died()
{
    return this->health <= 0;
}

shared_ptr<Card>& Player::getIthMinion(int index)
{
    if (index == 6)
        return this->ritual;
    return this->minions.at(index - 1);
}

void Player::playCard(int index, bool testing)
{
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            this->editMagic(-1*this->magic);
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
        {
            throw 1;
        }
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    if (dynamic_pointer_cast<Enchantment>(this->hand.at((index - 1))) == nullptr &&
        dynamic_pointer_cast<Spell>(this->hand.at((index - 1))) == nullptr)
    {
        if (dynamic_pointer_cast<Ritual>(this->hand.at((index - 1))) == nullptr)
        {
            if (this->minions.size() < 5)
            {
                this->minions.emplace_back(this->hand.at((index - 1)));
                this->hand.erase(this->hand.begin() + (index - 1));
                int k = 0;
                try{
                    this->checkTrigger(TriggerType::allyEnter, *this, this->minions.size());
                }
                catch(int e){
                    if(e==456) k =1;
                }
                if(k!=1) this->getOpponent()->checkTrigger(TriggerType::enemyEnter, *this, this->minions.size());
            } else {
                std::cerr << "You already have five minions!"<<std::endl;
            }
        }
        else
        {
            this->ritual = this->hand.at((index - 1));
            this->hand.erase(this->hand.begin() + (index - 1));
        }
    }
    else
    {
        try {
            int i = 0;
            try{
            this->hand.at((index - 1))->playCard(getOpponent()->getOpponent(), index);
            }
            catch(int e){
                if (e == 345) i = 1;
            }
            if(i!=1) this->hand.erase(this->hand.begin() + (index - 1));
        }
        catch (string e) {
            cerr << e << endl;
        }
    }
} //bool is for testing mode

void Player::playCard(int index, shared_ptr<Player> target, int targetIndex, bool testing)
{
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            this->editMagic(-1 * this->magic);
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            throw 'a';
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    if (dynamic_pointer_cast<Enchantment>(this->hand.at((index - 1))) == nullptr &&
        dynamic_pointer_cast<Spell>(this->hand.at((index - 1))) == nullptr)
    {
        if (dynamic_pointer_cast<Ritual>(this->hand.at((index - 1))) == nullptr)
        {
            if (this->minions.size() < 5)
            {
                this->minions.emplace_back(this->hand.at((index - 1)));
                this->minions.erase(this->minions.begin() + (index - 1));
                int k = 0;
                try{
                    this->checkTrigger(TriggerType::allyEnter, *this, this->minions.size());
                }
                catch(int e){
                    if(e==456) k =1;
                }
                if(k!=1) this->getOpponent()->checkTrigger(TriggerType::enemyEnter, *this, this->minions.size());
            }
            else {
                std::cerr << "You already have five minions!"<<std::endl;
            }
        }
        else
        {
            this->ritual = this->hand.at((index - 1));
            this->hand.erase(this->hand.begin() + (index - 1));
        }
    }
    else
    {
        try {
            this->hand.at((index - 1))->playCard(target, targetIndex);
            this->hand.erase(this->hand.begin() + (index - 1));
        }
        catch (string e) {
            cerr << e << endl;
        }
    }
}

void Player::useAbility(int index, bool testing)
{
    int tmp;
    if (testing) {
        if (this->magic < this->minions.at((index - 1))->getAbilityCost())
        {
            tmp = this->magic;
            this->editMagic(-1 * this->magic);
        }
        else
        {
            tmp = this->minions.at((index - 1))->getAbilityCost();
            this->editMagic(-1 * this->minions.at((index - 1))->getAbilityCost());
        }
    }
    else {
        if (this->magic < this->minions.at((index - 1))->getAbilityCost()) {
            throw 'a';
        }
        else {
            this->editMagic(-1 * this->minions.at((index - 1))->getAbilityCost());
        }
    }
    try
    {
        this->minions.at((index - 1))->cast(*this, 0);
    }
    catch (char e)
    {
        if (testing)
            this->editMagic(tmp);
        else {
            this->editMagic(this->minions.at((index - 1))->getAbilityCost());
        }
        std::cerr << "You are out of spots!" << std::endl;
    }
    catch (int e) {
        if (testing)
            this->editMagic(tmp);
        else {
            this->editMagic(this->minions.at((index - 1))->getAbilityCost());
        }
        if (e == 9) std::cerr << "The minion is silenced" << std::endl;
        else std::cerr << "This Minion can not attack/use ability anymore this round" << std::endl;
    }
    catch (string e) {
        if (testing)
            this->editMagic(tmp);
        else {
            this->editMagic(this->minions.at((index - 1))->getAbilityCost());
        }
        cerr << e << endl;
    }
} //bool is for testing mode

void Player::useAbility(int index, Player& target, int targetIndex, bool testing)
{
    int tmp;
    if (testing) {
        if (this->magic < this->minions.at((index - 1))->getAbilityCost())
        {
            tmp = this->magic;
            this->editMagic(-1 * this->magic);
        }
        else
        {
            tmp = this->minions.at((index - 1))->getAbilityCost();
            this->editMagic(-1 * this->minions.at((index - 1))->getAbilityCost());
        }
    }
    else
    {
        if (this->magic < this->minions.at((index - 1))->getPlayCost())
            throw 'a';
        else
            this->editMagic(-1 * this->minions.at((index - 1))->getPlayCost());
    }
    try {
        this->minions.at((index - 1))->cast(target, targetIndex);
    }
    catch (int e) {
        std::cerr << "This Minion can not attack/use ability anymore this round" << std::endl;
    }
    catch (string e) {
        if (testing)
            this->editMagic(tmp);
        else {
            this->editMagic(this->minions.at((index - 1))->getAbilityCost());
        }
        cerr << e << endl;
    }
}

void Player::draw()
{
    if (this->countHand() >= 5)  throw 1;
    if (this->notOut.empty())
        throw 3;
    this->hand.emplace_back(this->notOut.back());
    this->notOut.pop_back();
}

void Player::discard(int index)
{
    if (index == 6)
        this->ritual = nullptr;
    this->hand.erase(this->hand.begin() + (index - 1));
}

void Player::inspect(int index, bool testing)
{
    this->minions.at(index - 1)->inspect(testing);
}

void Player::shuffleDeck()
{
    //auto rng = default_random_engine();
    random_shuffle(this->notOut.begin(), this->notOut.end()); //DELETE THE RNG CLASS IF THIS WORKS, USED <algorithm> && <random>, INCLUDED IN player.h
}

void Player::takeAttack(int damage)
{
    this->health -= damage;
} //agianst player

void Player::attack(int index)
{
    if (minions.at(index - 1)->getAction() > 0) {
        this->getOpponent()->takeAttack(this->minions.at(index - 1)->getAttack());
        minions.at(index - 1)->editAction(-1);
    }
    else {
        std::string e = "This Minion can not attack anymore this round";
        throw e;
    }
} // against player

void Player::takeAttack(int enemyIndex, int damage, int index, int attackType)
{
    this->minions.at(index - 1)->editDefence(-1 * damage);
    if (attackType == 0)
    {
        this->attack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, 1);
    }
    if (this->minions.at(index - 1)->getDefence() <= 0)
    {
        this->killMinion((index));
        try{
            this->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
            this->getOpponent()->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
        }
        catch(int e){}
    }
} // against minion, attackType indicates if the minion is actively attacking or counter-attack

void Player::attack(int index, int damage, int enemyIndex, int attackType)
{
    if (minions.at(index - 1)->getAction() > 0) {
        if(attackType == 0){
            minions.at(index - 1)->editAction(-1);
        }
        this->getOpponent()->takeAttack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, attackType);
    }
    else {
        throw 'a';
    }
} // against minion, the 3rd int indicates if the minion is actively attacking or counter-attack

void Player::killMinion(int index)
{
    if(index == 6){
        ritual = nullptr;
        return;
    }
    this->graveyard.emplace_back(this->minions.at(index - 1));
    this->minions.erase(this->minions.begin() + (index - 1));
}

void Player::reviveMinion()
{
    if (this->graveyard.size() == 0) {
        string temp = "There is nothing in the graveyard!";
        throw temp;
    }
    if (this->minions.size() < 5)
    {
        this->minions.emplace_back(this->graveyard.back());
        this->minions.back()->editDefence((-1) * this->minions.back()->getDefence());
        this->minions.back()->editDefence(1);
        int k = 0;
        try{
            this->checkTrigger(TriggerType::allyEnter, *this, this->minions.size());
        }
        catch(int e){
            if(e==456) k =1;
        }
        if(k!=1) this->getOpponent()->checkTrigger(TriggerType::enemyEnter, *this, this->minions.size());
    }
    this->graveyard.pop_back();
}

void Player::allEditDefence(int value)
{
    for (int i = 0; i < this->minions.size(); i++)
    {
        this->minions.at(i)->editDefence(value);
        if (minions.at(i)->died())
        {
            killMinion(i + 1);
            i--;
            try{
                this->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
                this->getOpponent()->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
            }
            catch(int e){}
        }
    }
}

void Player::checkTrigger(TriggerType type, Player& player, int index)
{
    for (int i = 0; i < this->minions.size(); i++)
    {
        this->minions.at(i)->checkTrigger(type, player, index);
    }
    if (this->ritual)
    {
        try {
            this->ritual->checkTrigger(type, player, index);
        }
        catch (string e) {
            if (e == "The ritual has used up its usage cap") {
                cerr << e << endl;
            }
        }
    }
}

void Player::summonCard(int count, string name)
{
    for (int i = 0; i < count; i++)
    {
        if (this->minions.size() == 5)
            return;
        this->minions.emplace_back(make_shared<Minion>(name, make_shared<Player>(*this)));
        int k = 0;
        try{
            this->checkTrigger(TriggerType::allyEnter, *this, this->minions.size());
        }
        catch(int e){
            if(e==456) k =1;
        }
        if(k!=1) this->getOpponent()->checkTrigger(TriggerType::enemyEnter, *this, this->minions.size());
    }
}

shared_ptr<Player>& Player::getOpponent()
{
    std::shared_ptr<Player> temp = this->opponent.lock();
    return temp;
}

void Player::editMagic(int value)
{
    this->magic += value;
}

void Player::addMagicCap()
{
    magicCap++;
    magic = magicCap;
}

void Player::unsummonCard(int index)
{
    minions.at(index - 1)->clearEnchantment();
    if (this->hand.size() < 5)
    {
        this->hand.emplace_back(this->minions.at(index - 1));
    }
    this->minions.erase(this->minions.begin() + (index - 1));
    try{
        this->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
        this->getOpponent()->checkTrigger(TriggerType::minionLeave, *this, this->minions.size());
    }
    catch(int e){}
}

void Player::editRitualUsage(int value)
{
    if (this->ritual == nullptr)
        return;
    this->ritual->editUsage(value);
}

int Player::countMinions()
{
    return this->minions.size();
}

void Player::printCards(bool graphics, std::string w)
{
    if (!graphics)
    {
        vector<card_template_t> temp;
        std::vector<std::shared_ptr<Card>> what;
        if (w == "hand")
        {
            what = hand;
        }
        else
        {
            what = minions;
        }
        for (int i = 0; i < what.size(); i++)
        {
            std::shared_ptr<Card> temp2 = what.at(i);
            temp.push_back(whichFunc(temp2));
        }
        for (int j = 0; j < CARD_TEMPLATE_BORDER.size(); ++j)
        {
            if (w != "hand")
                std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
            for (int i = 0; i < 5; ++i)
            {
                if (i < temp.size())
                {
                    std::cout << temp.at(i).at(j);
                }
                else
                {
                    std::cout << CARD_TEMPLATE_BORDER.at(j);
                }
            }
            if (w != "hand")
                std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
            std::cout << std::endl;
        }
    }
}

std::string Player::getName()
{
    return name;
}

void Player::printPlayer(bool graphics, bool current)
{
    if (!graphics)
    {
        std::vector<card_template_t> temp;
        if (ritual)
        {
            temp.push_back(display_ritual(ritual->getName(), ritual->getPlayCost(), ritual->getUsageCap(),
                                          ritual->getDescription(), ritual->getUsage()));
        }
        else
        {
            temp.push_back(CARD_TEMPLATE_BORDER);
        }
        temp.push_back(CARD_TEMPLATE_EMPTY);
        if (current)
        {
            temp.push_back(display_player_card(2, name, health, magic));
        }
        else
        {
            temp.push_back(display_player_card(1, name, health, magic));
        }
        temp.push_back(CARD_TEMPLATE_EMPTY);
        if (graveyard.size() > 0)
        {
            temp.push_back(whichFunc(graveyard.back()));
        }
        else
        {
            temp.push_back(CARD_TEMPLATE_BORDER);
        }
        for (int j = 0; j < CARD_TEMPLATE_BORDER.size(); ++j)
        {
            std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
            for (int i = 0; i < 5; ++i)
            {
                if (i < temp.size())
                {
                    std::cout << temp.at(i).at(j);
                }
                else
                {
                    std::cout << CARD_TEMPLATE_BORDER.at(j);
                }
            }
            std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
            std::cout << std::endl;
        }
    }
    else
    {
    }
}

card_template_t whichFunc(std::shared_ptr<Card> temp2)
{
    std::map<std::string, card_template_t> cardNameToFunc;
    cardNameToFunc["Air Elemental"] = display_minion_triggered_ability(temp2->getName(), temp2->getPlayCost(),
                                                                       temp2->getAttack(), temp2->getDefence(),
                                                                       temp2->getDescription());
    cardNameToFunc["Earth Elemental"] = display_minion_triggered_ability(temp2->getName(), temp2->getPlayCost(),
                                                                         temp2->getAttack(), temp2->getDefence(),
                                                                         temp2->getDescription());
    cardNameToFunc["Bone Golem"] = display_minion_triggered_ability(temp2->getName(), temp2->getPlayCost(),
                                                                    temp2->getAttack(), temp2->getDefence(),
                                                                    temp2->getDescription());
    cardNameToFunc["Fire Elemental"] = display_minion_triggered_ability(temp2->getName(), temp2->getPlayCost(),
                                                                        temp2->getAttack(), temp2->getDefence(),
                                                                        temp2->getDescription());
    cardNameToFunc["Potion Seller"] = display_minion_triggered_ability(temp2->getName(), temp2->getPlayCost(),
                                                                       temp2->getAttack(), temp2->getDefence(),
                                                                       temp2->getDescription());
    cardNameToFunc["Novice Pyromancer"] = display_minion_activated_ability(temp2->getName(), temp2->getPlayCost(),
                                                                           temp2->getAttack(), temp2->getDefence(), temp2->getAbilityCost(),
                                                                           temp2->getDescription());
    cardNameToFunc["Apprentice Summoner"] = display_minion_activated_ability(temp2->getName(), temp2->getPlayCost(),
                                                                             temp2->getAttack(), temp2->getDefence(), temp2->getAbilityCost(),
                                                                             temp2->getDescription());
    cardNameToFunc["Master Summoner"] = display_minion_activated_ability(temp2->getName(), temp2->getPlayCost(),
                                                                         temp2->getAttack(), temp2->getDefence(), temp2->getAbilityCost(),
                                                                         temp2->getDescription());
    cardNameToFunc["Banish"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Unsummon"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Recharge"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Disenchant"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Raise Dead"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Blizzard"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Dark Ritual"] = display_ritual(temp2->getName(), temp2->getPlayCost(), temp2->getUsageCap(),
                                                   temp2->getDescription(), temp2->getUsage());
    cardNameToFunc["Aura of Power"] = display_ritual(temp2->getName(), temp2->getPlayCost(), temp2->getUsageCap(),
                                                     temp2->getDescription(), temp2->getUsage());
    cardNameToFunc["Standstill"] = display_ritual(temp2->getName(), temp2->getPlayCost(), temp2->getUsageCap(),
                                                  temp2->getDescription(), temp2->getUsage());
    cardNameToFunc["Giant Strength"] = display_enchantment_attack_defence(temp2->getName(), temp2->getPlayCost(),
                                                                          temp2->getDescription(), "+2", "+2");
    cardNameToFunc["Enrage"] = display_enchantment_attack_defence(temp2->getName(), temp2->getPlayCost(), temp2->getDescription(), "*2", "*2");
    cardNameToFunc["Haste"] = display_enchantment(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Magic Fatigue"] = display_enchantment(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Silence"] = display_enchantment(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Steal"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    cardNameToFunc["Switch Hand"] = display_spell(temp2->getName(), temp2->getPlayCost(), temp2->getDescription());
    return cardNameToFunc[temp2->getName()];
}

shared_ptr<Card> Player::getRitual() {
    return this->ritual;
}

int Player::countHand() {
    return this->hand.size();
}

void Player::resumeAction(){
    for(int i = 0; i<minions.size();i++){
        minions.at(i)->setAction(minions.at(i)->getActionCap());
    }
}

void Player::printMinions(Xwindow &window, int x, int y){
    for(int i = 0; i<minions.size(); i++){
        printCard(window, minions.at(i), x+252*i, y, 8);
    }
    for(int i = minions.size(); i<5;i++){
        window.fillRectangle(x+252*i, y , 201, 120, 8);
    }
}

void Player::printHand(Xwindow &window, int x, int y){
    for(int i = 0; i<hand.size(); i++){
        printCard(window, hand.at(i), x+252*i, y, 7);
    }
    for(int i = hand.size(); i<5;i++){
        window.fillRectangle(x+252*i, y , 201, 120, 7);
    }
}

void Player::printGraphics(Xwindow &window, int x, int y, bool iscurrent){
    if(ritual){
        printCard(window, ritual, x, y, 8);
    } else {
        window.fillRectangle(x, y , 201, 120, 8);
    }
    if(iscurrent){
        window.fillRectangle(x+504, y , 201, 120, 8);
        window.drawLine(x+504, y+20, x+704, y+20);
        window.drawLine(x+504+170, y, x+504+170, y+20);
        window.drawLine(x+504+35, y, x+504+35, y+20);
        window.drawString(x+504+179, y+11, std::to_string(magic));
        window.drawString(x+504+15, y+11, std::to_string(health));
        window.drawString(x+504+90, y+85, name);
    } else {
        window.fillRectangle(x+504, y , 201, 120, 8);
        window.drawLine(x+504, y+100, x+704, y+100);
        window.drawLine(x+504+170, y+100, x+504+170, y+119);
        window.drawLine(x+504+35, y+100, x+504+35, y+119);
        window.drawString(x+504+179, y+111, std::to_string(magic));
        window.drawString(x+504+15, y+111, std::to_string(health));
        window.drawString(x+504+90, y+25, name);
    }
    if(graveyard.size()>0){
        printCard(window, graveyard.back(), x+4*252, y,8);
    } else {
        window.fillRectangle(x+1008, y , 201, 120, 8);
    }
}

void Player::stealMinion(std::shared_ptr<Card> card){
    if(minions.size()<5){
        minions.push_back(card);
    }
}

void Player::stolenMinion(int index){
    getOpponent()->stealMinion(minions.at(index-1));
    minions.erase(minions.begin()+index-1);
}

std::vector<std::shared_ptr<Card>> Player::returnHand(){
    return hand;
}

void Player::switchHand(int index){
    hand.erase(hand.begin()+index-1);
    std::vector<std::shared_ptr<Card>> temp = hand;
    giveDeck(getOpponent()->returnHand(), "hand");
    getOpponent()->giveDeck(temp, "hand");
    throw 345;
}

