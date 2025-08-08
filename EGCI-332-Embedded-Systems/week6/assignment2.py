import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
button_pin = 5
GPIO.setup(button_pin,GPIO.IN)
led_pin = 7
GPIO.setup(led_pin,GPIO.OUT)

i = 0
PS,CS = 1,1
while(True):
	PS = CS
	CS = GPIO.input(button_pin)
	if(PS==1 and CS==0):
		i+=1
	if(i%4==0 and i!=0):
		GPIO.output(led_pin,GPIO.HIGH)
	else:
		GPIO.output(led_pin,GPIO.LOW)
	time.sleep(0.02)
