#include "temperature.h"
#include <iomanip>
#include <sstream>

Temperature::Temperature(uint16_t address, MUX_CHANNEL channel) :
    Display(address, channel, "Temp", "°F", false)
{
}

Temperature::~Temperature()
{
}

void Temperature::SetValue(float temp)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << temp;
    std::string fmtTemp = stream.str();
    SetValue(fmtTemp);
}