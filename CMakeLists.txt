# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "/path/to/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(gauges C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add the SSD library to the build
add_subdirectory($ENV{SSD1306_LIB_PATH} ./dep_builds)

# Add executable. Default name is the project name, version 0.1
add_executable(gauges main.cpp display.cpp voltage.cpp oil.cpp temperature.cpp measurement.cpp SteinhartHart.cpp)
pico_set_program_name(gauges "Automotive Gauges")
pico_set_program_version(gauges "0.1")

pico_enable_stdio_usb(gauges 1)

# Add the standard library to the build
target_link_libraries(gauges pico_stdlib pico_multicore hardware_adc)

# Add any user requested libraries
target_link_libraries(gauges
        hardware_i2c
        pico_ssd1306
        hardware_i2c
        )

target_include_directories(gauges PUBLIC $ENV{SSD1306_LIB_PATH})

pico_add_extra_outputs(gauges)

