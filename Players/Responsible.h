#pragma once
#include "CharacterType.h"
#include "Player.h"

class Responsible: public CharacterType{
public:
    Responsible(const std::string &type);
    int dealWithPM(Player &player) const override;
};