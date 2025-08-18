import RPi.GPIO as GPIO
import time

# Config GPIO
PIN_MANIP = 21 
GPIO.setmode(GPIO.BCM)
GPIO.setup(PIN_MANIP, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Variables pour mesurer la durée des appuis
t0 = None

print("Écoute du manipulateur... (Ctrl+C pour quitter)")

try:
    while True:
        if GPIO.input(PIN_MANIP) == GPIO.LOW:  # contact fermé
            if t0 is None:
                t0 = time.time()
        else:
            if t0 is not None:
                duree = time.time() - t0
                if duree < 0.25:
                    print(".", end="", flush=True)   # point
                else:
                    print("-", end="", flush=True)   # trait
                t0 = None
        time.sleep(0.01)

except KeyboardInterrupt:
    GPIO.cleanup()
    print("\nFin du programme.")
