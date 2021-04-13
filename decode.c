/* MAIN PROGRAM FOR DECODING. */

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
        printf("Usage: decode <encfile> <decfile>\n");
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
    start_inputing_bits();
    start_decoding();
    for (;;) {                                  /* Loop through characters. */
        int ch; int symbol;
        symbol = decode_symbol(cum_freq);       /* Decode next symbol.      */
        if (symbol==EOF_symbol) break;          /* Exit loop if EOF symbol. */
        ch = index_to_char[symbol];             /* Translate to a character.*/
        putc(ch,fo) ;                       /* Write that character.    */
        update_model(symbol);                   /* Update the model.        */
    }
    fclose(fi);
    fclose(fo);
    exit(0);
}
