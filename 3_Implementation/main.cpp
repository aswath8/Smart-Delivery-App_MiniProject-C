#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"smart_delivery.h"


#include<iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <memory>
#include "mqtt/async_client.h"
#include "mqtt/client.h"




int main()
{
    /*
    const std::string ADDRESS("tcp://broker.hivemq.com:1883");
    const std::string CLIENT_ID("mqtizer-1618738314805");

    const std::string TOPIC { "Loc" };
    const std::string PAYLOAD1 { "vit" };

    const char* PAYLOAD2 = "Hi there!";

    // Create a client

    mqtt::client cli(ADDRESS, CLIENT_ID,nullptr);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try {
        // Connect to the client

        cli.connect(connOpts);

        // Publish using a message pointer.

        auto msg = mqtt::make_message(TOPIC, PAYLOAD1);
        msg->set_qos(mqtt::GRANTED_QOS_0);

        cli.publish(msg);

        // Now try with itemized publish.

        //cli.publish(TOPIC, PAYLOAD2, strlen(PAYLOAD2), 2, false);

        // Disconnect

        cli.disconnect();
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << " ["
            << exc.get_reason_code() << "]" << std::endl;
        return 1;
    }
    */




    int input,choice=1,otp=0;
    char input_repeat[20];
    printf("Welcome to Smart delivery APP\n");
    int pass=Login_Singup();
    if(pass==0)
    {
        while(choice==1)
        {
            printf("Please select the delivery system\n");
            printf("1.Food\n");
            printf("2.Medicines\n");
            scanf("%d", &input);
            if(input==1)
            {
                int res=Food();
                if(res==0)
                {
                    printf("\nReceived the order? press 1 for OTP Authentication press 0 if not ");
                    scanf("%d", &otp);
                    if(otp==1)
                    {
                        otpauthentication();
                        exit(1);
                    }
                    else{
                        printf("Want to order anything else? Yes or No");
                        scanf("%s", &input_repeat);
                        if(!strcmp(input_repeat,"Yes"))
                        {
                            choice=1;
                        }
                        else{
                            choice=0;
                        }
                    }
                }
                else{
                    break;
                }
            }
            else if(input==2)
            {
                int res=Medicine();
                if(res==0)
                {
                    printf("\nReceived the order? press 1 for OTP Authentication press 0 if not ");
                    scanf("%d", &otp);
                    if(otp==1)
                    {
                        otpauthentication();
                        exit(1);
                    }
                    else
                    {
                        printf("Want to order anything else? Yes or No");
                        scanf("%s", &input_repeat);
                        if(!strcmp(input_repeat,"Yes"))
                        {
                            choice=1;
                        }
                        else{
                            choice=0;
                        }
                    }
                }
                else{
                    break;
                }
            }

            else{
                printf("please enter a valid number\n");
            }
        }
        
    }
    return 0;
}