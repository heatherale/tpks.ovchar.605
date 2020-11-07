#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <aREST.h>

WiFiClient espClient;
PubSubClient client (espClient) ;
aREST rest = aREST (client);
char* device id = "Su2co4";
const char* ssid = "5G";
const char* password = "ovchar21510617";
void callback(char* topic, byte* payload, unsigned int length);
void setup (void)
{
Serial. begin (115200) ;
client.setCallback (callback) ;
rest.set_id(device_id);
rest.set_name ("devices control");
WiFi.begin(ssid, password) ;
while (WiFi.status() != WL_CONNECTED) {
delay (500) ;
Serial.print(".");
}
Serial.printin("");
Serial.println ("WiFi connected") ;
char* out_topic = rest.get_topic();
}

void loop() {
rest.handle (client) ;
}
void callback(char* topic, byte* payload, unsigned int length) {
rest.handle callback(client, topic, payload, length);
}
