#pragma once

#include <string>
#include <memory>

#include "CharacterRole.h"
#include "CharacterType.h"


class Player {
public:
      Player(const std::string& name,
            std::shared_ptr<CharacterRole> role,
            std::shared_ptr<CharacterType> type);

      virtual ~Player() = default;
      Player(const Player&) = default;
      Player& operator=(const Player& source) = default;

      std::string getName() const;
      int getLevel() const;
      int getForce() const;
      int getHealthPoints() const;
      int getMaxHP() const;
      int getCoins() const;
      std::string getDescription() const;

      std::string getRoleName() const;
      std::string getTypeName() const;
      std::shared_ptr<CharacterRole> getCharacterRole() const;
      std::shared_ptr<CharacterType> getCharacterType() const;

      int getCombatPower() const;
      void levelUp();
      void heal(int health);
      void damage(int damage);
      void addLoot(int loot);
      void setForce(int force);
      void setCoins(int coins);

      bool canPlayerPlay() const;
      void setLifeStatus();
      bool hasPlayerReachedMaxLevel() const;

      bool operator>(const Player& source) const;
      bool handleEncounterEffect(int combatPower, int loot, int damage);//

private:
      std::string playerName;
      int playerLevel;
      int playerForce;
      int playerCurrentHP;
      int playerMaxHP;
      int playerCoins;
      bool aliveOrDead;

      std::shared_ptr<CharacterRole> playerRole;
      std::shared_ptr<CharacterType> playerType;

};
