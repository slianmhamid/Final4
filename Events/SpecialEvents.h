#pragma once
#include "Event.h"
#include <string>

class SpecialEvents : public Event{
public:
      SpecialEvents(const string& name);
      std::string getDescription() const override;
      virtual ~SpecialEvents() = default;
};
