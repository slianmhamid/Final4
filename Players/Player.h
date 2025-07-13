
#pragma once
#include <string>
#include <memory>
#include "Job.h"
#include "CharacterType.h"

using std::string;

class Player {

public:
    Player(const string &name, const std::shared_ptr<Job> job, const std::shared_ptr<CharacterType> ct);
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;
    Player(const Player&) = default;
    bool operator>(const Player& other);


    //getters
    string getName() const;
    int getLevel() const;
    int getForce() const;
    int getHealthPoints() const;
    int getCoins() const;
    std::shared_ptr<Job> getJob() const;

    std::shared_ptr<CharacterType> getCharacterType() const;
    string getDescription() const;
    string getJobString() const;
    int getCombatPower() const;
    void setForce(int force);
    int getMaxHP()const;
    bool applyEncounter(int combatPower,int loot , int damage);
    bool isMaxLevel()const;
    bool canPlay() const;
    void setStatus();

    //func
    void levelUp();
    void damage(int damage);
    void addLoot(int loot);
    void addHP(int toAdd);
    void setCoins(int coins);








   //bool operator>(const std::shared_ptr<Player> p);


protected:
    string m_name;
    int m_level;
    int m_force;
    int m_currHP;
    int m_maxHP;//need to check
    int m_coins;
    bool isEliminated;
    std::shared_ptr<Job> m_job;
    std::shared_ptr<CharacterType> m_character;
};
