void setup() {
  Serial.begin(9600);  

}

void loop() {
  if(Serial.available()>0){
    String Data = Serial.readStringUntil('\n');
    Serial.println(Data);
  }
}
