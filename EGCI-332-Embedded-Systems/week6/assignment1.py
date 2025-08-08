import RPi.GPIO as GPIO
import time 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

button_pin = 5
GPIO.setup(button_pin,GPIO.IN)

led_pin = 7
GPIO.setup(led_pin,GPIO.OUT)

while(True):
	if(GPIO.input(button_pin)==0):
		for i in range(0,3):
			GPIO.output(led_pin,GPIO.HIGH) #led on
			time.sleep(1)
			GPIO.output(led_pin,GPIO.LOW) #led off
			time.sleep(1)
