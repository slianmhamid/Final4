#include "Job.h"
#include "Player.h"
int Job::getCombatPower(int force, int level) const {
    return force + level;
}

int Job::getCoins() const {
    return 10;
}

int Job::getMaxHP() const {
    return 100;
}
int Job::handleWithSolarEclipse(Player &player){
    if (player.getForce() > 0) {
        player.setForce(player.getForce() - 1);
        return -1;
    }
    return 0;
}

Job::Job(const std::string &job):m_job(job) {}