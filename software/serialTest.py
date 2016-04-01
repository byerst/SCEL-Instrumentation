import csv
import serial
import time

#confiugre serial connection for usb
ser = serial.Serial(port = '/dev/tty.usbmodem1411',baudrate = 9600)

time.sleep(5)
while 1:
	test = raw_input('Enter input: ')
	ser.write(test)

	print ser.in_waiting
	while ser.in_waiting:
		with open('test.csv', 'rb') as csvfile:
			dataWriter = csv.writer(csvfile, delimeter = ' ', quotechar = '|', quoting = csv.QUOTE_MINIMAL)
			dataWriter.writerow([ser.readline()])
			print ser.readline()
		
