/*
 * led_class.hpp
 *
 *  Created on: 2019/11/14
 *      Author: kazu
 */

#ifndef LED_CLASS_HPP_
#define LED_CLASS_HPP_

#include "digital_class.hpp"

class Led {
 public:
  Led(Digital &digital_object);
  virtual ~Led();

  void On(){ digital_.On(); }
  void Off(){ digital_.Off(); }
  void Toggle(){ digital_.Toggle(); }

 private:
  Digital &digital_;
};

#endif /* LED_CLASS_HPP_ */
