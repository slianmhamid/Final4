#pragma once
#include "specialEvents.h"


class SolarEclipse : public SpecialEvents{
public:
    SolarEclipse() ;
    int applyEffect(Player &player)override;
    string getResult(Player &player,int effect) const override;
};

int SolarEclipse::applyEffect(Player &player){

    return player.getJob()->handleWithSolarEclipse(player);
}

SolarEclipse::SolarEclipse() : SpecialEvents("SolarEclipse"){
}
string SolarEclipse::getResult(Player &player,int effect)const{
    return getSolarEclipseMessage(player,effect);
}