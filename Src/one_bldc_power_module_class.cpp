/*
 * one_bldc_power_module_class.cpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#include "one_bldc_power_module_class.hpp"

OneBLDCPowerModule::OneBLDCPowerModule(PWM &pwm_object, Digital &dir_object, Digital &coast_object):pwm_(pwm_object),dir_(dir_object),coast_(coast_object) {
	// TODO Auto-generated constructor stub

}

OneBLDCPowerModule::~OneBLDCPowerModule() {
	// TODO Auto-generated destructor stub
}

int OneBLDCPowerModule::Setup() {
	pwm_.Setup();

	return 0;
}

void OneBLDCPowerModule::Duty(float duty) {
	if (duty > 0.0f) {
		dir_.Off();
		pwm_.Duty(duty);
	} else if (duty < 0.0f) {
		dir_.On();
		pwm_.Duty(duty);
	} else {
		pwm_.Duty(duty);
	}
}

void OneBLDCPowerModule::Stop() {
	coast_.On();

	pwm_.Duty(0.0f);
}

