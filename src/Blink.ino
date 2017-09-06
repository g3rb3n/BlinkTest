
#ifdef ARDUINO_AVR_UNO
  #define LEDA {13}
  #define LEDS 1
  #define BAUD 9600
#endif
#ifdef ARDUINO_AVR_MICRO
  #define LEDA {17, 30}
  #define LEDS 2
  #define LEDI
  #define BAUD 230400
#endif
#ifdef ARDUINO_AVR_NANO
  #define LEDA {13}
  #define LEDS 1
  #define BAUD 230400
#endif
#ifdef ESP8266_WEMOS_D1MINI
  #define LEDA {BUILTIN_LED}
  #define LEDS 1
  #define LEDI
  #define BAUD 230400
#endif
#ifdef ARDUINO_LOLIN32//ARDUINO_ARCH_ESP32 //ESP32_WEMOS_LOLIN32
  #define LEDA {2}
  #define LEDS 1
  #define BAUD 230400
#endif
#ifdef ARDUINO_ESP32_DEV
  #define LEDA {2}
  #define LEDS 1
  #define BAUD 9600
#endif
#ifdef ARDUINO_GENERIC_STM32F103C
  #define LEDA {PC13}
  #define LEDS 1
  #define LEDI
  #define BAUD 9600
#endif

#ifndef LEDA
  #warning "No builtin leds defined"
#endif
#ifdef LEDI
  #define ON LOW
  #define OFF HIGH
#else
  #define ON HIGH
  #define OFF LOW
#endif

int leds[] = LEDA;

void setup()
{
  Serial.begin(BAUD);
  Serial.println();

  for (unsigned int i = 0 ; i < LEDS ; ++i)
    pinMode(leds[i], OUTPUT);  
}

void loop()
{
  for (unsigned int i = 0 ; i < LEDS ; ++i)
  {
    int state = (millis() + i * 1000 / LEDS) % 1000 < 100;
    digitalWrite(leds[i], state ? ON : OFF);
    Serial.print(state);
  }
  Serial.println();
}
