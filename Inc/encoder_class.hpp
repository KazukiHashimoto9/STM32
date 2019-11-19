/*
 * encoder_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef ENCODER_CLASS_HPP_
#define ENCODER_CLASS_HPP_

#include "tim.h"

#include <iostream>
#include <cmath>

class Encoder {
 public:
  Encoder(TIM_HandleTypeDef *htim, uint32_t channel, TIM_TypeDef *tim);
  virtual ~Encoder();

  int Setup();

  void Reverse(){ reverse_flag_ = true; }
  void SetGearRatio(float gear_ratio){ gear_ratio_ = gear_ratio; }
  void SetResolution(int resolution){ resolution_ = (float)resolution * 4.0f; }

  int Count(){ return count_; }
  float Revolution(){ return revolution_; }
  float Radian(){ return revolution_ * 2.0f * M_PI; }
  float Rads(){ return angular_velocity_; }

  void Cycle();

 private:
  TIM_HandleTypeDef *htim_;
  uint32_t channel_;
  TIM_TypeDef *tim_;

  int cnt_;
  int cnt_diff_;
  int cnt_old_;
  int count_;
  float revolution_;
  float revolution_old_;
  float angular_velocity_;
  int time_old_;
  float dt_;
  float gear_ratio_;
  float resolution_;
  bool reverse_flag_;
};

#endif /* ENCODER_CLASS_HPP_ */
