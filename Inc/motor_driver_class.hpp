/*
 * motor_driver_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef MOTOR_DRIVER_CLASS_HPP_
#define MOTOR_DRIVER_CLASS_HPP_

class MotorDriver {
 public:
  MotorDriver();
  virtual ~MotorDriver();

  virtual int Setup(){ return 0; }
  virtual void Duty(float value){};
  virtual void Stop(){};
};

#endif /* MOTOR_DRIVER_CLASS_HPP_ */
