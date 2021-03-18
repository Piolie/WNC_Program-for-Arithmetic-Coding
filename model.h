/* INTERFACE TO THE MODEL. */


/* THE SET OF SYMBOLS THAT MAY BE ENCODED. */

#define No_of_chars 256                 /* Number of character symbols      */
#define EOF_symbol (No_of_chars+1)      /* Index of EOF symbol              */

#define No_of_symbols (No_of_chars+1)   /* Total number of symbols          */


/* TRANSLATION TABLES BETWEEN CHARACTERS AND SYMBOL INDEXES. */

int char_to_index[No_of_chars];         /* To index from character          */
unsigned char index_to_char[No_of_symbols+1]; /* To character from index    */


/* CUMULATIVE FREQUENCY TABLE. */

#define Max_frequency 16383             /* Maximum allowed frequency count  */
                                        /* 2^14 - 1                         */
int cum_freq[No_of_symbols+1];          /* Cumulative symbol frequencies    */


/* FUNCTION PROTOTYPES */

void start_encoding(void);          /* START ENCODING A STREAM OF SYMBOLS.  */
void encode_symbol(int symbol, int cum_freq[]); /* ENCODE A SYMBOL.         */
void done_encoding(void);           /* FINISH ENCODING THE STREAM.          */

void start_decoding(void);          /* START DECODING A STREAM OF SYMBOLS.  */
int decode_symbol(int cum_freq[]);  /* DECODE THE NEXT SYMBOL.              */


void start_model(void);             /* INITIALIZE THE MODEL.                */
void update_model(int symbol);      /* UPDATE THE MODEL TO ACCOUNT          */
                                    /* FOR A NEW SYMBOL.                    */
