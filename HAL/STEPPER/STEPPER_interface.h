/*
 * STEPPER_interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: bagiz
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef struct
{
	port_index Port;
	pin_index  Pin1;
	pin_index  Pin2;
	pin_index  Pin3;
	pin_index  Pin4;
}Stepper_Config;

typedef enum
{
	RotateCW,
	RotateCCW
}SteppDirection_t;


ErrorState STEPPER_u8Rotate(Stepper_Config * obj , SteppDirection_t direcion , uint16 angle);


#endif /* STEPPER_INTERFACE_H_ */
