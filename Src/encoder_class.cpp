/*
 * encoder_class.cpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#include "encoder_class.hpp"

Encoder::Encoder(TIM_HandleTypeDef *htim, uint32_t channel, TIM_TypeDef *tim):htim_(htim),channel_(channel),tim_(tim) {
	// TODO Auto-generated constructor stub
	cnt_ = 0;
	cnt_diff_ = 0;
	cnt_old_ = 0;
	count_ = 0;
	revolution_ = 0.0f;
	revolution_old_ = 0.0f;
	angular_velocity_ = 0.0f;
	time_old_ = 0;
	dt_ = 0.0f;
	gear_ratio_ = 1.0f;
	resolution_ = 1.0f;
	reverse_flag_ = false;
}

Encoder::~Encoder() {
	// TODO Auto-generated destructor stub
}

int Encoder::Setup() {
	HAL_TIM_Encoder_Start(htim_, channel_);

	return 0;
}

void Encoder::Cycle() {
	if (reverse_flag_) cnt_ = (tim_->CNT) * -1;
	else cnt_ = tim_->CNT;

	cnt_diff_ = cnt_ - cnt_old_;
	if (std::abs(cnt_diff_) <= 60000) {
		count_ += cnt_diff_;
	}

	revolution_ = (float)count_ / resolution_ / gear_ratio_;

	dt_ = ((float)millis() - (float)time_old_) / 1000.0f;

	angular_velocity_ = 2.0f * M_PI * (revolution_ - revolution_old_) / dt_;

	cnt_old_ = cnt_;

	revolution_old_ = revolution_;

	time_old_ = millis();
}
