import serial, time
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
time.sleep(1) #give the connection a second to settle
arduino.write("n")

