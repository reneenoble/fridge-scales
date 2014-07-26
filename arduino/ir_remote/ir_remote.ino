/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define POWER_BUT            0xFFA25D
#define MODE_BUT             0xFF629D
#define MUTE_BUT             0xFFE21D
#define PLAY_BUT             0xFF22DD
#define REWIND_BUT           0xFF02FD
#define FFWD_BUT             0xFFC23D
#define EQ_BUT               0xFFE01F
#define MINUS_BUT            0xFFA857
#define PLUS_BUT             0xFF906F
#define SHUFFLE_BUT          0xFF9867
#define USD_BUT              0xFFB04F
#define ZERO_BUT             0xFF6897
#define ONE_BUT              0xFF30CF
#define TWO_BUT              0xFF18E7
#define THREE_BUT            0xFF7A85
#define FOUR_BUT             0xFF10EF
#define FIVE_BUT             0xFF38C7
#define SIX_BUT              0xFF5AA5
#define SEVEN_BUT            0xFF42BD
#define EIGHT_BUT            0xFF4AB5
#define NINE_BUT             0xFF52AD

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
    switch(results.value) {
      case POWER_BUT:
        Serial.println("Power");
        break;
      case MODE_BUT:
        Serial.println("Mode");
        break;
      case MUTE_BUT:
        Serial.println("Mute");
        break;
      case PLAY_BUT:
        Serial.println("Play");
        break;
      case REWIND_BUT:
        Serial.println("Rewind");
        break;
      case FFWD_BUT:
        Serial.println("Fastforward");
        break;
      case EQ_BUT:
        Serial.println("EQ");
        break;
      case MINUS_BUT:
        Serial.println("Minus");
        break;
      case PLUS_BUT:
        Serial.println("Plus");
        break;
      case SHUFFLE_BUT:
        Serial.println("Shuffle");
        break;
      case USD_BUT:
        Serial.println("USD");
        break;
      case ZERO_BUT:
        Serial.println("0");
        break;
      case ONE_BUT:
        Serial.println("1");
        break;
      case TWO_BUT:
        Serial.println("2");
        break;
      case THREE_BUT:
        Serial.println("3");
        break;
      case FOUR_BUT:
        Serial.println("4");
        break;
      case FIVE_BUT:
        Serial.println("5");
        break;
      case SIX_BUT:
        Serial.println("6");
        break;
      case SEVEN_BUT:
        Serial.println("7");
        break;
      case EIGHT_BUT:
        Serial.println("8");
        break;
      case NINE_BUT:
        Serial.println("9");
        break;
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
