#include "oil.h"
#include <iomanip>
#include <sstream>

Oil::Oil(uint16_t address, MUX_CHANNEL channel) :
    Display(address, channel, "Oil", "psi", false)
{
}

Oil::~Oil()
{
}

void Oil::SetValue(float oil)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << oil;
    std::string fmtOil = stream.str();
    SetValue(fmtOil);
}