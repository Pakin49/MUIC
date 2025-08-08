import time
import Adafruit_ADS1x15
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

led_pin = 7
GPIO.setup(led_pin,GPIO.OUT)
p = GPIO.PWM(led_pin,100)
p.start(0)
adc = Adafruit_ADS1x15.ADS1115()

GAIN = 1
duty_cycle = 0
while True:
	value = adc.read_adc(0,gain=GAIN)
	if value < 100:
		duty_cycle = 0
	else :
		duty_cycle = value / 300
		if duty_cycle > 100:
			duty_cycle = 100
	p.ChangeDutyCycle(duty_cycle)
	print(duty_cycle)
	time.sleep(0.5)
