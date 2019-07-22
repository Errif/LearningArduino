

void setup() {
  
  // Use Gener Purpose Input Output (GPIO) 2 as input
  pinMode(2, INPUT);

  // Open a serial connection at 9600 Bd
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(digitalRead(2));
  delay(100);
}
