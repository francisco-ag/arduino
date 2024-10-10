int potPin = A0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Prueba potenciometro");
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  Serial.println("Valor del potenciometro : ");
  Serial.println(potValue);
  delay(500);
}