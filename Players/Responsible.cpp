#include "Responsible.h"

Responsible::Responsible(const std::string &type): CharacterType(type) {}
int Responsible::dealWithPM(Player &player) const{
    int tmpP=0;
    while (player.getCoins() - 5 >= 0 && player.getHealthPoints() < player.getMaxHP()) {
        player.setCoins(player.getCoins() - 5);
        player.addHP(10);
        tmpP++;
    }
    return tmpP;
}