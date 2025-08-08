import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(02,GPIO.OUT)

while True:
	GPIO.output(02,GPIO.HIGH) #led on
	time.sleep(1)
	GPIO.output(02,GPIO.LOW) #led off
	time.sleep(1)

