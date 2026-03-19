/*
Instituto Tecnológico de Costa Rica
Laboratorio de Control Eléctrico.
Lab #1: Introducción a Arduino
Este programa prende el LED cuando se presiona el botón. 
*/

// Declaraciones de entradas y salidas
const int BUTTON = 2;  // Boton conectado al pin 2
const int LED = 4;     // LED conectado al pin 4

// Configuración
void setup() {
    pinMode(LED, OUTPUT);    // configuramos el pin del LED como salida
    digitalWrite(LED, HIGH);  // Encendemos el LED
    pinMode(BUTTON, INPUT);  // configuramos el pin del botón como entrada
}
//  Programa principal
void loop() {
    bool buttonState = !digitalRead(BUTTON);  // leemos el estado del botón
    digitalWrite(LED, buttonState); // Actualizamos el estado del LED
}