#pragma once
#include "Job.h"
#include "Player.h"
class Archer : public Job{
public:
    int getCoins() const override;
    std::string jobToString() const override;
    Archer(const std::string &name);
};

int Archer::getCoins() const {
    return 20;
}

std::string Archer::jobToString() const{
    return "Archer";
}

Archer::Archer(const std::string &name) : Job(name){}