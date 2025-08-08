import time
import Adafruit_ADS1x15
import RPi.GPIO as GPIO

from luma.led_matrix.device import max7219
from luma.core.interface.serial import spi, noop
from luma.core.virtual import viewport, sevensegment

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
button_pin = 5
GPIO.setup(button_pin,GPIO.IN,GPIO.PUD_UP)

serial = spi(port=0, device=0, gpio=noop())
device = max7219(serial, cascaded=1)
seg = sevensegment(device)

def button_pressed_callback(chennel):
	global count
	count = count + 1

GPIO.add_event_detect(button_pin,GPIO.FALLING,button_pressed_callback,bouncetime=200)

count = 0
while True:
	seg.text = str(count)
	time.sleep(0.2)