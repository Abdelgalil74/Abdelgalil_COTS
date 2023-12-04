/*
 * STEPPER_prog.c
 *
 *  Created on: Dec 1, 2023
 *      Author: bagiz
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "STEPPER_interface.h"
#include "util/delay.h"

ErrorState STEPPER_u8Rotate(Stepper_Config * obj,SteppDirection_t direcion , uint16 angle)
{
	ErrorState Local_u8ErrorState;


	if(NULL==obj)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		uint16 Local_u8Counter;
		uint16 Rotate = (uint16)( ((uint32)angle * 2048UL)/360UL );

		if(direcion==RotateCW )
		{
			for(Local_u8Counter=0;Local_u8Counter<(Rotate/4);Local_u8Counter++)
			{

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_LOW);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

			}
		}
		else if(direcion== RotateCCW)
		{
			for(Local_u8Counter=0 ; Local_u8Counter<(Rotate/4) ; Local_u8Counter++)
			{
				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_HIGH);
				_delay_ms(2);

				DIO_u8SetPinValue(obj->Port,obj->Pin1,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(obj->Port,obj->Pin4,DIO_u8PIN_LOW);
				_delay_ms(2);
			}
		}



	}
	return Local_u8ErrorState;

}
