#include "voltage.h"
#include <iomanip>
#include <sstream>

Voltage::Voltage(uint16_t address, MUX_CHANNEL channel) :
    Display(address, channel, "Voltage", "V", false)
{
}

Voltage::~Voltage()
{
}

void Voltage::SetValue(float voltage)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << voltage;
    std::string fmtVoltage = stream.str();
    SetValue(fmtVoltage);
}
