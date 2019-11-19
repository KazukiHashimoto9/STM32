/*
 * one_bldc_power_module_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef ONE_BLDC_POWER_MODULE_CLASS_HPP_
#define ONE_BLDC_POWER_MODULE_CLASS_HPP_

#include "motor_driver_class.hpp"
#include "pwm_class.hpp"
#include "digital_class.hpp"

class OneBLDCPowerModule : public MotorDriver {
 public:
  OneBLDCPowerModule(PWM &pwm_object, Digital &dir_object, Digital &coast_object);
  virtual ~OneBLDCPowerModule();

  int Setup();
  void Duty(float duty);
  void Stop();

 private:
  PWM &pwm_;
  Digital &dir_;
  Digital &coast_;
};

#endif /* ONE_BLDC_POWER_MODULE_CLASS_HPP_ */
