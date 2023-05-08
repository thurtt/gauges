#pragma once

#include "display.h"


class Voltage : public Display
{
public:
    using Display::SetValue;
    Voltage(uint16_t address, MUX_CHANNEL channel);
    virtual ~Voltage();
    void SetValue(float value);

};