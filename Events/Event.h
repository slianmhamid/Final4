
#pragma once

#include "../Players/Player.h"
#include "Job.h"


class Event {
protected:
    std:: string m_name;
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    Event(const string &name):m_name(name){}
    virtual string getDescription() const = 0;
    virtual ~Event() = default;
    virtual int applyEffect(Player &player) = 0;
    virtual string getResult(Player &player,int effect) const = 0;
    string getnameE() const{
        return m_name;
    }
};
