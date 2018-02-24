# LM35 temperature sensor library for Arduino

This is an accurate LM35 analog temperature sensor library for Arduino with noise cancellation.

## Library features

- Synchronous 16-bit temperature read
- Temperature range: 0.0 .. 110.0 degree Celsius
- Accuracy: 0.1 degree Celsius
- Noise cancellation
- Small footprint


## Hardware

![Schematic LM35 and Arduino UNO](https://raw.githubusercontent.com/Erriez/ErriezLM35/master/extras/LM35_Arduino_UNO.png)

**Connection LM35 - Arduino UNO**

| LM35 |   Arduino UNO   |
| :--: | :-------------: |
| GND  |       GND       |
|  Vs  |  5V (or 3.3V)   |
| Vout | A0 (ANALOG pin) |

**Notes:** 

* Keep wires short to prevent noise.
* This library has been tested on the Arduino UNO only which supports internal 1.1V ADC reference voltage. This may not be available with other MCU's.

### LM35 pins

![LM35 pins](https://raw.githubusercontent.com/Erriez/ErriezLM35/master/extras/LM35_pins.png)

## Documentation

[DHT35 datasheet](https://www.google.com/search?q=LM35+datasheet)



## LM35 specifications

- Supply voltage: 3.3V .. 30V
- Low power: Around 65uA 
- Analog voltage interface



## Examples

Examples | ErriezLM35:

* [Example](https://github.com/Erriez/ErriezLM35/blob/master/examples/Example/Example.ino)



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
  // Read temperature from sensor
  int16_t lm35_temp = lm35.readTemperature();
  
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

