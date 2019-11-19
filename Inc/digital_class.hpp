/*
 * digital_class.hpp
 *
 *  Created on: 2019/11/13
 *      Author: kazu
 */

#ifndef DIGITAL_CLASS_HPP_
#define DIGITAL_CLASS_HPP_

#include "gpio.h"

class Digital {
 public:
  Digital(GPIO_TypeDef* gpio_x, uint16_t gpio_pin);
  virtual ~Digital();

  void On(){ HAL_GPIO_WritePin(gpio_x_, gpio_pin_, GPIO_PIN_SET); }
  void Off(){ HAL_GPIO_WritePin(gpio_x_, gpio_pin_, GPIO_PIN_RESET); }
  void Toggle(){ HAL_GPIO_TogglePin(gpio_x_, gpio_pin_); }

  int Read(){ return HAL_GPIO_ReadPin(gpio_x_, gpio_pin_); }

 private:
  GPIO_TypeDef* gpio_x_;
  uint16_t gpio_pin_;
};

#endif /* DIGITAL_CLASS_HPP_ */
