void setup() {
  lcd.begin(16, 2); // Inicializa la pantalla LCD con 16 columnas y 2 filas
 
  // Muestra el valor decimal
  lcd.setCursor(0, 0);
  lcd.print("Decimal: ");
  lcd.print(decimalNumber);
  delay(2000); // Pausa de 2 segundos

  // Limpia la pantalla
  lcd.clear();
 
  // Muestra el valor en binario
  lcd.setCursor(0, 0);
  lcd.print("Binario: ");
  lcd.print(decimalToBinary(decimalNumber));
  delay(2000); // Pausa de 2 segundos

  // Limpia la pantalla
  lcd.clear();

  // Muestra el valor en octal
  lcd.setCursor(0, 0);
  lcd.print("Octal: ");
  lcd.print(decimalToOctal(decimalNumber));
  delay(2000); // Pausa de 2 segundos

  // Limpia la pantalla
  lcd.clear();

  // Muestra el valor en hexadecimal
  lcd.setCursor(0, 0);
  lcd.print("Hexadecimal: ");
  lcd.print(decimalToHex(decimalNumber));
  delay(2000); // Pausa de 2 segundos

  // Limpia la pantalla
  lcd.clear();
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
