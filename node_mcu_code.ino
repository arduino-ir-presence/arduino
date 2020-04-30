#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "/Users/sujitvaradhan/arduino_ir_presence/info.h" 

int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                   // PIR status


    
void setup() {
 pinMode(LED_BUILTIN, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(115200);

 WiFi.begin(ssid, pass);   //WiFi connection
 
 while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion

  delay(500);
  Serial.println("Waiting for connection");

 }
}
void loop(){
 pirStat = digitalRead(pirPin); 
// Serial.println(secret);
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(LED_BUILTIN, HIGH);  // turn LED ON
   delay(1000);
   if(WiFi.status()== WL_CONNECTED) {   //Check WiFi connection status
     HTTPClient http;    //Declare object of class HTTPClient
     http.begin(url);      //Specify request destination
//     http.addHeader("Content-Type", "text/plain"); 
     int httpCode = http.POST("secretId=" + secret + "&isOccupied=true");   
     String payload = http.getString();     
     Serial.println(httpCode);   //Print HTTP return code
     Serial.println(payload);    //Print request response payload//Get the response payload
     http.end();  //Close connection
   } else {
      Serial.println("Error in WiFi connection");   
   }

 } 
 else { 
   digitalWrite(LED_BUILTIN, LOW); // turn LED OFF if we have no motion
   Serial.println("here");   
 }
} 
