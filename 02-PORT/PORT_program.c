#include "STD_TYPES.h"
#include "BIT_MATHS.h"


#include "port_interface.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "port_private.h"




void PortInit (void)
{
  
  DDRA=PORTA_DIR;

  DDRB=PORTB_DIR;

  DDRC=PORTC_DIR;

  DDRD=PORTD_DIR;
  
  PORTA=PORTA_INITIALVALUE;
  PORTB=PORTB_INITIALVALUE;
  PORTC=PORTC_INITIALVALUE;
  PORTD=PORTD_INITIALVALUE;

  
  
  
}
