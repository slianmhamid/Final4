#pragma once
#include <string>
class Player;

class CharacterType{
public:
    CharacterType(const std::string &type);
    std::string getCharacterType() const;
    virtual ~CharacterType() = default;
    virtual int dealWithPM(Player &player) const = 0;
protected:
    std::string m_type;
};