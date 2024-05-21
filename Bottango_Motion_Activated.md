# This following code needs to go into GeneratedCommandStream.cpp

// Motion Sensor stuff
const int motionPin = 26;
int pirState = LOW;
bool motionTrigger = false;

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

if (motionTrigger && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
{
    BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
    motionTrigger = false;
}
