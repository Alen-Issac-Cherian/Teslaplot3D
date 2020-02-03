from vpython import *
import serial

window = canvas(title="Output Screen")
window.width = 700
window.height = 600

C = curve(color=color.red, radius=0.1)
arduino = serial.Serial('com7', 9600)

while 1:
    rate(30)
    if arduino.inWaiting() > 0:
        data = arduino.readline().decode('ascii')
        variables = data.split(' ')
        r = float(variables[0])
        angle = int(variables[1])
        V = vector((r*cos(angle)), (r*sin(angle)), 0)
        C.append(V)
