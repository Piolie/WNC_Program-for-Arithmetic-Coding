/* BIT OUTPUT ROUTINES. */

#include <stdio.h>
#include "bit_io.h"


/* THE BIT BUFFER. */

static int buffer;              /* Bits buffered for output                 */
static int bits_to_go;          /* Number of bits free in buffer            */


/* INITIALIZE FOR BIT OUTPUT. */

void start_outputing_bits(void)
{   buffer = 0;                                 /* Buffer is empty to start */
    bits_to_go= 8;                              /* with.                    */
}


/* OUTPUT A BIT. */

void output_bit(int bit)
 /* int bit; */
{   buffer >>= 1;                               /* Put bit in top of buffer.*/
    if (bit) buffer |= 0x80;
    bits_to_go -= 1;
    if (bits_to_go==0) {                        /* Output buffer if it is   */
        putc(buffer,fo);                        /* now full.                */
        bits_to_go = 8;
    }
}


/* FLUSH OUT THE LAST BITS. */

void done_outputing_bits(void)
{   putc(buffer>>bits_to_go,fo);
}
