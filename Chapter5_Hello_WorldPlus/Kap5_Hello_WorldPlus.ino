int loopCount;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Opened serial connection!\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello World!") ;
  Serial.print("(");
  Serial.print(loopCount);
  Serial.println(")");

  loopCount++;
  delay(1000);
}
