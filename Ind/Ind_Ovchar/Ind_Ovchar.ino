#include &lt;ESP8266WiFi.h&gt;
#include &lt;BlynkSimpleEsp8266.h&gt;
#define BLYNK_PRINT Serial  
char auth[] = "47c9d3d8bc924cc1b592cd64d63d6a96"; 
char ssid[] = "Ovchar"; 
char pass[] = "14111990"; 

String location = "room";
int rangeMin = 0;
int rangeMax = 50;
 
const int echoPin = D6;
const int trigPin = D7;
 
long duration;
int distance;
int saveDis = 0;
 
SimpleTimer timer;
 
void sensorFire() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  saveDis = distance;
  distance = duration * 0.034 / 2;
}
 
void sensorRead() {
  sensorFire();
  if (rangeMin &lt; distance &amp;&amp; distance &lt; rangeMax) {
    sensorFire();
    if (rangeMin &lt; distance &amp;&amp; distance &lt; rangeMax) {
      Blynk.notify(String(location) + ": Расстояние изменено = " + distance);
    }
  }
}
 
void setup() {
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  Blynk.notify(String(location) + " connected to: " + String(ssid));
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  timer.setInterval(1000L, sensorRead);
}
 
void loop() {
  Blynk.run();
  timer.run();
}
