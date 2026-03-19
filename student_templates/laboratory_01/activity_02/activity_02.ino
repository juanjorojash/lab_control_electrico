/*
Instituto Tecnológico de Costa Rica
Laboratorio de Control Eléctrico.
Lab #1: Introducción a Arduino
Implementación de funciones lógicas AND, OR, XOR, NAND, NOR de 2 entradas
*/


// Declaracione de constantes
  const int PinEntrada[2]={2,3};
  const int PinSalidas[5]={4,5,6,7,8};
  const int PinAnalogico[2]={A0,A1};
  int ValorAnalojLeido[2]={0,0};
  float ValorVoltage[2]={0.0,0.0};
  boolean Mapa_entradas[2];
  boolean ResultadoLogico[5]={false, false, false, false, false};

// Configuracion de Pines de entrada y salida
void setup(){
  Serial.begin(115200);
  Serial.println("-----");  
// Initializa los pines:
for (int i = 0; i < 2; i++) {
  pinMode(PinEntrada[i], INPUT);
}
for (int i = 0; i < 5; i++) {
  pinMode(PinSalidas[i], OUTPUT);
}
delay(2);
}

void loop()
{	
    //Lectura de entradas
    for(int i=0; i < 2; i++){
        Mapa_entradas[i] = digitalRead(PinEntrada[i]);
        ValorAnalojLeido[i] = analogRead(PinAnalogico[i]);
        ValorVoltage[i]= (map(ValorAnalojLeido[i], 0, 1023, 0, 500)/100.0);
    }
    //Escritura de salidas
    for(int i=0; i < 5; i++){
        digitalWrite(PinSalidas[i],ResultadoLogico[i]);
    }    
//EJECUCION DEL PROGRAMA
  ResultadoLogico[0]=AND(Mapa_entradas[1],Mapa_entradas[0]);
  ResultadoLogico[1]=OR(Mapa_entradas[1],Mapa_entradas[0]);
  ResultadoLogico[2]=XOR(Mapa_entradas[1],Mapa_entradas[0]);
  ResultadoLogico[3]=NAND(Mapa_entradas[1],Mapa_entradas[0]);
  ResultadoLogico[4]=NOR(Mapa_entradas[1],Mapa_entradas[0]);

//IMPRESION DE RESULTADOS ENTRADA Y SALIDAS

  Serial.print(Mapa_entradas[0]);
  Serial.print(",");
  Serial.print(ValorVoltage[0]);
  Serial.print(",");
  Serial.print(Mapa_entradas[1]);
  Serial.print(",");
  Serial.print(ValorVoltage[1]);
  Serial.print(",");
  Serial.print(ResultadoLogico[0]);
  Serial.print(",");
  Serial.print(ResultadoLogico[1]);
  Serial.print(",");
  Serial.print(ResultadoLogico[2]);
  Serial.print(",");
  Serial.print(ResultadoLogico[3]);
  Serial.print(",");
  Serial.println(ResultadoLogico[4]);
  delay(10);
}

//DEFINICION DE LAS FUNCIONES LÓGICAS
// Forma de programacion Booleana
bool AND (bool X, bool Y ){
  return (X & Y); 
}

// Forma de programacion con estructuras de control
bool OR (boolean X, bool Y ){
  return (X | Y);
}

// Completar código
bool XOR (bool X, bool Y ){
  return (X ^ Y); 
}

bool NAND (bool X, bool Y ){
  return !(X & Y); 
}		

bool NOR (bool X, bool Y ){
  return !(X | Y); 
}