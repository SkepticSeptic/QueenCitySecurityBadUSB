#include <Arduino.h>
#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT, KEY_SPACE);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("tree");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(7000);

}

void loop() {
  // put your main code here, to run repeatedly:
    DigiKeyboard.print("echo MaiNfRaMe hAcKeD!");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

// put function definitions here:
