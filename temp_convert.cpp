#include "SteinhartHart.h"
#include <iostream>

using namespace std;

int main()
{
    double r;
    SteinhartHart shh;

    while(true)
    {
        cout << "Enter in resistance: ";
        cin >> r;

        cout << "Temp Kelvin: " << shh.getTempKelvin(r) <<endl;
        cout << "Temp Celsius: " << shh.getTempCelsius(r) <<endl;
        cout << "Temp Fahrenheit: " << shh.getTempFahrenheit(r) <<endl;
    }



}