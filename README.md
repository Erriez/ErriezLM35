# LM35 temperature sensor library for Arduino
[![Build Status](https://travis-ci.org/Erriez/ErriezLM35.svg?branch=master)](https://travis-ci.org/Erriez/ErriezLM35)

This is an accurate LM35 analog temperature sensor library for Arduino with noise cancellation.

## Library features

- Synchronous 10-bit unsigned temperature read
- Temperature range: 0.0 .. 110.0 degree Celsius
- Accuracy: 0.1 degree Celsius
- Noise cancellation
- Small footprint


## Hardware

### Supported hardware

* All ATmega328P MCU (Arduino UNO, Micro, Nano, etc)
* All ATmega32U4 MCU (Arduino Leonardo, Pro Micro, etc)
* Arduino ATmega2560

**Notes:** 

* This library changes analog pins to ADC 1.1V internal reference voltage which affects all analog pins.
* The function ```analogReference()``` may not be supported with other non-AVR MCU's.

### Arduino UNO - LM35 example

![Schematic LM35 and Arduino UNO](https://raw.githubusercontent.com/Erriez/ErriezLM35/master/extras/LM35_Arduino_UNO.png)

| LM35 |   Arduino UNO   |
| :--: | :-------------: |
| GND  |       GND       |
|  Vs  |  5V (or 3.3V)   |
| Vout | A0 (ANALOG pin) |

**Notes:** 

* Keep wires short to prevent noise.

### LM35 pins

![LM35 pins](https://raw.githubusercontent.com/Erriez/ErriezLM35/master/extras/LM35_pins.png)


## LM35 specifications

- Supply voltage: 3.3V .. 30V
- Low power: Around 65uA 
- Analog voltage interface


## Examples

Arduino IDE | Examples | Erriez LM35 analog temperature:

* [Example](https://github.com/Erriez/ErriezLM35/blob/master/examples/LM35/LM35.ino)


## Documentation

* [Doxygen online HTML](https://erriez.github.io/ErriezLM35)
* [Doxygen PDF](https://github.com/Erriez/ErriezLM35/raw/gh-pages/latex/ErriezLM35.pdf)
* [LM35 datasheet](https://www.google.com/search?q=LM35+datasheet)


## Usage

**Initialization**

```c++
#include <LM35.h>
  
// Connect LM35 data pin to Arduino DIGITAL pin
#define LM35_PIN   A0
  
LM35 lm35 = LM35(LM35_PIN);
```


**Read temperature and humidity**

```c++
void loop()
{
  // Read unsigned temperature from sensor
  uint16_t lm35_temp = lm35.readTemperature();
  
  // Print temperature
  Serial.print(F("LM35: "));
  Serial.print(lm35_temp / 10);
  Serial.print(F("."));
  Serial.print(lm35_temp % 10);
  Serial.println(F(" *C"));
  
  // Wait some time
  delay(2000);
}
```


**Serial output**

```
Analog LM35 temperature sensor example
  
LM35: 18.1 *C
LM35: 18.2 *C
LM35: 18.2 *C
  
...
```


## Library dependencies

* None


## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.


## Other Arduino Libraries and Sketches from Erriez

* [Erriez Libraries and Sketches](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches)
