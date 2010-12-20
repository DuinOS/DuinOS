/* cserial.cpp */
// these two c functions are required so that
// stdout can be initialized for the stdio library
// This binds the printf function to the hardware serial port

#include “cserial.h”
#include “wiring_private.h”

static int serial_write(char c, FILE *f) {

/* Wait for transmit buffer to be empty */
while ((UCSR0A & _BV(UDRE0)) == 0)
;

/* Put byte into transmit buffer */
UDR0 = c;

return 0;
}

static FILE sio_stdout = {0} ;                           /* added to support the DH mod eliminating stdio malloc requirements */

void serial_stdout_init (long speed) {
/* Set baud rate */
uint16_t factor = (F_CPU / 16 + speed / 2) / speed – 1;
UBRR0H = factor >> 8;
UBRR0L = factor;

/* Set format (8N1) */
UCSR0C = 3 << UCSZ00;

/* Enable transmitter */

UCSR0B = _BV(TXEN0);

/* Set up stdout to write to the serial port */
/* stdout = fdevopen (serial_write, NULL);  replaced with the following care of DH */

fdev_setup_stream(&sio_stdout, serial_write, NULL,_FDEV_SETUP_WRITE);
stdout = &sio_stdout ;

}

