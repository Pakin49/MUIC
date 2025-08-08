import RPi.GPIO as GPIO
import time
import Adafruit_ADS1x15
import lcddriver
import datetime

from luma.led_matrix.device import max7219
from luma.core.interface.serial import spi, noop
from luma.core.virtual import viewport, sevensegment

#lcd
lcd = lcddriver.lcd()

#7segment
serial = spi(port = 0, device = 0, gpio=noop())
device = max7219(serial, cascaded = 1)
seg = sevensegment(device)

# ADC setup
adc = Adafruit_ADS1x15.ADS1115()
GAIN = 1

# LED
led_pin = 7
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(led_pin,GPIO.OUT)
p = GPIO.PWM(led_pin,100)
p.start(0)
duty_cycle = 0

while True:
	value = adc.read_adc(0,gain = GAIN)
	if value < 0:
		value = 0
	seg.text = str(value)
	duty_cycle = (value/300)
	if duty_cycle > 100:
		duty_cycle = 100
	p.ChangeDutyCycle(duty_cycle)
	if value < 10000:
		status = "Low"
	elif value < 25000:
		status = "Medium"
	else :
		status  = " High"
	lcd.lcd_clear()
	lcd.lcd_display_string(str(value),1)
	lcd.lcd_display_string(status,2)
	f = open('/home/egco/Desktop/embedded/lab_exam/raw.txt','a')
	now = datetime.datetime.now()
	Date = now.strftime("%d/%m/%Y")
	timestamp = now.strftime("%H:%M:%S")
	output = str(Date) + " " + str(timestamp) + ": " + str(value) + ", " +  status + "\n"
	print(output)
	f.write(output)
	time.sleep(1)
