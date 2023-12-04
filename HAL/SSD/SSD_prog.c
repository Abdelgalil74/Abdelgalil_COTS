#include "STD_TYPES.h"
#include "bit_math.h"
#include "ErrType.h"
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "SSD_interface.h"





uint8 SSD_Arr[10] = {
		0b00111111,  		 /* 0 */
		0b00000110,   		 /* 1 */
		0b01011011,   		 /* 2 */
		0b01001111,       	 /* 3 */
		0b01100110,   		 /* 4 */
		0b01101101,   		 /* 5 */
		0b01111101,           /* 6 */
		0b00000111,  		 /* 7 */
		0b01111111, 		/* 8 */
		0b01101111   		 /* 9 */
};

/*
ErrorState SSD_u8Init(const ssd_config_t * SSD_obj)
{
	ErrorState Local_u8ErrorState;

	if(NULL == SSD_obj )
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[0],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[1],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[2],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[3],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[4],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[5],DIO_u8PIN_OUTPUT);
			DIO_u8SetPinDirection(SSD_obj->led_port,SSD_obj->led_pins[6],DIO_u8PIN_OUTPUT);


			DIO_u8SetPinDirection(SSD_obj->EnablePort,SSD_obj->EnablePin,DIO_u8PIN_OUTPUT);

	}

	return Local_u8ErrorState;

}
*/

ErrorState SSD_u8DisplayNumber(const ssd_config_t * SSD_obj, uint8 Copy_u8number)
{
	ErrorState Local_u8ErrorState;

	if(NULL == SSD_obj )
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		if( (SSD_obj->common==COMMON_CATHODE) || (SSD_obj->common==ETA_KIT) )
		{

			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[0],GET_BIT(SSD_Arr[Copy_u8number],0));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[1],GET_BIT(SSD_Arr[Copy_u8number],1));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[2],GET_BIT(SSD_Arr[Copy_u8number],2));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[3],GET_BIT(SSD_Arr[Copy_u8number],3));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[4],GET_BIT(SSD_Arr[Copy_u8number],4));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[5],GET_BIT(SSD_Arr[Copy_u8number],5));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[6],GET_BIT(SSD_Arr[Copy_u8number],6));
		}
		else if(SSD_obj->common==COMMON_ANODE)
		{
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[0],~GET_BIT(SSD_Arr[Copy_u8number],0));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[1],~GET_BIT(SSD_Arr[Copy_u8number],1));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[2],~GET_BIT(SSD_Arr[Copy_u8number],2));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[3],~GET_BIT(SSD_Arr[Copy_u8number],3));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[4],~GET_BIT(SSD_Arr[Copy_u8number],4));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[5],~GET_BIT(SSD_Arr[Copy_u8number],5));
			DIO_u8SetPinValue(SSD_obj->led_port,SSD_obj->led_pins[6],~GET_BIT(SSD_Arr[Copy_u8number],6));
		}
	}

	return Local_u8ErrorState;

}

ErrorState SSD_u8ON(const ssd_config_t * SSD_obj)
{
	ErrorState Local_u8ErrorState;

	if(NULL == SSD_obj )
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		if(SSD_obj->common==COMMON_ANODE || SSD_obj->common==ETA_KIT)
		DIO_u8SetPinValue(SSD_obj->EnablePort,SSD_obj->EnablePin,DIO_u8PIN_HIGH);

		else if(SSD_obj->common==COMMON_CATHODE)
		DIO_u8SetPinValue(SSD_obj->EnablePort,SSD_obj->EnablePin,DIO_u8PIN_LOW);

		else
			Local_u8ErrorState=NOT_OK;
	}

	return Local_u8ErrorState;

}


ErrorState SSD_u8OFF(const ssd_config_t * SSD_obj)
{
	ErrorState Local_u8ErrorState;

	if(NULL == SSD_obj )
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		if(SSD_obj->common==COMMON_ANODE || SSD_obj->common==ETA_KIT)
		DIO_u8SetPinValue(SSD_obj->EnablePort,SSD_obj->EnablePin,DIO_u8PIN_LOW);

		else if(SSD_obj->common==COMMON_CATHODE)
		DIO_u8SetPinValue(SSD_obj->EnablePort,SSD_obj->EnablePin,DIO_u8PIN_HIGH);

		else
			Local_u8ErrorState=NOT_OK;
	}

	return Local_u8ErrorState;

}
