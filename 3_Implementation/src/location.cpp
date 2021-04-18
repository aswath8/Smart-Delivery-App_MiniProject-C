/**
 * @file location.c
 * @author your name (you@domain.com)
 * @brief Fetching Location Values
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"smart_delivery.h"


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

//#include<iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <memory>
#include "mqtt/async_client.h"
#include "mqtt/client.h"


/**
 * @brief Location details
 * 
 * @return int 
 */
int location()
{
    char address1[30],address2[30];
    printf("\nPlease provide the pickup address: ");
    scanf("%s",address1);
    printf("\nPlease provide the delivery address: ");
    scanf("%s",address2);
    
    const std::string ADDRESS("tcp://broker.hivemq.com:1883");
    const std::string CLIENT_ID("bec-sense0880");

    const std::string TOPIC { "sdbAA/loc" };
    // const std::string PAYLOAD1 { "vit" };
    const std::string a="a";
    const std::string b="b";
    //const std::string json = a+b;
    
    const std::string json = std::string("{")+
            std::string("\"pick_adr\":")+ address1+
            std::string(",")+
            std::string("\"del_adr\":")+address2+
            std::string("}");
    
    // Create a client

    mqtt::client cli(ADDRESS, CLIENT_ID,nullptr);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try {
        // Connect to the client

        cli.connect(connOpts);

        // Publish using a message pointer.

        auto msg = mqtt::make_message(TOPIC, json);
        msg->set_qos(mqtt::GRANTED_QOS_0);

        cli.publish(msg);

        // Now try with itemized publish.

        // cli.publish(TOPIC, json, strlen(json), 2, false);

        // Disconnect

        cli.disconnect();
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << " ["
            << exc.get_reason_code() << "]" << std::endl;
        return 1;
    }

    return 0;
}