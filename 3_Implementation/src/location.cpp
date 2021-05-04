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
#include <cstring>

#include "../inc/aes.h"

const unsigned int BLOCK_BYTES_LENGTH = 16 * sizeof(unsigned char);

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
            std::string("\"pick_adr\":")+ 
            std::string("\"")+address1+
            std::string("\",")+
            std::string("\"del_adr\":")+
            std::string("\"")+address2+
            std::string("\"}");
    
    // Create a client

    mqtt::client cli(ADDRESS, CLIENT_ID,nullptr);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try {
        // Connect to the client

        cli.connect(connOpts);

        // Publish using a message pointer.
        AES aes(128);
        unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
        unsigned char right[] = { 0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a, 
                                    0x07, 0xfe, 0xef, 0x74, 0xe1, 0xd5, 0x03, 0x6e, 0x90, 0x0e, 0xee, 0x11, 0x8e, 0x94, 0x92, 0x93, 
        };
        unsigned int len = 0;
        std::string s(json);
        unsigned char plain[100];
        int i;
        for (i = 0; i < sizeof(plain); i++) 
        {
        plain[i] = s[i];
        }
        unsigned char *out = aes.EncryptECB(plain, (BLOCK_BYTES_LENGTH * 2) * sizeof(unsigned char), key, len);
        
        /*unsigned char *innew = aes.DecryptECB(out, BLOCK_BYTES_LENGTH, key);
        cout<<out<<'\n';*/
        
        //delete[] innew;
        int size = sizeof(out) / sizeof(char);
        int i;
        string s = "";
        for (i = 0; i < size; i++) {
            s = s + &out[i];
        }
        //std::string str(out);        
        auto msg = mqtt::make_message(TOPIC, s);
        msg->set_qos(mqtt::GRANTED_QOS_0);
        //delete[] out;
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