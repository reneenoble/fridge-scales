import serial
ser = serial.Serial('COM3', 9600, timeout=0)
while True:
    line = ser.readline()
    if line:
        print line

