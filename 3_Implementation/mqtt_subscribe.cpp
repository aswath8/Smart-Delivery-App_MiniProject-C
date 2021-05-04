
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>
#include "mqtt/client.h"
#include "inc/aes.h"

using namespace std;
using namespace std::chrono;

const string SERVER_ADDRESS	{ "tcp://broker.hivemq.com:1883" };
const string CLIENT_ID		{ "paho_f3fwefewfw" };

constexpr int QOS_0 = 0;
constexpr int QOS_1 = 1;
unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
AES aes(128);

const unsigned int MESSAGE_LENGTH = 100;
const unsigned int BLOCK_BYTES_LENGTH = MESSAGE_LENGTH * sizeof(unsigned char);

/////////////////////////////////////////////////////////////////////////////

// Message table function signature
using handler_t = std::function<bool(const mqtt::message&)>;

// Handler for data messages (i.e. topic "data/#")
std::string data_handler(const mqtt::message& msg)
{
	//cout << msg.get_topic() << ": " << msg.to_string() << endl;
	

	std::string s(msg.to_string());
	unsigned char plain[MESSAGE_LENGTH];
	for (int i = 0; i < MESSAGE_LENGTH; i++) 
	{
	plain[i] = s[i];
	}
	unsigned char *innew = aes.DecryptECB(plain, BLOCK_BYTES_LENGTH, key);
	cout<<"Decoded message: "<<innew<<'\n';
	std::string decoded_msg;
	for (int j = 0; j < sizeof(innew); j++) {
		decoded_msg += innew[j];
	}
	cout<<"\nDecoded message: "<<decoded_msg<<'\n';

	delete[] innew;
	return decoded_msg;
	//return msg.get_topic();
}

/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	mqtt::client cli(SERVER_ADDRESS, CLIENT_ID,
					 mqtt::create_options(MQTTVERSION_5));

	auto connOpts = mqtt::connect_options_builder()
		.mqtt_version(MQTTVERSION_5)
		.automatic_reconnect(seconds(2), seconds(30))
		.clean_session(false)
		.finalize();

	try {
		cout << "Connecting to the MQTT server..." << flush;
		mqtt::connect_response rsp = cli.connect(connOpts);
		cout << "OK\n" << endl;

		if (!rsp.is_session_present()) {
			std::cout << "Subscribing to topics..." << std::flush;

			mqtt::subscribe_options subOpts;
			mqtt::properties props1 {
				{ mqtt::property::SUBSCRIPTION_IDENTIFIER, 1 },
			};
			cli.subscribe("sdbAA/loc", QOS_0, subOpts, props1);

			std::cout << "OK" << std::endl;
		}
		else {
			cout << "Session already present. Skipping subscribe." << std::endl;
		}

		// Consume messages

		while (true) {
			auto msg = cli.consume_message();

			// Note: In a real app, you'd want to do a lot more error
			// and bounds checking than this.

			if (msg) {
				// Get the subscription ID from the incoming message
				int subId = mqtt::get<int>(msg->get_properties(),
										   mqtt::property::SUBSCRIPTION_IDENTIFIER);

				// Dispatch to a handler function based on the Subscription ID
				std::string d = data_handler(*msg);
				std::cout<<d;
			}
			else if (!cli.is_connected()) {
				cout << "Lost connection" << endl;
				while (!cli.is_connected()) {
					this_thread::sleep_for(milliseconds(250));
				}
				cout << "Re-established connection" << endl;
			}
		}

		// Disconnect

		cout << "\nDisconnecting from the MQTT server..." << flush;
		cli.disconnect();
		cout << "OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return 1;
	}

 	return 0;
}