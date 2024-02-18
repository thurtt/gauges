#include "display.h"
#include "pico/stdlib.h"
#include "ssd1306.h"
#include "shapeRenderer/ShapeRenderer.h"
#include "textRenderer/TextRenderer.h"
#include "hardware/i2c.h"

Display::Display(uint16_t address, MUX_CHANNEL channel, std::string label, std::string units, bool graphical) : m_address(address),
                                                                                                                m_channel(channel),
                                                                                                                m_label(label),
                                                                                                                m_units(units),
                                                                                                                m_graphical(graphical)
{

    // Create a new display object
    m_display = std::make_shared<SSD1306>(i2c_default, m_address, Size::W128xH64);
}

Display::~Display()
{
}

void Display::Clear()
{
    SelectChannel();
    m_display->clear();
}

void Display::SetValue(std::string value)
{
    SelectChannel();
    value += m_units;
    drawText(m_display.get(), font_12x16, m_label.c_str(), 5, 0);
    drawText(m_display.get(), font_16x32, value.c_str(), 8, 28);
    m_display->sendBuffer();
}

void Display::SelectChannel()
{
    uint8_t buf = static_cast<uint8_t>(m_channel);
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        ret = i2c_write_blocking(i2c_default, MUX_ADDRESS, &buf, sizeof(buf), false);
        if (ret == sizeof(buf))
        {
            break;
        }
    }
}