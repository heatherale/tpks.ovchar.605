#include <ESP8266WiFi.h>

void setup (void)
{
Serial .begin (115200) ;
pinMode(5, INPUT); 
}

void loop() {
Serial.print ("State of GPIO 5: ");
Serial.println (digitalRead (5) );
delay (1000) ;
}
