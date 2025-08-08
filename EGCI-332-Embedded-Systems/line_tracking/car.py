import time
import RPi.GPIO as GPIO

#GPIO setup 
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

#----- sensor -----
left_sensor = 11
center_sensor = 13
right_sensor = 15
GPIO.setup(left_sensor, GPIO.IN)
GPIO.setup(center_sensor, GPIO.IN)
GPIO.setup(right_sensor,GPIO.IN)

#----- motor output -----
#left
in1 = 32 # Front
in2 = 36 # Back
enA = 38 # PWM L
GPIO.setup(in1, GPIO.OUT)
GPIO.setup(in2, GPIO.OUT)
GPIO.setup(enA, GPIO.OUT)
pl = GPIO.PWM(enA,1000)
pl.start(0)

#right
in3 = 29 # Front
in4 = 31 # Back
enB = 33 # PWM R
GPIO.setup(in3, GPIO.OUT)
GPIO.setup(in4, GPIO.OUT)
GPIO.setup(enB, GPIO.OUT)
pr = GPIO.PWM(enB,1000)
pr.start(0)

# assume white = low, black = high
while True:
    default_cycle = 75 # default duty_cycle
    # Get value from the IR sensors
    left = GPIO.input(left_sensor)
    center = GPIO.input(center_sensor)
    right = GPIO.input(right_sensor)

    if left and right and center: # DETECT ENDLINE STOP
       # left motor
        GPIO.output(in1,GPIO.HIGH)
        GPIO.output(in2,GPIO.LOW)
        pr.ChangeDutyCycle(default_cycle)
        # right motor
        GPIO.output(in3,GPIO.HIGH)
        GPIO.output(in4,GPIO.LOW)
        pl.ChangeDutyCycle(default_cycle) 

    if (not left) and (not right) and center: # FOWARD
        # left motor
        GPIO.output(in1,GPIO.HIGH)
        GPIO.output(in2,GPIO.LOW)
        pr.ChangeDutyCycle(default_cycle)
        # right motor
        GPIO.output(in3,GPIO.HIGH)
        GPIO.output(in4,GPIO.LOW)
        pl.ChangeDutyCycle(default_cycle)

    elif left: # turn left
       # left motor
        GPIO.output(in1,GPIO.LOW)
        GPIO.output(in2,GPIO.HIGH)
        pr.ChangeDutyCycle(default_cycle)
        # right motor
        GPIO.output(in3,GPIO.HIGH)
        GPIO.output(in4,GPIO.LOW)
        pl.ChangeDutyCycle(default_cycle)

    elif right: # Turn left
       # left motor
        GPIO.output(in1,GPIO.HIGH)
        GPIO.output(in2,GPIO.LOW)
        pr.ChangeDutyCycle(default_cycle)
        # right motor
        GPIO.output(in3,GPIO.LOW)
        GPIO.output(in4,GPIO.HIGH)
        pl.ChangeDutyCycle(default_cycle) 