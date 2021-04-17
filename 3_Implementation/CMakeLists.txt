cmake_minimum_required(VERSION 3.0.2)
project(mqtt)
#find_package(Threads REQUIRED)
find_package(PahoMqttCpp REQUIRED)
file(GLOB SOURCES
     "src/*.c"
)

include_directories("inc/")
add_executable(mqtt main.c ${SOURCES})

target_link_libraries(mqtt PahoMqttCpp::paho-mqttpp3)
