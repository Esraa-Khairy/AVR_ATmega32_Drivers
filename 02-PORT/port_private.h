#define conc(b7,b6,b5,b4,b3,b2,b1,b0) conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0


#define PORTA_DIR conc(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR conc(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR conc(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR conc(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_INITIALVALUE conc(PORTA_PIN7_INITIALVALUE,PORTA_PIN6_INITIALVALUE,PORTA_PIN5_INITIALVALUE,PORTA_PIN4_INITIALVALUE,PORTA_PIN3_INITIALVALUE,PORTA_PIN2_INITIALVALUE,PORTA_PIN1_INITIALVALUE,PORTA_PIN0_INITIALVALUE)
#define PORTB_INITIALVALUE conc(PORTB_PIN7_INITIALVALUE,PORTB_PIN6_INITIALVALUE,PORTB_PIN5_INITIALVALUE,PORTB_PIN4_INITIALVALUE,PORTB_PIN3_INITIALVALUE,PORTB_PIN2_INITIALVALUE,PORTB_PIN1_INITIALVALUE,PORTB_PIN0_INITIALVALUE)
#define PORTC_INITIALVALUE conc(PORTC_PIN7_INITIALVALUE,PORTC_PIN6_INITIALVALUE,PORTC_PIN5_INITIALVALUE,PORTC_PIN4_INITIALVALUE,PORTC_PIN3_INITIALVALUE,PORTC_PIN2_INITIALVALUE,PORTC_PIN1_INITIALVALUE,PORTC_PIN0_INITIALVALUE)
#define PORTD_INITIALVALUE conc(PORTD_PIN7_INITIALVALUE,PORTD_PIN6_INITIALVALUE,PORTD_PIN5_INITIALVALUE,PORTD_PIN4_INITIALVALUE,PORTD_PIN3_INITIALVALUE,PORTD_PIN2_INITIALVALUE,PORTD_PIN1_INITIALVALUE,PORTD_PIN0_INITIALVALUE)


