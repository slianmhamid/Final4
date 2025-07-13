#pragma once
#include "Job.h"
#include "Player.h"
class Warrior : public Job{
public:
    Warrior(const string& name);
    int getCombatPower(int force,int level)const override;
    int getMaxHP() const override;
    std::string jobToString() const override;

};

int Warrior::getCombatPower(int force,int level)const {
    return 2 * force +level;
}

int Warrior::getMaxHP() const {
    return 150;
}

std::string Warrior::jobToString() const{
    return "Warrior";
}

Warrior::Warrior(const std::string &name) : Job(name){}