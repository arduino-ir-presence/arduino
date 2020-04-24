
int ledPin = 13;                // LED 
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {
 pinMode(LED_BUILTIN, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == LOW) {            // if no motion detected
   digitalWrite(LED_BUILTIN, HIGH);  // turn LED ON
   //send to server 
 } 
 else { 
   digitalWrite(LED_BUILTIN, LOW); // turn LED OFF if we have no motion
 }
} 
