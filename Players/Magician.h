#pragma once
#include "Job.h"
#include "Player.h"
class Magician : public Job{
public:
    std::string jobToString() const override;
    int handleWithSolarEclipse(Player &player) override;
    Magician(const std::string &name);

};

std::string Magician::jobToString() const{
    return "Magician";
}

int Magician::handleWithSolarEclipse(Player &player){
    player.setForce(player.getForce() + 1);
    return 1;
}
Magician::Magician(const std::string &name) : Job(name){}
