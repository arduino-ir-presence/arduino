#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = ""; 
const char* pass = "";
const char* ip = "";

void setup() {
  Serial.begin(115200);                 //Serial connection
  WiFi.begin(ssid, pass);   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
}

void loop() {
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   
     HTTPClient http;    //Declare object of class HTTPClient
   
     http.begin(ip);      //Specify request destination
//     http.addHeader("Content-Type", "text/plain"); 
   
     int httpCode = http.POST("TEST");   
     String payload = http.getString();                  //Get the response payload
   
     Serial.println(httpCode);   //Print HTTP return code
     Serial.println(payload);    //Print request response payload
   
     http.end();  //Close connection
   
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
}
