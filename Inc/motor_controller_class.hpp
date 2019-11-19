/*
 * motor_controller_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef MOTOR_CONTROLLER_CLASS_HPP_
#define MOTOR_CONTROLLER_CLASS_HPP_

#include "motor_driver_class.hpp"
#include "encoder_class.hpp"

class MotorController {
 public:
  MotorController(MotorDriver &motor_driver_object, Encoder &encoder_object);
  virtual ~MotorController();

  int Setup();

  void Duty(float duty){ mode_ = DUTY_MODE; output_ = duty; }
  void Stop(){ motor_driver_.Stop(); }

  float Vel(float target_vel){ mode_ = VEL_MODE; target_vel_ = target_vel; return target_vel_; }
  float Pos(float target_pos){ mode_ = POS_MODE; target_pos_ = target_pos; return target_pos_; }

  float SetPGain(float p_gain){ p_gain_ = p_gain; return p_gain_; }
  float SetIGain(float i_gain){ i_gain_ = i_gain; return i_gain_; }
  float SetDGain(float d_gain){ d_gain_ = d_gain; return d_gain_; }

  float Revolution(){ return encoder_.Revolution(); }
  float Radian(){ return encoder_.Radian(); }
  float Rads(){ return encoder_.Rads(); }

  void Cycle();

 private:
  MotorDriver &motor_driver_;
  Encoder &encoder_;

  float target_vel_;
  float current_vel_;
  float target_pos_;
  float current_pos_;
  float p_gain_;
  float i_gain_;
  float d_gain_;
  float vel_deviation_;
  float vel_deviation_sum_;
  float pos_deviation_;
  float pos_deviation_old_;
  float output_;
  int mode_;
  enum{
    STOP_MODE=0,
	DUTY_MODE=1,
	VEL_MODE=2,
	POS_MODE=3,
  };
};

#endif /* MOTOR_CONTROLLER_CLASS_HPP_ */
