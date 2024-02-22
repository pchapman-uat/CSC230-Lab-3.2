// Include the M5StickCPlus library
// This is the core library for the M5StickCPlus
#include <M5StickCPlus.h>

// Declare global variables
// These are the values that will be displayed on the screen
int buttonA = 0;
int buttonB = 0;

void info() {
    // Clear the screen
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    // Display the values
    M5.Lcd.setTextColor(RED);
    // printf allows formatted printing
    // buttonA and buttonB are the values that will be displayed
    M5.Lcd.printf("Button A: %d\n", buttonA);
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.printf("Button B: %d", buttonB);
}


void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(4);
    // Run the info function to display the values
    info();
}

void loop() {
    // Update is needed to get the latest button values
    M5.update();
    // Check if the button was pressed for 2 seconds
    if(M5.BtnB.wasReleasefor(2000)){
        // If so, reset the values and display them
        M5.Beep.tone(4000, 100);
        buttonA = 0;
        buttonB = 0;
        info();
    // Check if the button A was pressed
    } else if(M5.BtnA.wasPressed()) {
        // If so, increment the value and display it
        M5.Beep.tone(1000, 100);
        buttonA++;
        info();
    } else if(M5.BtnB.wasPressed()) {
        // If so, increment the value and display it
        M5.Beep.tone(2000, 100);
        buttonB++;
        info();
    }

}