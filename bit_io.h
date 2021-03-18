/* BIT INPUT/OUTPUT ROUTINES. */

void start_inputing_bits(void);     /* INITIALIZE BIT INPUT.                */
int input_bit(void);                /* INPUT A BIT.                         */

void start_outputing_bits(void);    /* INITIALIZE FOR BIT OUTPUT.           */
void output_bit(int bit);           /* OUTPUT A BIT.                        */
void done_outputing_bits(void);     /* FLUSH OUT THE LAST BITS.             */
