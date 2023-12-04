/*
 * SSD.h
 *
 *  Created on: Oct 28, 2023
 *      Author: bagiz
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef enum
{
	COMMON_CATHODE,
	COMMON_ANODE,
	ETA_KIT
}common_t;


typedef struct{

	common_t common;
	port_index led_port;
	pin_index led_pins[7];
	port_index EnablePort;
	pin_index  EnablePin;

}ssd_config_t;



//ErrorState SSD_u8Init(const ssd_config_t * SSD_obj);

ErrorState SSD_u8ON(const ssd_config_t * SSD_obj);
ErrorState SSD_u8OFF(const ssd_config_t * SSD_obj);

ErrorState SSD_u8DisplayNumber(const ssd_config_t * SSD_obj, uint8 Copy_u8number);



#endif /* SSD_INTERFACE_H_ */
