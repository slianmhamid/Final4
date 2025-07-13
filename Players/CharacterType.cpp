#include "CharacterType.h"

CharacterType::CharacterType(const std::string &type):m_type(type) {}

std::string CharacterType::getCharacterType() const {
    return m_type;
}