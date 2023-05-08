#pragma once

enum PACKET_TYPE
{
    VOLTAGE,
    OIL,
    FUEL,
    TEMP
};

struct FIFO_PACKET
{
    PACKET_TYPE type;
    float data;
};