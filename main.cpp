#include "temperature.h"
#include "voltage.h"
#include "oil.h"
#include "packet.h"

#include "pico/multicore.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"

#include "measurement.h"


void display_worker()
{

    Voltage vDisplay = Voltage(0x3D, MUX_CHANNEL::ZERO);
    Oil oDisplay = Oil(0x3D, MUX_CHANNEL::ONE);
    Temperature tDisplay = Temperature(0x3D, MUX_CHANNEL::TWO);
    while(true)
    {
        uint32_t value = multicore_fifo_pop_blocking();

        FIFO_PACKET * pkt = reinterpret_cast<FIFO_PACKET *>(value);

        switch(pkt->type)
        {
        case PACKET_TYPE::VOLTAGE:
            vDisplay.Clear();
            vDisplay.SetValue(pkt->data);
            break;
        case PACKET_TYPE::OIL:
            oDisplay.Clear();
            oDisplay.SetValue(pkt->data);
            break;
        case PACKET_TYPE::TEMP:
            tDisplay.Clear();
            tDisplay.SetValue(pkt->data);
            break;
        };

    }
}

int main(int argc, char * argv[])
{

    // Initialize the default i2c port
    // Use i2c port with clock rate of 400kHz
    i2c_init(i2c_default, 400000);
    
    // Set up the gpio pins for i2c
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    
    // Initialize the ADC pin
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(30);


    // Start the display loop
    multicore_launch_core1(display_worker);

    Measurement measure;

    // measurement loop
    while(true)
    {
        FIFO_PACKET oilPkt = measure.ReadOilPressure();
        multicore_fifo_push_blocking(reinterpret_cast<uint32_t>(&oilPkt));
        sleep_ms(500);
        
        FIFO_PACKET tempPkt = measure.ReadTemperature();
        multicore_fifo_push_blocking(reinterpret_cast<uint32_t>(&tempPkt));           
        sleep_ms(500);

        FIFO_PACKET voltPkt = measure.ReadVoltage();
        multicore_fifo_push_blocking(reinterpret_cast<uint32_t>(&voltPkt));
        sleep_ms(500);
    }

    return 0;
}