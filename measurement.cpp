#include "hardware/adc.h"
#include "measurement.h"
#include "SteinhartHart.h"


FIFO_PACKET Measurement::ReadVoltage()
{
    adc_select_input(VOLTAGE_ADC_INPUT);
    uint16_t raw_voltage = adc_read();
    float voltage = raw_voltage * VOLT_CONVERSION_FACTOR;
    FIFO_PACKET voltPkt;
    voltPkt.type = PACKET_TYPE::VOLTAGE;
    voltPkt.data = voltage;
    return voltPkt;
}

FIFO_PACKET Measurement::ReadOilPressure()
{
    adc_select_input(OIL_ADC_INPUT);
    uint16_t raw_oil = adc_read();
    float oil = raw_oil * OIL_CONVERSION_FACTOR;
    FIFO_PACKET oilPkt;
    oilPkt.type = PACKET_TYPE::OIL;
    oilPkt.data = oil;
    return oilPkt;
}

FIFO_PACKET Measurement::ReadTemperature()
{
    SteinhartHart shh;
    FIFO_PACKET tempPkt;
    
    float vref = ADCRefVoltage();

    adc_select_input(TEMP_ADC_INPUT);
    uint16_t raw_voltage = adc_read();
    float v_temp = raw_voltage * TEMP_CONVERSION_FACTOR;
    float i_temp = (vref - v_temp) / R_TEMPDIV;
    float r_temp = v_temp / i_temp;

    float temp_f = shh.getTempFahrenheit(r_temp);
    tempPkt.type = PACKET_TYPE::TEMP;
    tempPkt.data = temp_f;
    return tempPkt;
}

float Measurement::ADCRefVoltage(){
    adc_select_input(VOLTAGE_ADC_INPUT);
    uint16_t raw_voltage = adc_read();
    float ref_voltage = raw_voltage * TEMP_CONVERSION_FACTOR;
    return ref_voltage;
}

FIFO_PACKET Measurement::ReadFuel()
{
    FIFO_PACKET fuelPkt;
    return fuelPkt;
}
