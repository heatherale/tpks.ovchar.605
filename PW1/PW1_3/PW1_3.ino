#include <ESP8266WiFi.h>

const char* ssid = "5G";
const char* password = “ovchar1510617";
const char* host = “www.facebook.com";

void setup() {
Serial .begin (115200) ;
Serial.printin();
Serial.println ();

Serial.print ("Connecting to ");
Serial.println (ssid) ;
WiFi.begin(ssid, password) ;

while (WiFi.status() != WL_CONNECTED) {
delay (S00) ;

Serial.print(".");

}

Serial.println("");

Serial.printin ("WiFi connected") ;
Serial.println ("IP address: ");

Serial.println (WiFi.localIP());
}
int value = 0;

void loop() {
Serial.print ("Connecting to ");
Serial.println (host) ;
WiFiClient client;
const int httpPort = 80;
if (!client.connect (host, httpPort)) {
Serial.printin("connection failed");
return;
}

client.print (String("GET /") + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" + "Connection: close\r\n\r\n") ;
delay (10);
while (client.available()) {
String line = client.readStringUntil('\r');

Serial.print (line) ;

}

Serial.printin();

Serial.printin ("closing connection") ;

delay (5000) ;

}
