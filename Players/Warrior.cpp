#include "player.h"
#include "Warrior.h"
#include "CharacterRole.h"

Warrior::Warrior(const std::string& role) : CharacterRole(role) {}

int Warrior::getMaxHP() const {
      return 150;
}

int Warrior::getCombatPower(const Player& player) const {
      return player.getForce() * 2 + player.getLevel();
}
