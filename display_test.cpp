#include <stdio.h>
#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/shapeRenderer/ShapeRenderer.h"
#include "pico-ssd1306/textRenderer/TextRenderer.h"
#include "hardware/i2c.h"


int main(int argc, char * argv[])
{
    i2c_init(i2c_default, 1000000); //Use i2c port with baud rate of 1Mhz
    //Set pins for I2C operation
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    //Create a new display object
    pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(i2c_default, 0x3D, pico_ssd1306::Size::W128xH64);

    //create a vertical line on x: 64 y:0-63
    display.clear();
    drawText(&display, font_12x16, "Fuel", 40 ,0);
    drawText(&display, font_12x16, "Christine!", 8 ,24);
    //for( int x = 0; x < 64; x+=2)
    //{
        // for (int y = 0; y < 64; y++){
        //     display.setPixel(64, y);
        // }
   // }
    display.sendBuffer(); //Send buffer to device and show on screen
    return 0;

}