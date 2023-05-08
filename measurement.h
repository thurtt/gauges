#pragma once

#include "packet.h"

const int VOLTAGE_ADC_INPUT = 0;
const int OIL_ADC_INPUT = 1;
const int TEMP_ADC_INPUT = 2;
const int FUEL_ADC_INPUT = 3;
const int ADC_REF = 3;

const int R_TEMPDIV = 322;

const float VOLT_CONVERSION_FACTOR = 19.8f / (1 << 12);
const float OIL_CONVERSION_FACTOR = 5.0f / (1 << 12);
const float TEMP_CONVERSION_FACTOR = 3.3f / (1 << 12);

class Measurement
{
public:
    FIFO_PACKET ReadVoltage();
    FIFO_PACKET ReadOilPressure();
    FIFO_PACKET ReadTemperature();
    FIFO_PACKET ReadFuel();
private:
    float ADCRefVoltage();
    
};