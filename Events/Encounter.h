#pragma once
#include "Event.h"
#include <vector>
#include <memory>


using namespace std;

class Encounter : public Event{
public:
    Encounter(const string &name,int combatPower,int loot,int damage);
    int getCombatPower()const;
    int getLoot()const;
    int getDamage()const;
    string getDescription() const override;
    virtual int applyEffect(Player &player) override;
    string getResult(Player &player,int effect)const override;

protected:
    int m_combatPower;
    int m_loot;
    int m_damage;

};

class Snail : public Encounter{
public:
    Snail();

};

class Slime : public Encounter{
public:
    Slime();


};

class Balrog : public Encounter{
public:
    Balrog();
    int applyEffect(Player &player) override;

};
class Pack : public Encounter{
public:
    Pack(vector<shared_ptr<Encounter>> encounters);
    string getDescription() const override;
    //Event* clone() const override ;
    int applyEffect(Player &player) override;
    const vector<std::shared_ptr<Encounter>>& getEncounters() const;



private:
    int m_size;
    int barlogs;
    std::vector<std::shared_ptr<Encounter>> m_encounters;
};
