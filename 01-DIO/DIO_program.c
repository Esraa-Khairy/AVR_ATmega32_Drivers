#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_private.h"
#include "PORT_register.h"
#include "DIO_conifig.h"
#include "DIO_interface.h"




void SetpinValue (u8 port , u8 pin , u8 val)
{
   switch(port)
  {
    case 'A':
    
      if(val==0)
      {
        //PORTA = PORTA & ~(1<< pin);
         CLR_BIT(PORTA,pin);
      }
      else
      {
        //PORTA=PORTA| (1<< pin);
        SET_BIT(PORTA,pin);
        
      }break;
     
    case 'B':
     if(val==0)
      {
        //PORTB = PORTB& ~(1<< pin);
         CLR_BIT(PORTB,pin);
      }
      else
      {
        //PORTB=PORTB | (1<< pin);
         SET_BIT(PORTB,pin);
      }break;
    case 'C':
     if(val==0)
      {
         //PORTC= PORTC & ~(1<< pin);
          CLR_BIT(PORTC,pin);
      }
      else
      {
        //PORTC=PORTC | (1<< pin);
        SET_BIT(PORTC,pin);
        
      }break;
    case 'D':
     if(val==0)
      {
        //PORTD = PORTD & ~(1<< pin);
         CLR_BIT(PORTD,pin);
      }
      else
      {
        //PORTD=PORTD | (1<< pin);
        SET_BIT(PORTD,pin);
        
      }break;
    
  }
  
  
}
u8 GetPinValue (u8 port , u8 pin)
{
	u8 result;
	 switch(port)
	  {
	 	case 'A':result=  GET_BIT(PINA,pin);break;
	    case 'B':result=  GET_BIT(PINB,pin);break;
	    case 'C':result=  GET_BIT(PINC,pin);break;
	    case 'D':result=  GET_BIT(PIND,pin);break;

	  }
	 return result;
}
