#pragma once

#include "../Players/Player.h"
#include "characterRole.h"
#include <string>

class Event {
protected:
      std::string eventName;
public:
      /**
       * Gets the description of the event
       *
       * @return - the description of the event
      */
      virtual std::string getDescription() const = 0;
      Event(const std::string &name):eventName(name){}
      virtual ~Event() = default;
      virtual int applyEffect(Player& player) = 0;////
      virtual std::string eventEffectResult(Player& player,int effect) const = 0;
      std::string getEventName() const{
            return eventName;
      }
};
