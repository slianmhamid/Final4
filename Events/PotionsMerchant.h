#pragma once
#include "specialEvents.h"


class PotionsMerchant: public SpecialEvents{
public:
    PotionsMerchant();
    int applyEffect(Player &player)override;
    string getResult(Player &player,int effect) const override;
};

int PotionsMerchant::applyEffect(Player &player){
    return player.getCharacterType()->dealWithPM(player);
}
PotionsMerchant::PotionsMerchant() : SpecialEvents("PotionsMerchant") {}


string PotionsMerchant::getResult(Player &player,int effect)const{
    return getPotionsPurchaseMessage(player,effect);
}
