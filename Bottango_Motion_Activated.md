# Replace the code in GeneratedCommandStream.cpp with this

```

#include "GeneratedCommandStreams.h"

namespace GeneratedCommandStreams
{

    //// !!! Insert/edit your animation triggering and playback logic here !!! ////
    /* Some helpful methods:

        BottangoCore::commandStreamProvider.streamIsInProgress()                                        //returns if any animation is currently playing
        BottangoCore::commandStreamProvider.startCommandStream(byte animationID, bool looping)          //starts playing an animation (and stops the current if any)
        BottangoCore::commandStreamProvider.stop()                                                      //stops the current playing animation, if any
    */

    /* Animations key:
        0 - Slow
    */

    bool playBegan = false;
    bool playOnStart = false;
    bool loop = false;
    byte startingAnimation = 0;

    // Motion Sensor stuff
    const int motionPin = 26;
    int pirState = LOW;
    bool motionTrigger = false;

  

    // called once per update loop, your logic probably goes here.
    void updatePlayStatus()
    {
        pinMode(motionPin, INPUT); 

        if (digitalRead(motionPin) == HIGH) {
           if (pirState == LOW) {
             motionTrigger = true;
             pirState = HIGH;
           }
         } else {
           if (pirState == HIGH){
             pirState = LOW;
           }
        }

        // if haven't started any animations, or if should loop and nothing is playing (IE the last loop ended)
        if (motionTrigger && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
        {
            BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
            motionTrigger = false;
        }

        if (playOnStart && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
        {
            BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
            playBegan = true;
        }
    }

    //// ----------------------------------------- /////

    //// GENERATED CODE. You probably don't need to change any of the below ////
    const char SETUP_CHAR_STREAM[] PROGMEM = "rECOnOff,led,1,255\nrECColor,eyeColor,0,255,255\n";
    const char STREAM_SLOW_CHAR_STREAM[] PROGMEM = "sCO,led,0,1\nsCC,eyeColor,0,2033,0,255,255,1,255,255\nsCC,eyeColor,2033,1967,1,255,255,2,255,255\nsCC,eyeColor,4000,4000,2,255,255,3,255,255\nsCC,eyeColor,8000,4000,3,255,255,4,255,255\nsCO,led,13000,0\nsCO,led,14000,0\n";
    const char STREAM_SLOW_CHAR_STREAM_LOOP[] PROGMEM = "sCO,led,0,1\nsCC,eyeColor,14000,0,4,255,255,0,255,255\n";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_Slow = CommandStream(STREAM_SLOW_CHAR_STREAM, 14000, STREAM_SLOW_CHAR_STREAM_LOOP, 0);    

    CommandStream *getCommandStream(byte streamID)
    {
        switch (streamID)
        {
        case 0:
            return &stream_Slow;
        default:
            return NULL;
        }
    }

    CommandStream *getSetupCommandStream()
    {
        return &setupStream;
    }
} // namespace GeneratedCommandStreams


```
