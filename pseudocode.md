/* ARITHMETIC ENCODING ALGORITHM.                                           */

/* Call encode symbol repeatedly for each symbol in the message.            */
/* Ensure that a distinguished "terminator" symbol is encoded last, then    */
/* transmit any value in the range [low, high).                             */

encode symbol(symbol, cum_freq)
    range = high - low
    high  = low + range*cum_freq[symbol-1]
    low   = low + range*cum_freq[symbol]


/* ARITHMETIC DECODING ALGORITHM.                                           */

/* "Value" is the number that has been received.                            */
/* Continue calling decode symbol until the terminator symbol is returned.  */

decode symbol(cum_freq)
    find symbol such that
        cum_freq[symbol] <= (value-low)/(high-low) < cum_freq[symbol-1]
                           /* This ensures that value lies within the new   */
                           /* [low, high) range that will be calculated by  */
                           /* the following lines of code.                  */

    range = high - low
    high  = low + range*cum_freq[symbol-1]
    low   = low + range*cum_freq[symbol]
    return symbol
