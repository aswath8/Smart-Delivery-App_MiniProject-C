cmake_minimum_required(VERSION 3.0.2)
project(mqtt)
#find_package(Threads REQUIRED)
find_package(PahoMqttCpp REQUIRED)
add_subdirectory(src)
add_executable(mqtt main.c)

target_link_libraries(mqtt PahoMqttCpp::paho-mqttpp3)
