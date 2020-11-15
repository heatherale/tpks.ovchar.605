#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           
#include <SimpleTimer.h>   
#define DHTTYPE DHT11      

#define dht_dpin 14
DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;

char auth[] = "47c9d3d8bc924cc1b592cd64d63d6a96";        
char ssid[] = "5G";   
char pass[] = "ovchar21510617";  
float t;                                   


void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  float t = dht.readTemperature();  
  Blynk.virtualWrite(V0, t);
}

void loop()
{
  Blynk.run();
  timer.run();
}
