#include "Encounter.h"
#include "Utilities.h"
Encounter::Encounter(const string &name,int combatPower,int loot,int damage)
        : Event(name), m_combatPower(combatPower),m_loot(loot),m_damage(damage){}

int Encounter::getCombatPower()const{
    return m_combatPower;
}
int Encounter::getLoot()const{
    return m_loot;
}
int Encounter::getDamage() const{
    return m_damage;
}

string Encounter::getDescription() const {
        return m_name + " (power " + std::to_string(m_combatPower) +", loot "+
                std::to_string(m_loot) +", damage "+std::to_string(m_damage)+")";
}

Snail::Snail(): Encounter("Snail",5,2,10){}


Slime::Slime(): Encounter("Slime",12,5,25){}

Balrog::Balrog() :Encounter("Balrog",15,100,9001){}

int Balrog::applyEffect(Player &player){
    int i = player.applyEncounter(m_combatPower,m_loot,m_damage);
    m_combatPower+=2;
    return i;

}

Pack::Pack(vector<shared_ptr<Encounter>> encounters):
Encounter("Pack",0,0,0),m_size(0)
,barlogs(0){
    //m_size = encounters.size();
    m_encounters = encounters;

for(std::vector<std::shared_ptr<Encounter>>::const_iterator cit = encounters.cbegin();cit!= encounters.cend();cit++){
  //  cout << (*cit)->getnameE() << "   ";
    m_combatPower += (*cit)->getCombatPower();

    m_damage += (*cit)->getDamage();
    m_loot += (*cit)->getLoot();
    m_size++;
if((*cit)->getnameE() == "Balrog"){
    barlogs++;
}

}
}

string Pack::getDescription() const {
    return "Pack of "+std::to_string(m_size) +" members (power " + std::to_string(m_combatPower) +", loot "+
           std::to_string(m_loot) +", damage "+std::to_string(m_damage)+")";
}

int Encounter::applyEffect(Player &player) {
    return player.applyEncounter(m_combatPower,m_loot,m_damage);
}
string Encounter::getResult(Player &player,int effect) const {
    if(effect == 1){
        return getEncounterWonMessage(player,this->m_loot);
    }else if (effect == 0){
        return getEncounterLostMessage(player, this->m_damage);
    }
    return " ";
}

int Pack::applyEffect(Player &player) {
    int i = player.applyEncounter(m_combatPower,m_loot,m_damage);
    m_combatPower += (2*barlogs);
    return i;
}

const std::vector<std::shared_ptr<Encounter>>& Pack::getEncounters() const {
    return m_encounters;
}