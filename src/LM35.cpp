/*
 * MIT License
 *
 * Copyright (c) 2018 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \brief Analog LM35 temperature sensor library for Arduino
 * \details Source: https://github.com/Erriez/ErriezLM35
 * \file LM35.cpp
 */

#include "LM35.h"

/*!
 * \brief LM35 constructor.
 * \details
 *      The constructor changes the ADC to 1.1V internal ADC reference voltage
 *      for higher accuracy. This affects all ANALOG pins.
 * \param pin LM35 analog pin.
 */
LM35::LM35(uint8_t pin) : _pin(pin)
{
  // Configures internal ADC reference voltage to 1.1V of the ANALOG pins
  analogReference(INTERNAL);

  // Dummy read to clear previous ADC conversion
  (void)analogRead(_pin);
}

/*!
 * \brief Read analog temperature in range between 0.0 .. 110 degree Celsius.
 * \details
 *      Sample LM35 analog pin multiple times to find two identical samples to
 *      reduce noise. A maximum number of samples can be configured with macro
 *      LM35_MAX_SAMPLES. The last sampled temperature will be returned when
 *      no identical temperatures found.
 *
 *      A negative temperature cannot be measured, because the ADC pin can only
 *      sample between positive 0.0 and 1.1 Volt.
 * \return
 *      Divide temperature by 10 to get the temperature integer, temperature
 *      modulo 10 results in the fraction, for example:
 *         int16_t temperature = 182 means 18.2 degree Celsius.
 */
int16_t LM35::readTemperature()
{
  int16_t temperatureLast = 0;
  int16_t temperature = 0;

  // Take multiple temperature samples with a maximum of LM35_MAX_SAMPLES
  for (uint8_t i = 0; i < LM35_MAX_SAMPLES; i++) {
    // Analog range: 0 .. 1.1V = 0 .. 1023 ADC value
    // For example, LM35 analog signal of 0.182 V equals to 18.2 degree celsius
    // 1024 / 1.1V = 931 ratio between analog sample and output temperature
    // This calculation is multiplied by 1000 first to avoid expensive floating
    // point instructions.
    temperature = ((uint32_t)analogRead(_pin) * 1000) / 931;

    if (temperatureLast == temperature) {
      // Two identical temperatures read, return
      return temperature;
    }

    // Different temperatures, take another sample
    temperatureLast = temperature;
  }

  // Return the last measured temperature
  return temperatureLast;
}
