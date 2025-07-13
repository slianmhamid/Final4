#pragma once
#include <string>
class Player;

class Job{
protected:
    std::string m_job;
public:
    Job(const std::string &job);
    virtual int getCombatPower(int force,int level) const;
    virtual int getMaxHP() const;
    virtual int getCoins() const;
    virtual std::string jobToString() const = 0;
    virtual int handleWithSolarEclipse(Player &player);
    virtual ~Job() = default;


};