/*
		Instituto Tecnológico de Costa Rica
		Laboratorio de Control Eléctrico.
		Lab #1: Conectiva logicas y señal analógica
		Fecha: 24/01/2023
		Ing. Luis D. Murillo
		
		Implementación de Funciones Lógicas AND, OR, XOR, NAND, NOR de 2 entradas
		*/
		// Declaracione de constantes
			const int PinEntrada[2]={2,3};
			const int PinSalidas[5]={4,5,6,7,8};
			const int PinAnalogico[2] = {A0, A1};
			int ValorAnalojLeido[2]={0,0};
			float ValorVoltage[2]={0.0,0.0};
			boolean Mapa_entradas[2];
			boolean ResultadoLogico[5]={false, false, false, false, false};
		
		// Configuracion de Pines de entrada y salida
		void setup(){
			Serial.begin(115200);
			// Serial.println("-----");
			// Serial.println((sizeof(PinEntrada)/2));
			// Serial.println((sizeof(PinSalidas)/2));
			// Serial.println("-----");
		
		// Initializa los pines:
		for (int i = 0; i < (sizeof(PinSalidas)/2); i++) {
			if (i<(sizeof(PinEntrada)/2)) {
				pinMode( PinEntrada[i], INPUT);
			}
			pinMode(PinSalidas[i], OUTPUT);
			}
		delay(2);
		}
		
		void loop()
		{		
			//LECTURA DE LAS ENTRADAS Y SALIDAS 	
			for(int i=0; i<(sizeof(PinSalidas)/2);i++){
				if(i<(sizeof(PinEntrada)/2)){
					// Lectura de entradas digitales
					Mapa_entradas[i]=digitalRead(PinEntrada[i]);
					// Lectura de los valores analógicos
					ValorAnalojLeido[i] = analogRead(PinAnalogico[i]);
					// Funcion de mapeo :
				ValorVoltage[i]= (map(ValorAnalojLeido[i], 0, 1023, 0, 500)/100.0);
				}
			// Escritura de salida digital
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
      delay(1);
		}
		
		//DEFINICION DE LAS FUNCIONES LÓGICAS
		// Forma de programacion Booleana
		bool AND (bool X, bool Y ){
		return (X && Y ); 
		}
		
		// Forma de programacion con estructuras de control
		bool OR (boolean X, bool Y ){
		if (X || Y) {return true;} 
		else {return false;}
		}
		
		// Completar código
		bool XOR (bool X, bool Y ){
			return (X ^ Y); 
		}
		
		bool NAND (bool X, bool Y ){
			return !(X && Y); 
		}		
		
		bool NOR (bool X, bool Y ){
			return !(X || Y); 
		}