import sys
import serial
import RPi.GPIO as GPIO
import time


## GPIO PINS CONF##
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(22, GPIO.OUT)
GPIO.setup(26, GPIO.OUT)


ser = serial.Serial('/dev/ttyS0', 115200, timeout=2.0 )       #Open serial po$

print('Openning serial port ')
#print(ser.name)         # check which port was really used

ser.close()
ser.open()

GPIO.output(26,GPIO.HIGH)
time.sleep(2)
GPIO.output(26,GPIO.LOW)
time.sleep(1)
ser.write('AT\r\n')

read_val = ser.readline()
test=read_val.encode("hex")
#print test
if  test == '41540d0d0a':
        print('got  OK')
        GPIO.output(26,GPIO.HIGH)
        time.sleep(0.5)
        GPIO.output(26,GPIO.LOW)
        time.sleep(0.25)
        GPIO.output(26,GPIO.HIGH)
        time.sleep(0.5)
        GPIO.output(26,GPIO.LOW)
else:
        print('test NOK')
        GPIO.output(26,GPIO.HIGH)
        time.sleep(0.250)
        GPIO.output(26,GPIO.LOW)
        time.sleep(0.250)
        GPIO.output(26,GPIO.HIGH)
        time.sleep(0.250)
        GPIO.output(26,GPIO.LOW)
        time.sleep(0.250)
        GPIO.output(26,GPIO.HIGH)
        time.sleep(0.250)
        GPIO.output(26,GPIO.LOW)
#print read_val
ser.close()             # close port
