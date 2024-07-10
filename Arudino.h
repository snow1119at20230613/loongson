#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>             
#include <stdlib.h>           
#include <string.h>             
#include <math.h>                


#define ARDUINO_CORE_VERSION "1.8.13"


#define HIGH 0x1
#define LOW  0x0

#define true 1
#define false 0

#define PI 3.14159265358979323846
#define HALF_PI 1.57079632679489661923
#define TWO_PI 6.28318530717958647692
#define DEG_TO_RAD 0.017453292519943295
#define RAD_TO_DEG 57.295779513082320876

#define SERIAL  0x0
#define DISPLAY 0x1


#define INPUT           0x0
#define OUTPUT          0x1
#define INPUT_PULLUP    0x2
#define INPUT_PULLDOWN  0x3


#define LSBFIRST 0
#define MSBFIRST 1

/
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)   ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define digitalPinToBitMask(P) (1UL << digitalPinToBitNumber(P))
#define digitalPinToTimer(P) (timerForPin(P))


#include "binary.h"          
#include "WCharacter.h"      
#include "WString.h"          
#include "HardwareSerial.h"   
#include "Stream.h"          
#include "Printable.h"      
#include "Wire.h"            
#include "SPI.h"            
#include "EEPROM.h"        
#include "analog.h"        
#include "tone.h"             
#include "millis.h"           
#include "pulse.h"         
#include "WInterrupts.h"    

#if defined(ARDUINO_ARCH_AVR)
  #include "avr/interrupt.h" 
#elif defined(ARDUINO_ARCH_ESP8266)
#elif defined(ARDUINO_ARCH_SAMD)

#endif

#endif
