# Taller de visualización de datos en Python a través
# comunicación serial con arduino
from datetime import datetime
import serial
import pandas as pd
import matplotlib.pyplot as plt
from drawnow import drawnow

# Inicializa el serial
ArduinoData = serial.Serial('COM8', baudrate=9600, bytesize=8,
                            parity='N', stopbits=1, timeout=1.5)

# verfica que la instancancia serial esté cerrada
ArduinoData.close()

# Abrir la instancia serial
ArduinoData.open()

# Flush: wait until all data is written
ArduinoData.flush()

# Se graba el instante de tiempo actual
past_time = datetime.now()

# crea e inicializa la variable a almacenar el tiempo transcurrido
seconds = 0

# Crea la lista vacía para almacenar el tiempo y la distancia
time_data = []
dist_data = []
Xdata = []
Ydata = []

# Crear la canvas para la figura
plt.ion()     # tell matplotlib you want interactive mode to plot data
fig = plt.figure()

def dist_figure() -> None:
    # Función para "imprimir" los últimos 100 datas de distancia
    ax1 = plt.subplot()
    plt.plot(time_data[-100:], Xdata[-100:])
    ax1.set(xlabel='time (s)', ylabel='X',
            title='measurements')




recep = ArduinoData.read_until(b'\r\n')
while True:
    # Lee el primer byte de la información transmitidad por
    #  en el serial
    seconds += 1 
    X = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    print(X,'\n')
    aX = float(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    print(aX,'\n')
    Y = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    print(Y,'\n')
    aY = float(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    print(aY,'\n')
    f_and = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    f_or = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    f_xor = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    f_nand = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))
    f_nor = bool(ArduinoData.read_until(b',')[:-1].decode("ascii"))

    time_data.append(seconds)
    Xdata.append(X)
    Ydata.append(Y)
    
