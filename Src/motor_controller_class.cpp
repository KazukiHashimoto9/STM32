/*
 * motor_controller_class.cpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#include "motor_controller_class.hpp"

MotorController::MotorController(MotorDriver &motor_driver_object, Encoder &encoder_object):motor_driver_(motor_driver_object),encoder_(encoder_object) {
	// TODO Auto-generated constructor stub
	target_vel_ = 0.0f;
	current_vel_ = 0.0f;
	target_pos_ = 0.0f;
	current_pos_ = 0.0f;
	p_gain_ = 0.0f;
	i_gain_ = 0.0f;
	d_gain_ = 0.0f;
	vel_deviation_ = 0.0f;
	vel_deviation_sum_ = 0.0f;
	pos_deviation_ = 0.0f;
	pos_deviation_old_ = 0.0f;
	output_ = 0.0f;
	mode_ = STOP_MODE;
}

MotorController::~MotorController() {
	// TODO Auto-generated destructor stub
}

int MotorController::Setup() {
	motor_driver_.Setup();
	encoder_.Setup();

	return 0;
}

void MotorController::Cycle() {
	encoder_.Cycle();

	if (mode_ == STOP_MODE) motor_driver_.Stop();
	else if (mode_ == DUTY_MODE) motor_driver_.Duty(output_);
	else if (mode_ == VEL_MODE) {
		current_vel_ = encoder_.Rads();

		vel_deviation_ = target_vel_ - current_vel_;

		if (fabsf(output_) <= 1.0f) {
			vel_deviation_sum_ += vel_deviation_;
		}

		output_ = vel_deviation_ * p_gain_ + vel_deviation_sum_ * i_gain_;

		motor_driver_.Duty(output_);
	} else if (mode_ == POS_MODE) {
		current_pos_ = encoder_.Radian();

		pos_deviation_ = target_pos_ - current_pos_;

		output_ = pos_deviation_ * p_gain_ + (pos_deviation_ - pos_deviation_old_) * d_gain_;

		pos_deviation_old_ = pos_deviation_;

		if (fabsf(pos_deviation_) <= 0.01f) output_ = 0.0f;

		motor_driver_.Duty(output_);
	}
}


