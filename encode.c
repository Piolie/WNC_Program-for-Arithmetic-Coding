/* MAIN PROGRAM FOR ENCODING. */

#include <stdlib.h>
#include "model.h"
#include "bit_io.h"

FILE *fi;                                       /* Input file  */
FILE *fo;                                       /* Output file */
int char_to_index[No_of_chars];                 /* To index from character  */
unsigned char index_to_char[No_of_symbols+1];   /* To character from index  */
int cum_freq[No_of_symbols+1];          /* Cumulative symbol frequencies    */

int main(int argc, char *argv[])
{   if (argc != 3) {
        printf("Usage: encode <infile> <encfile>\n");
        exit(EXIT_FAILURE);
    }
    if ((fi = fopen(argv[1], "rb")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fo = fopen(argv[2], "wb")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    start_model();                              /* Set up other modules.    */
    start_outputing_bits();
    start_encoding();
    for (;;) {                                  /* Loop through characters. */
        int ch; int symbol;                    
        ch = getc(fi);                          /* Read the next character. */
        if (ch==EOF) break;                     /* Exit loop on end-of-file.*/
        symbol = char_to_index[ch];             /* Translate to an index.   */
        encode_symbol(symbol,cum_freq);         /* Encode that symbol.      */
        update_model(symbol);                   /* Update the model.        */
    }
    encode_symbol(EOF_symbol,cum_freq);         /* Encode the EOF symbol.   */
    done_encoding();                            /* Send the last few bits.  */
    done_outputing_bits();
    fclose(fi);
    fclose(fo);
    exit(0);
}
