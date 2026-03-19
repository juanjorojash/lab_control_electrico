// Hacer un #define para que la libreria TimerInterrupt cargue el Timer3
#define USE_TIMER_3 true
// Definir PIN para el reloj
#define PIN_CLK 2
// Definir el intervalo del timer en milisegundos
#define TIMER_INTERVAL_MS 500
// Incluir librería para interrupciones basadas en tiempo
#include "TimerInterrupt.h"
// Definir variable para levantar la bandera del timer
bool timer_flag = true;
// Definir variable para el estado del PIN_CLK
bool pin_clk_state = true;

void setup() {
  // Inicializar el puerto serial
  Serial.begin(9600);
  // Inicializar el Timer 3
  ITimer3.init();
  // Setear PIN_CLK como salida
  pinMode(PIN_CLK, OUTPUT);
  // Asignar una interrupción por tiempo que ejecuta la función "TimerHandler"
  if (ITimer3.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler))
  {
    Serial.print(F("Starting  ITimer3 OK, millis() = ")); Serial.println(millis());
  }
  else
    Serial.println(F("Can't set ITimer3. Select another freq. or timer"));
}

void TimerHandler()
{
  pin_clk_state = !pin_clk_state;
  // Cuando se activa la función se sube la bandera
  digitalWrite(PIN_CLK, pin_clk_state);
  timer_flag = true;
}

void loop() {
  if (timer_flag)
  {
    timer_flag = 0;
    Serial.print("toggle");
  }
}