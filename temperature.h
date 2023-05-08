#pragma once

#include "display.h"

class Temperature: public Display
{
public:
    using Display::SetValue;
    Temperature(uint16_t address, MUX_CHANNEL channel);
    virtual ~Temperature();
    void SetValue(float temp_c);
};