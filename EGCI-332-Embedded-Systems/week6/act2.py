import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

button_pin = 5
GPIO.setup(button_pin,GPIO.IN)

while True:
	if(GPIO.input(button_pin) == 1):
		print("Release")
	else:
		print("Push")
	time.sleep(1)
