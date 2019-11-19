/*
 * pwm_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef PWM_CLASS_HPP_
#define PWM_CLASS_HPP_

#include <cmath>

#include "tim.h"

class PWM {
 public:
  PWM(TIM_HandleTypeDef *htim, uint32_t channel);
  virtual ~PWM();

  int Setup();
  void Duty(float value);
  void DutyLimit(float lower_value,float upper_value);

 private:
  TIM_HandleTypeDef *htim_;
  uint32_t channel_;

  float duty_;
  float lower_limit_value_;
  float upper_limit_value_;
};

#endif /* PWM_CLASS_HPP_ */
