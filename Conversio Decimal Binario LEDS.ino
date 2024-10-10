/Definimos pines a usar
int ledPin[] = {8,9,10,11};

void setup() {
  for(int i= 0; i<4; i++){
    pinMode(ledPin[i], OUTPUT);
  }  
  Serial.begin(9600);
  Serial.println("Ingresa un numero decimal 0-15:");  
}

void loop() {
  if(Serial.available()>0){
      int decimal = Serial.parseInt();  
    if(decimal >= 0 && decimal <=15){
       int binary[4]; //Array limitado a los 4 bits
       decimalToBinary(decimal, binary);
       displayBinary(binary);
       Serial.print("Mostrando numero decimal");
       Serial.println(decimal);
       Serial.print("en binario en los LEDS");    
    }else{
      Serial.print("Ingresa un numero entre 0-15");
    }  
  }
}


void decimalToBinary(int decimal,int binary[]){
  for(int i=3; i>=0; i--){
      binary[i] = decimal%2;
    decimal = decimal/2;            
  }
}  

void displayBinary(int binary[]){
  for(int i=0; i<4; i++){
      digitalWrite(ledPin[i], binary[i]);
  }
}