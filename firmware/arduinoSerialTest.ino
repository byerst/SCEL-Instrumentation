int incomingbyte = 0;
byte receivedString;

void setup(){
	Serial.begin(9600);
}

void loop(){
	if(Serial.available()){
                //Serial.write("Test");
		receivedString = Serial.read();
                //Serial.println(receivedString);
                Serial.write(receivedString);
                Serial.println();
        }
}
