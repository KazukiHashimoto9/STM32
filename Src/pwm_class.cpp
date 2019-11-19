/*
 * pwm_class.cpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#include "pwm_class.hpp"

PWM::PWM(TIM_HandleTypeDef *htim, uint32_t channel):htim_(htim),channel_(channel) {
	// TODO Auto-generated constructor stub
	duty_ = 0.0f;
	lower_limit_value_ = -1.0f;
	upper_limit_value_ = 1.0f;
}

PWM::~PWM() {
	// TODO Auto-generated destructor stub
}

int PWM::Setup() {
	HAL_TIM_PWM_Start(htim_, channel_);
}

void PWM::Duty(float value) {
	if (value >= upper_limit_value_) value = upper_limit_value_;
	else if (value <= lower_limit_value_) value = lower_limit_value_;

	duty_ = fabsf(value) * (htim_->Init.Period + 1);

	__HAL_TIM_SetCompare(htim_, channel_, (int)duty_);
}

void PWM::DutyLimit(float lower_value,float upper_value) {
	lower_limit_value_ = lower_value;
	upper_limit_value_ = upper_value;
}
