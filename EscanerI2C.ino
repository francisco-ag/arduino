#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial); // Espera a que el puerto serie se inicie
  Serial.println("\nI2C Scanner");
}

void loop() {
  Serial.println("Escaneando...");
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    // Inicia la comunicación con la dirección I2C
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado en la dirección 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println();
      nDevices++;
    } else if (error == 4) {
      Serial.print("Error en la dirección 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0) {
    Serial.println("No se encontraron dispositivos I2C\n");
  } else {
    Serial.print("Se encontraron ");
    Serial.print(nDevices);
    Serial.println(" dispositivos I2C\n");
  }

  delay(5000); // Espera 5 segundos antes de escanear de nuevo
}
