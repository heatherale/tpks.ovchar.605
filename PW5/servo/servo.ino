#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "47c9d3d8bc924cc1b592cd64d63d6a96";
char ssid[] = "5G";
char pass[] = "ovchar21510617";

Servo servo;

BLYNK_WRITE(V3) {
servo.write(param.asInt());
}

void setup() {
Blynk.begin(auth, ssid, pass);
servo.attach(15); // 15 means D8 pin of ESP8266
}

void loop()

{
Blynk.run(); 
}
