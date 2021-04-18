/**
 * @file otpauthentication.c
 * @author your name (you@domain.com)
 * @brief OTP authentication
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 * @brief For displaying OTP, getting input and comparing
 * 
 */
void otpauthentication()
{
    const std::string ADDRESS("tcp://broker.hivemq.com:1883");
    const std::string CLIENT_ID("bec-sense0880");

    const std::string TOPIC { "sdb00/otp" };
    // const std::string PAYLOAD1 { "vit" };
    const std::string json="verified";
    
    char str[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int n = strlen(str);
    int inp;
    char otp[8];
    char OTP[8];
    for (int i=0; i<=6; i++)
        OTP[i]=str[rand()%n];
    printf("\nYour OTP Number is:%s",OTP);
    OTP[8]='\n';
    printf("\nPlease enter the OTP:");
    scanf("%s", otp);
    int res=strcmp(otp,OTP);
    printf("\n",strlen(otp),strlen(OTP));
    if(res==0)
    {
        printf("OTP is Verified..Thanks for Purchasing\n");

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
        }


    }
    else
    {
        printf("Please Enter Correct OTP\n");
        printf("If you want to exit press 0 Else press 1\n");
        scanf("%d", &inp);
        if(inp==0)
            exit(1);
        else
            otpauthentication();
    }
}