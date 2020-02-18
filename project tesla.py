from vpython import *
import serial

window = canvas(title="Output Screen")
window.width = 1000
window.height = 600
C = points(color=color.green, radius=0.9)
arduino = serial.Serial('com7', 9600)
n = 0

while 1:
    rate(180)
    if arduino.inWaiting() > 0:
        data = arduino.readline().decode('ascii')
        n = n + 1
        variables = data.split(' ')
        r = float(variables[0])
        angle1 = int(variables[1])
        angle2 = float(variables[2])
        print(r, " ", angle1, " ", angle2)
        angle1 = angle1*(3.14/180.0)
        angle2 = 90-angle2 
        angle2 = angle2*(3.14/180.0)
        V = vector(r*sin(angle2)*cos(angle1), r*sin(angle2)*sin(angle1), r*cos(angle2))
        C.append(V)
        if angle2 == (3.14/180):
            print(n)
            break
