#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "parking-da820-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "iVDc0X7KSx2SF9ZcKFIwUwI3DdFXYAjrVAXMn0V9"
#define WIFI_SSID "arora"
#define WIFI_PASSWORD "pahava0133"

int it;
String st;
FirebaseData a;
FirebaseJson json;
FirebaseData fbdo;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(0, INPUT);
  pinMode(2, INPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Firebase.getString(a, "parking_data/slot-1/block");
  if (a.stringData().toInt()){digitalWrite(14, HIGH);}
  else{digitalWrite(14, LOW);}
  Firebase.getString(a, "parking_data/slot-2/block");
  if (a.stringData().toInt()){digitalWrite(12, HIGH);}
  else{digitalWrite(12, LOW);}
  Firebase.getString(a, "parking_data/slot-3/block");
  if (a.stringData().toInt()){digitalWrite(13, HIGH);}
  else{digitalWrite(13, LOW);}
  Firebase.getString(a, "parking_data/slot-4/block");
  if (a.stringData().toInt()){digitalWrite(15, HIGH);}
  else{digitalWrite(15, LOW);}
  it = digitalRead(5);
  st = String(it);
  Serial.print(st);
  Firebase.setString(fbdo, "parking_data/slot-1/status", st);
  it = digitalRead(4);
  st = String(it);
  Serial.print(st);
  Firebase.setString(fbdo, "parking_data/slot-2/status", st);
  it = digitalRead(0);
  st = String(it);
  Serial.print(st);
  Firebase.setString(fbdo, "parking_data/slot-3/status", st);
  it = digitalRead(2);
  st = String(it);
  Serial.println(st);
  Firebase.setString(fbdo, "parking_data/slot-4/status", st);

}
