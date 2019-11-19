/*
 * wrapper.cpp
 *
 *  Created on: 2019/09/19
 *      Author: kazu
 */

#include "wrapper.hpp"
#include "control.hpp"

Control control;

void MainLoop(void){
	control.Cycle();
}
