#pragma once

#include "Player.h"
#include "CharacterRole.h"

class Warrior : public CharacterRole {
public:
      Warrior(const std::string& role);
      virtual ~Warrior() = default;

      int getMaxHP() const override;
      int getCombatPower(const Player& player) const override;
};

