#include "Player.h"

static const int MAXL = 10;

Player::Player(const string &name, const std::shared_ptr<Job> job, const std::shared_ptr<CharacterType> ct)
        : m_name(name),
          m_level(1),
          m_force(5),
          m_currHP(job->getMaxHP()),
          m_maxHP(job->getMaxHP()),
          m_coins(job->getCoins()),
          isEliminated(true),
          m_job(std::move(job)),
          m_character(std::move(ct)){}

string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getHealthPoints() const {
    return m_currHP;
}

//string Player::getDescription() const {
//    return ;
//}
int Player::getForce() const {
    return m_force;
}

int Player::getLevel() const {
    return m_level;
}

int Player::getCombatPower() const {
    return m_job->getCombatPower(m_force,m_level);
}
string Player::getJobString() const{
    return m_job->jobToString();
}
std::shared_ptr<Job> Player::getJob() const {
    return m_job;
}

void Player::setForce(int force){
    m_force = force;
}
void Player::addHP(int toAdd){
    m_currHP += toAdd;
    if (m_currHP > m_maxHP){
        m_currHP = m_maxHP;
    }
}
int Player::getMaxHP()const{
    return m_maxHP;
}
void Player::setCoins(int coins){
    m_coins = coins;
}
void Player::levelUp() {
    m_level++;
}
void Player::damage(int damage) {
    m_currHP = std::max(m_currHP-damage,0);
}

void Player::addLoot(int loot) {
    m_coins += loot;
}

std::shared_ptr<CharacterType> Player::getCharacterType() const{
    return m_character;
}

bool Player::applyEncounter(int combatPower, int loot, int damage){
    if(this->getCombatPower() > combatPower) {
        this->addLoot(loot);
        levelUp();
        if((this->m_job)->jobToString() == "Warrior")
            this->damage(10);
        return true;
    }
    else{
        this->damage(damage) ;
        return false;
        }

}

string Player::getDescription() const{
    return m_name +", "+m_job->jobToString() +" with "+ m_character->getCharacterType()
    +" character (level "+ std::to_string(getLevel())+", force "+std::to_string(getForce()) +")";

}
bool Player::isMaxLevel()const{
    return m_level == MAXL;
}
bool Player::operator>(const Player &other) {
    if (m_level > other.m_level) {
        return true;
    }
    if (m_level < other.m_level) {
        return false;
    }
    if (m_coins > other.m_coins) {
        return true;
    }
    if (m_coins < other.m_coins) {
        return false;
    }
    return m_name < other.m_name; // Lexicographically smaller names rank higher
}


bool Player::canPlay() const{
    return isEliminated;
}
void Player::setStatus(){
    isEliminated = false;
}