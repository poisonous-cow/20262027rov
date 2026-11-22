#include <iostream>
#include "ArduinoJson.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.read();

    JsonObject& inputs = jsonBuffer.parseObject(data);
    if (!inputs.success()) {
      Serial.println("parseObject() failed");
    }

    Serial.println("JSON print: ");
    float left_x = inputs["left_x"];
    Serial.println(left_x);
  }
}


