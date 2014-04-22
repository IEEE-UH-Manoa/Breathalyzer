/*
 * Sample DrinkShield Sketch
 *
 * Used for simple standalone usuage of the drinkshield.
 * Records results at all times (no ready lights)
 *
 * Craig Smith <craig@gfxhax.com>
 */
 
#include "DrinkShield.h"

// 0.1 is the version written on the DrinkShield board
DrinkShield ds(0,1);

int highscoreLed = 0;  // The highest LED
int lightLevel;        // Current LED level

void setup()
{
    // Take 20 air samples when we first turn on the system
    ds.autocalibrate(20);

    // Turn on the Ready light and turn off the rest
    ds.greenLight(ON);
    ds.redLight(OFF);
    ds.lightBarLevel(0, 0);
    ds.christmas_setup();
}

void loop()
{
    ds.christmas_setup();
    int val = ds.getReading();
    // NERF VAL HERE!

    if(val) {  
        // Get & display a reading
        lightLevel = ds.getLightLevel(val);
        if(lightLevel > highscoreLed)
          highscoreLed = lightLevel;

        //highscoreLed = highscoreLed + 2;

        ds.lightBarLevel(lightLevel, highscoreLed); 
        // highscoreLed (1-8) 
        //if(highscoreLed < 6) {
          //highscoreLed = highscoreLed+2;
        //}
        ds.christmas(highscoreLed);
        highscoreLed = 0;
    } 

    //else if(highscoreLed) {  // Done.  Flash and reset
    //    for(int cnt=0; cnt < 4; cnt++) {
    //     ds.lightBarLevel(0, highscoreLed);
    //     //delay(100);
    //     ds.lightBarLevel(0, 0);
    //     //delay(100); 
    //    }
    //    highscoreLed = 0;
    //  }

    highscoreLed = 0;  
    ds.christmas_setup();
}
