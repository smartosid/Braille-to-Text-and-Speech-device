#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int buttonPin1 = 22;   // Pin for switch 1
const int buttonPin2 = 23;   // Pin for switch 2
const int buttonPin3 = 24;   // Pin for switch 3
const int buttonPin4 = 25;   // Pin for switch 4
const int buttonPin5 = 26;   // Pin for switch 5
const int buttonPin6 = 27;   // Pin for switch 6
const int enterButtonPin = 42; // Pin for the "Enter" button

Adafruit_SSD1306 display(128, 64, &Wire, -1); // Initialize OLED

bool switch1Pressed = false;
bool switch2Pressed = false;
bool switch3Pressed = false;
bool switch4Pressed = false;
bool switch5Pressed = false;
bool switch6Pressed = false;

void setup() {
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
    pinMode(buttonPin4, INPUT_PULLUP);
    pinMode(buttonPin5, INPUT_PULLUP);
    pinMode(buttonPin6, INPUT_PULLUP);
    pinMode(enterButtonPin, INPUT_PULLUP);

    Serial.begin(9600);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Stop if display initialization fails
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("START");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
}

void loop() {
    // Check each button and print if pressed
    if (digitalRead(buttonPin1) == LOW) {
        if (!switch1Pressed) {
            Serial.println("Button 1 Pressed");
            switch1Pressed = true;
        }
    }
    if (digitalRead(buttonPin2) == LOW) {
        if (!switch2Pressed) {
            Serial.println("Button 2 Pressed");
            switch2Pressed = true;
        }
    }
    if (digitalRead(buttonPin3) == LOW) {
        if (!switch3Pressed) {
            Serial.println("Button 3 Pressed");
            switch3Pressed = true;
        }
    }
    if (digitalRead(buttonPin4) == LOW) {
        if (!switch4Pressed) {
            Serial.println("Button 4 Pressed");
            switch4Pressed = true;
        }
    }
    if (digitalRead(buttonPin5) == LOW) {
        if (!switch5Pressed) {
            Serial.println("Button 5 Pressed");
            switch5Pressed = true;
        }
    }
    if (digitalRead(buttonPin6) == LOW) {
        if (!switch6Pressed) {
            Serial.println("Button 6 Pressed");
            switch6Pressed = true;
        }
    }

    if (digitalRead(enterButtonPin) == LOW) {
        Serial.println("Enter Button Pressed");
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);

        // Display and Serial print based on conditions
        if (switch1Pressed && !switch2Pressed && !switch3Pressed && !switch4Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("A");
            Serial.println("Output: A");
            switch1Pressed = false;
        }
        else if (switch1Pressed && switch2Pressed && !switch3Pressed && !switch4Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("B");
            Serial.println("Output: B");
            switch1Pressed = false;
            switch2Pressed = false;
        }
        else if (switch1Pressed && switch4Pressed && !switch2Pressed && !switch3Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("C");
            Serial.println("Output: C");
            switch1Pressed = false;
            switch4Pressed = false;
        }
        else if (switch1Pressed && switch4Pressed && switch5Pressed && !switch2Pressed && !switch3Pressed && !switch6Pressed) {
            display.println("D");
            Serial.println("Output: D");
            switch1Pressed = false;
            switch4Pressed = false;
            switch5Pressed = false;
        }
        else if (switch1Pressed && !switch4Pressed && !switch3Pressed && switch5Pressed && !switch2Pressed && !switch6Pressed) {
            display.println("E");
            Serial.println("Output: E");
            switch1Pressed = false;
            switch5Pressed = false;
        }
        else if (switch1Pressed && switch2Pressed && switch4Pressed && !switch3Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("F");
            Serial.println("Output: F");
            switch1Pressed = false;
            switch2Pressed = false;
            switch4Pressed = false;
        }
        else if (switch1Pressed && switch2Pressed && switch4Pressed && switch5Pressed && !switch3Pressed && !switch6Pressed) {
            display.println("G");
            Serial.println("Output: G");
            switch1Pressed = false;
            switch2Pressed = false;
            switch4Pressed = false;
            switch5Pressed = false;
        }

         // Display and Serial print based on conditions
        if (switch1Pressed && switch2Pressed && switch5Pressed && !switch3Pressed && !switch4Pressed && !switch6Pressed) {
            display.println("H");
            Serial.println("Output: H");
            switch1Pressed = false;
            switch2Pressed = false;
            switch5Pressed = false;
        }
        else if (switch4Pressed && switch2Pressed && !switch1Pressed && !switch3Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("I");
            Serial.println("Output: I");
            switch4Pressed = false;
            switch2Pressed = false;
        }
        else if (switch2Pressed && switch4Pressed && switch5Pressed && !switch1Pressed && !switch3Pressed && !switch6Pressed) {
            display.println("J");
            Serial.println("Output: J");
            switch2Pressed = false;
            switch4Pressed = false;
            switch5Pressed = false;
        }
        else if (switch1Pressed && switch3Pressed && !switch2Pressed && !switch4Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("K");
            Serial.println("Output: K");
            switch1Pressed = false;
            switch3Pressed = false;
        }
        else if (switch1Pressed && switch2Pressed && switch3Pressed && !switch4Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("L");
            Serial.println("Output: L");
            switch1Pressed = false;
            switch2Pressed = false;
            switch3Pressed = false;
        }
        else if (switch1Pressed && switch4Pressed && switch3Pressed && !switch2Pressed && !switch5Pressed && !switch6Pressed) {
            display.println("M");
            Serial.println("Output: M");
            switch1Pressed = false;
            switch4Pressed = false;
            switch3Pressed = false;
        }
        else if (switch1Pressed && switch4Pressed && switch5Pressed && switch3Pressed && !switch2Pressed && !switch6Pressed) {
            display.println("N");
            Serial.println("Output: N");
            switch1Pressed = false;
            switch4Pressed = false;
            switch5Pressed = false;
            switch3Pressed = false;
        }
        else if (switch1Pressed && switch5Pressed && switch3Pressed && !switch2Pressed && !switch4Pressed && !switch6Pressed) {
            display.println("O");
            Serial.println("Output: O");
            switch1Pressed = false;
            switch5Pressed = false;
            switch3Pressed = false;
        }


        display.display();
        delay(500);
    }
}

  
