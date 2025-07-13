#pragma once
#include "CharacterType.h"

class RiskTaking: public CharacterType{
public:
    RiskTaking(const std::string &type);
    int dealWithPM(Player &player) const override;
};