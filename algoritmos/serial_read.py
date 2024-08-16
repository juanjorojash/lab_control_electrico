# Taller de visualización de datos en Python a través
# comunicación serial con arduino
from datetime import datetime
import serial
import pandas as pd
import matplotlib.pyplot as plt
from drawnow import drawnow
import csv

# Inicializa el serial
ArduinoData = serial.Serial('COM9', baudrate=115200, bytesize=8,
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
aXdata = []
aYdata = []
list = []

# Crear la canvas para la figura
plt.ion()     # tell matplotlib you want interactive mode to plot data
fig = plt.figure()

def in_figure() -> None:
    # Función para "imprimir" los últimos 100 datas de distancia
    ax1 = plt.subplot()
    plt.plot(time_data[-100:], Xdata[-100:])
    plt.plot(time_data[-100:], aXdata[-100:])
    plt.plot(time_data[-100:], Ydata[-100:])
    plt.plot(time_data[-100:], aYdata[-100:])
    ax1.set(xlabel='time (s)', ylabel='X',
            title='measurements')

filename = "test1.csv"


def csv_write(filename):
    with open(filename, "w+", newline="") as file:
        write = csv.writer(file)
        write.writerows(list)


recep = ArduinoData.read_until(b'\r\n')
recep = ArduinoData.read_until(b'\r\n')
while True:
    # Lee el primer byte de la información transmitidad por
    #  en el serial
    seconds += 1 
    X_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    X = bool(X_text)
    aX_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    aX = float(aX_text)
    Y_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    Y = bool(Y_text)
    aY_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    aY = float(aY_text)
    f_and_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    f_or_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    f_xor_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    f_nand_text = ArduinoData.read_until(b',')[:-1].decode("ascii")
    f_nor_text = ArduinoData.read_until(b'\r\n')[:-2].decode("ascii")


    tiempo_actual = datetime.now()
    deltat = (tiempo_actual - past_time).total_seconds()
    past_time = tiempo_actual
    seconds += deltat
    seconds_text = str(round(seconds,6))
    list.append([seconds_text, X_text, aX_text, Y_text, aY_text, f_and_text, f_or_text, f_xor_text, f_nand_text, f_nor_text])
    csv_write(filename)
    time_data.append(seconds)
    Xdata.append(X)
    aXdata.append(aX)
    Ydata.append(Y)
    aYdata.append(aY)
    drawnow(in_figure)
    
