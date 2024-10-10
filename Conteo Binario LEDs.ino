
//Definimos pines a usar
int ledPin[] = {8,9,10,11};

void setup() {
  for(int i= 0; i<4; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  for(int number=0; number<16; number++){
      //Recorremos numeros de 0-16 bits
       
    getBinary(number);
    delay(1000);
   
  }
   
 
}


// Conversion a Binario con Desplazamiento de Bits
void getBinary(int number){
    for(int i= 0; i<4; i++){
        int bit = (number >> i) & 0x01;
          digitalWrite(ledPin[i],bit);
      }
}






