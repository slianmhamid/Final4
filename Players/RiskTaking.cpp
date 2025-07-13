#include "RiskTaking.h"
#include "Player.h"

RiskTaking::RiskTaking(const std::string &type): CharacterType(type) {}

int RiskTaking::dealWithPM(Player &player) const {
    int tmpP = 0;
    if(player.getCoins() >= 5 && player.getHealthPoints() < 50){
        player.setCoins(player.getCoins() - 5);
        player.addHP(10);
        tmpP++;
    }
    return tmpP;
}