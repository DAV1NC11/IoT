#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

//To Change
byte mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xED};
IPAddress ip(172, 16, 0, 100);
//byte dns[] = {192, 168, 0, 1};
byte gateway[] = {192, 168, 0, 1};
byte subnet[] = {255, 255, 255, 0};
const char* server = "192.168.0.254";

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);
void setup()
{
//Ethernet.begin(mac, ip, dns, gateway, subnet);
Ethernet.begin(mac, ip, gateway, subnet);

delay(1500);
mqttClient.setServer(server, 1883);

if (mqttClient.connect("myClientID")) 
{
  //connection success
} else
{
  //connection failed
}

}

void loop() {
  mqttClient.loop();

}
