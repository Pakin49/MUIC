import RPi.GPIO as GPIO
import time


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
button_pin = 5
GPIO.setup(button_pin,GPIO.IN,pull_up_down = GPIO.PUD_UP)
led_pin = 7
GPIO.setup(led_pin,GPIO.OUT)
led = 0

def button_pressed_callback(chennel):
	global led
	if(led==0):
		GPIO.output(led_pin,GPIO.HIGH)
		led = 1
	else:
		GPIO.output(led_pin,GPIO.LOW)
		led = 0

GPIO.add_event_detect(button_pin,GPIO.FALLING,button_pressed_callback, bouncetime=200)

try:
	message = input("press enter to quit\n")
	GPIO.cleanup()
except:
	print("end")
