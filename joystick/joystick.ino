void setup() {
  Serial.begin(9600);
}

void loop() {
  int xAxis = analogRead(A0);
  int yAxis = analogRead(A1);
  Serial.print("x");
  Serial.print(xAxis);
  Serial.print(" y");
  Serial.print(yAxis);
  Serial.println();
  delay(500);
}
