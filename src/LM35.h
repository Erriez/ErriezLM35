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
 * \file LM35.h
 */

#ifndef LM35_H__
#define LM35_H__

#include <Arduino.h>

//! Check tested platform.
#if !defined(AVR)
#warning "Untested platform. Check analogReference() support."
#endif

//! Maximum number of LM35 ADC samples
#ifndef LM35_MAX_SAMPLES
#define LM35_MAX_SAMPLES   10
#endif

//! LM35 sensor class
class LM35
{
public:
    explicit LM35(uint8_t pin);
    uint16_t readTemperature();

private:
    uint8_t _pin;
};

#endif // LM35_H__
