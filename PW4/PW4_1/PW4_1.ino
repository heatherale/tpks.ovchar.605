#include <ESP8266WiFi.h>

const char* ssid = "5G";
const char* password = "ovchar21510617";

const char* host = "maker.ifttt.com";
const char* eventName = "hello";

const char* key = Wt RRR IR IK RIO IO RK Rk kK RK IK KK KEN»


setup(){
Serial.println();
Serial.println();
Serial.print ("Connecting to ");
Serial.printl1n (ssid) ;
WiFi.begin(ssid, password) ;
while (WiFi.status() != WL_CONNECTED) {
delay (500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected") ;
Serial.println("IP address: ");
Serial. println (WiFi.localIP());
}

loop(){
WiFiClient client;
const int httpPort = 80;
if (!client.connect (host, httpPort)) {
Serial.println ("connection failed") ;
return;
}

String url = "/trigger/";
url += eventName;
url += "/with/key/";
url += key;
client. print (String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
int timeout = millis() + 5000;
while (client.available() == 0) {
if (timeout - millis() < 0) {
Serial.printin(">>> Client Timeout !");
client.stop();
return;
}
while (client.available()){
String line = client. readStringUntil('\r");
Serial.print (line) ;
}
delay(60 * 1000);
}
