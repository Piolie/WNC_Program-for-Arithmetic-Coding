/* DECLARATIONS USED FOR ARITHMETIC ENCODING AND DECODING */


/* SIZE OF ARITHMETIC CODE VALUES. */

#define Code_value_bits 16              /* Number of bits in a code value   */
typedef long code_value;                /* Type of an arithmetic code value */

#define Top_value (((long)1<<Code_value_bits)-1)      /* Largest code value */


/* HALF AND QUARTER POINTS IN THE CODE VALUE RANGE. */

#define First_qtr (Top_value/4+1)       /* Point after first quarter        */
#define Half      (2*First_qtr)         /* Point after first half           */
#define Third_qtr (3*First_qtr)         /* Point after third quarter        */


/* FUNCTION PROTOTYPES */

void start_encoding(void);          /* START ENCODING A STREAM OF SYMBOLS.  */
void encode_symbol(int symbol, int cum_freq[]); /* ENCODE A SYMBOL.         */
void done_encoding(void);           /* FINISH ENCODING THE STREAM.          */

void start_decoding(void);          /* START DECODING A STREAM OF SYMBOLS.  */
int decode_symbol(int cum_freq[]);  /* DECODE THE NEXT SYMBOL.              */
