/*
 * File: HardwarePWM.h
 * Original Author: https://github.com/hrsavla
 *
 * This HW_PWM library enables Sming framework user to use ESP SDK PWM API
 * Period of PWM is fixed to 1000ms / Frequency = 1khz
 * Duty at 100% = 22222. Duty at 0% = 0
 * You can use function setPeriod() to change frequency/period.
 * Calculate the Duty as per the formulae give in ESP8266 SDK
 * Duty = (Period *1000)/45
 *
 * PWM can be generated on upto 8 pins (ie All pins except pin 16)
 * Created on August 17, 2015, 2:27 PM
 */

#ifndef HARDWAREPWM_H
#define	HARDWAREPWM_H

#include "ESP8266EX.h"
#include "../wiring/WiringFrameworkDependencies.h"

#define PWM_CHANNEL_NUM_MAX 8
#define PWM_BAD_CHANNEL 0xff
#define PWM_MAXDUTY 1023

#ifdef __cplusplus
extern "C" {
#endif
#include "pwm.h"
#ifdef __cplusplus
}
#endif

class HardwarePWM {
public:
	HardwarePWM(uint8 *pins, uint8 no_of_pins, uint32 reqPeriod = 1000);
	virtual ~HardwarePWM();
	bool analogWrite(uint8 pin, uint32 duty, bool start = true);
	bool setDuty(uint8 pin, uint32 duty, bool start = true);
	uint32 getDuty(uint8 pin);
	void setPeriod(uint32 period);
	uint32 getPeriod(void);
	uint8 getChannel(uint8 pin);
	void restart();
protected:

private:
	uint8 channel_count;
	uint8 channels[PWM_CHANNEL_NUM_MAX];
};

#endif	/* HARDWAREPWM_H */
