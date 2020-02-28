# Teslaplot3D
This is a description of a project that I did for Tesla(techfest of EE department) in my college. The objective is to represent a virtual 3D visualization of a room in which the circuit is kept.

Components Required:

Hardware:
1.	Arduino microcontroller
2.	Pan and Tilt servo mount
3.	Jumper wires
4.	Ultrasonic sensor

Software:

1.	Arduino IDE
2.	Pycharm 
3.	Local Host

Working:

The ultrasonic sensor is used to locate different obstacles in the room.
This is achieved by rotating it in horizontal and vertical directions by means of a Pan and tilt servo mount. 
This apparatus gives the following information:

•	Radial distance b/w the sensor and the obstacle(cm)

•	Horizontal angle rotated(degrees)

•	Vertical angle rotated(degrees)

This information is transferred from the Arduino to a processing software. In this project, a python-based IDE called Pycharm is used. The serial port transfers the data. It requires importing of pyserial 3.4 and vpython 7.6 libraries for the same.
Pyserial is used to acquire the data from the serial port. Vpython is the library that enables the plotting of 3D shapes.
The program converts the information which is in the spherical coordinate system to the rectangular system and plots a point in 3D space. The output is displayed in a local web page.
