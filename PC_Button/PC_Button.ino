// Include the M5StickCPlus library
#include <M5StickCPlus.h>

// Create a global variable to hold the button state
boolean toggle = true;

// Create a function to display the screen
void screen() {
    M5.Lcd.setTextSize(3);
    M5.Lcd.setCursor(50, 30);
    M5.Lcd.println("Btn test");
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(40, 60);
    M5.Lcd.println("Preston Chapman");
}
void setup()
{
	M5.begin();
    M5.Lcd.setRotation(3);
    screen();
}

void loop()
{
    // Update the button state
	M5.update();
    // Check if the button A was pressed
    if (M5.BtnA.wasPressed()) {
        // if toggle is true, set the screen to red, else set to black
        if(toggle){
            M5.Lcd.fillScreen(RED);
        } else {
            M5.Lcd.fillScreen(BLACK);
        }
        // Update the screen
        screen();
        // Inverse the toggle variable
        toggle = !toggle;
    }
}
