import serial
import time
import MySQLdb
import re


var = raw_input("Serial Port : ")

ser = serial.Serial(var, 9600, timeout=0)

time.sleep(5)

while 1:
    try:


        ldrval = ser.readline()
        wtrlvl = ser.readline()
        humidi = ser.readline()
        tempt = ser.readline()
        pwrlvl = ser.readline()

        print ldrval
        print wtrlvl
        print humidi
        print tempt
        print pwrlvl




        #establish connection to MySQL Database
        dbConn = MySQLdb.connect("localhost","root","secret2","arduino") or die ("could not connect to database")
        #open a cursor to the database
        cursor = dbConn.cursor()

        cursor.execute('INSERT INTO interlista (ldrval,wtrlvl,humidi,tempt,pwrlvl) VALUES (%s,%s,%s,%s,%s)',(ldrval,wtrlvl,humidi,tempt,pwrlvl))
        dbConn.commit() #commit the insert
        cursor.close()  #close the cursor
        time.sleep(2)


    except serial.SerialTimeoutException:
        print('Data could not be read')
    time.sleep(1)
