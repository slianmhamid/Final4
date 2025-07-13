#pragma once
#include "SpecialEvents.h"
#include "Utilities.h"

class PotionsMerchant: public SpecialEvents{
public:
      PotionsMerchant();
      int applyEffect(Player &player) override;
      std::string eventEffectResult(Player &player,int effect) const override;
};

PotionsMerchant::PotionsMerchant():SpecialEvents("PotionsMerchant") {}

int PotionsMerchant::applyEffect(Player &player){
      return player.getCharacterType()->applyPotionsMerchantEffect(player);
}

std::string PotionsMerchant::eventEffectResult(Player &player,int effect) const{
      return getPotionsPurchaseMessage(player,effect);
}
