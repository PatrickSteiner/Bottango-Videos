#include "Adafruit_NeoPixel.h"

#define LED_PIN   7
#define NUM_LEDS  4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


.
.
.


    void onOnOffCustomEventOnOffChanged(AbstractEffector *effector, bool on)
    {
        char effectorIdentifier[9];
        effector->getIdentifier(effectorIdentifier, 9);

        if (strcmp(effectorIdentifier, "led") == 0) {
          pixels.begin();

          if ( on == 1) {
            pixels.fill(pixels.Color(0,150,0), 0, NUM_LEDS);
          } else {
            pixels.clear();
          }

           pixels.show();
           
        }  
    }
