
// Simple Siren by V205.
// Thank you to Arduino. 
// constants won't change. Used here to set a pin number:
const int piezoPin = 7;  // the number of the piezo pin

// Try playing around with these constants.
const int updateInterval = 10; //The interval that the siren's pitch is updated at in milliseconds(there are 1000 milliseconds in a second)
const int pitchHighBoundary = 700;//the siren will go to this pitch then go back again.
const int pitchLowBoundary = 600;// the siren will go to this pitvh then the pitch will go up again.
const int pitchChange = 10;//This is the amount that the pitch changes with everytime the pitch is updated.
void setup() {
  // Set piezo Pin to output.
  pinMode(piezoPin, OUTPUT);
  //Begin Serial comms.
  Serial.begin(9600);
  delay(1000);
  Serial.println("Simple Siren by V205.");
  Serial.print("piezoPin = " );
  Serial.println(piezoPin);
  Serial.print("updateInterval = ");
  Serial.println(updateInterval);
  Serial.print("pitchHighBoundary = ");
  Serial.println(pitchHighBoundary);
  Serial.print("pitchLowBoundary = ");
  Serial.println(pitchLowBoundary);
  Serial.print("pitchChange = ");
  Serial.println(pitchChange);

  
 

 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pitch = pitchLowBoundary; pitch <= pitchHighBoundary; pitch+=pitchChange) {
    tone(piezoPin,pitch);
    Serial.print("pitch = ");
    Serial.println(pitch);
    delay(updateInterval);
  }
  for (int pitch = pitchHighBoundary; pitch >= pitchLowBoundary; pitch-=pitchChange) {
    tone(piezoPin,pitch);
    Serial.print("pitch = ");
    Serial.println(pitch);
    delay(updateInterval);
  }



}
