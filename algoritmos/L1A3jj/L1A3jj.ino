/*
Instituto Tecnológico de Costa Rica
Laboratorio de Control Eléctrico.

Implementación de funciones lógicas AND, OR, XOR, NAND y NOR de 2 entradas
*/

//Declaración de constantes
const int PinesEntrada[2]={D2,D3};
const int PinesSalida[5]={D4,D5,D6,D7,D8};
const int PinAnalogico[2]={A0,A1};


void setup(){
  Serial.begin(115200);
/*   for (int i = 2; i <= 7; i++){
    if (i <= 3){
      pinMode(i, INPUT);
    }
  } */
}

void loop(){
  Serial.println(PinesEntrada[0]);
  Serial.println(PinAnalogico[0]);
}

