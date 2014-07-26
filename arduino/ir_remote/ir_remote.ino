/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define POWER_BUT            0xFFA25D

int RECV_PIN = 11;
int led = 8;
int on_off = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    // log message
    if(results == POWER_BUT) {
      Serial.println("Power!");
    }
    
    // toggle LED
    if (results.value) {
      on_off = !on_off;
      if(on_off == 1) {
        digitalWrite(led, HIGH);
      } else {
        digitalWrite(led, LOW);
      }
    }
    
    irrecv.resume(); // Receive the next value
  }
}
