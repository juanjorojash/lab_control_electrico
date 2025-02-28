    /*
    Instituto Tecnológico de Costa Rica
    Laboratorio de Control Eléctrico.
    
    Este programa prende el LED cuando se presiona el botón. 
    */
    // Declaracione de entradas y salidas
    const int BUTTON = 2;  // Boton conectado al pin 2
    const int LED = 4;     // LED conectado al pin 4
    
    // CONFIGURACION DE ENTRADAS Y SALIDAS
    void setup() {
        pinMode(LED, OUTPUT);    // configuramos el pin del LED como salida
        digitalWrite(LED, HIGH);  // Encendemos el LED
        pinMode(BUTTON, INPUT);  // configuramos el pin del botón como entrada
    }
    // PROGRAMA PRINCIPAL
    void loop() {
        bool buttonState = !digitalRead(BUTTON);  // leemos el estado del botón
        if (buttonState == HIGH) {
            digitalWrite(LED, HIGH);  // apagamos el LED
        } else {
            digitalWrite(LED, LOW);   // encendemos el LED
        }
    }