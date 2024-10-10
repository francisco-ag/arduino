int decimalNumber = 10; // Ejemplo de número decimal

void setup() {
  Serial.begin(9600);
  Serial.print("Decimal: ");
  Serial.println(decimalNumber);
  Serial.print("Binario: ");
  Serial.println(decimalToBinary(decimalNumber));
  Serial.print("Octal: ");
  Serial.println(decimalToOctal(decimalNumber));
  Serial.print("Hexadecimal: ");
  Serial.println(decimalToHex(decimalNumber));

}

void loop() {
  // No se requiere porque se realiza una sola ejecución
}

String decimalToBinary(int num) {
  String binary = "";
  while (num > 0) {
    binary = String(num % 2) + binary;
    num = num / 2;
  }
  return binary;
}

String decimalToOctal(int num) {
  String octal = "";
  while (num > 0) {
    octal = String(num % 8) + octal;
    num = num / 8;
  }
  return octal;
}

String decimalToHex(int num) {
  String hex = "";
  char hexChars[] = {
    '0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  while (num > 0) {
    hex = hexChars[num % 16] + hex;
    num = num / 16;
  }
  return hex;
}
