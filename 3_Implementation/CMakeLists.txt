cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 11)

project(mqtt)
#find_package(Threads REQUIRED)
find_package(PahoMqttCpp REQUIRED)
set(SOURCES
main.cpp src/account_check.cpp src/location.cpp src/medicine.cpp src/validate.cpp
src/cart_order_confirmation.cpp src/Food.cpp src/login_signup.cpp src/otpauthentication.cpp src/aes.cpp
)

add_executable(mqtt ${SOURCES})

add_executable(mqtt_subscribe mqtt_subscribe.cpp src/mqtt_subscriber_helper.cpp)

target_include_directories(mqtt PUBLIC ${PROJECT_SOURCE_DIR}/inc
)


target_link_libraries(mqtt PahoMqttCpp::paho-mqttpp3)
target_link_libraries(mqtt_subscribe PahoMqttCpp::paho-mqttpp3)
