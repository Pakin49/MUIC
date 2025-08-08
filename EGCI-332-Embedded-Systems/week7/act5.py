import time
import Adafruit_ADS1x15

from luma.led_matrix.device import max7219
from luma.core.interface.serial import spi, noop
from luma.core.virtual import viewport, sevensegment

adc = Adafruit_ADS1x15.ADS1115()

GAIN = 1

while True:
	value = adc.read_adc(0,gain=GAIN)

	serial = spi(port=0, device=0, gpio=noop())
	device = max7219(serial, cascaded=1)
	seg = sevensegment(device)
	print(value)
	seg.text = str(value)

	time.sleep(0.5)
