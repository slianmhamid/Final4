#pragma once
#include "SpecialEvents.h"
#include "Utilities.h"

class SolarEclipse : public SpecialEvents{
public:
      SolarEclipse() ;
      int applyEffect(Player &player) override;
      std::string eventEffectResult(Player &player,int effect) const override;
};

SolarEclipse::SolarEclipse():SpecialEvents("SolarEclipse") {}

int SolarEclipse::applyEffect(Player &player){
      return player.getCharacterRole()->applySolarEclipseEffect(player);
}

std::string SolarEclipse::eventEffectResult(Player &player,int effect) const{
      return getSolarEclipseMessage(player,effect);
}
