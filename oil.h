#pragma once

#include "display.h"

class Oil : public Display
{
public:
    using Display::SetValue;
    Oil(uint16_t address, MUX_CHANNEL channel);
    virtual ~Oil();
    void SetValue(float oil);
};