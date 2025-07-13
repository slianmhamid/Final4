#include "SpecialEvents.h"

SpecialEvents::SpecialEvents(const string& name) : Event(name){}

std::string SpecialEvents::getDescription() const{
      return eventName;
}
