import RPi.GPIO as GPIO
import time


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
button_pin = 5
GPIO.setup(button_pin,GPIO.IN,pull_up_down = GPIO.PUD_UP)

def button_pressed_callback(chennel):
	print("button pressed")

GPIO.add_event_detect(button_pin,GPIO.FALLING,button_pressed_callback, bouncetime=200)

try:
	message = input("press enter to quit\n")
	GPIO.cleanup()
except:
	print("end")
