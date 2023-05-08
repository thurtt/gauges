#pragma once
#include <string>
#include <memory>
#include "pico-ssd1306/ssd1306.h"

using namespace pico_ssd1306;

const uint8_t MUX_ADDRESS = 0x70;

enum MUX_CHANNEL
{
    ZERO = 0x01 << 0,
    ONE = 0x01 << 1,
    TWO = 0x01 << 2,
    THREE = 0x01 << 3,
    FOUR = 0x01 << 4,
    FIVE = 0x01 << 5,
    SIX = 0x01 << 6,
    SEVEN = 0x01 << 7
};

class Display
{
    public:
        Display(uint16_t address, MUX_CHANNEL channel, std::string label, std::string units, bool graphical);
        virtual ~Display();
        void Clear();
        void Update();
        void SetValue(std::string value);

    private:
        void SelectChannel();

    protected:
        uint16_t m_address;
        MUX_CHANNEL m_channel;
        std::string m_label;
        std::string m_units;
        bool m_graphical;

        std::shared_ptr<SSD1306> m_display;
};