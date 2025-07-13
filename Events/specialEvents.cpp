
#include "specialEvents.h"


SpecialEvents::SpecialEvents(const string& name) : Event(name){}

string SpecialEvents::getDescription() const{
    return m_name;
}

