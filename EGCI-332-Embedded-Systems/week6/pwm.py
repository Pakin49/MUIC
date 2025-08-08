import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

led_pin = 7
GPIO.setup(led_pin,GPIO.OUT)
p = GPIO.PWM(led_pin,100)
p.start(0)

while(True):
	for x in range (0,101,10):
		print(x)
		p.ChangeDutyCycle(x)
		time.sleep(0.1)

	for x in range (100,-1,-10):
		print(x)
		p.ChangeDutyCycle(x)
		time.sleep(0.1)

