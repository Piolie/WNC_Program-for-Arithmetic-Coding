CFLAGS = -std=c89 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes
CC=gcc

all: fixed adaptive

# ----------------------------------------------------------------------
# ----------------------------- FIXED MODEL ----------------------------
# ----------------------------------------------------------------------

fixed: encode_f decode_f

encode_f: encode arithmetic_encode bit_output fixed_model
	$(CC) -o encode_f.exe encode.o arithmetic_encode.o bit_output.o fixed_model.o

encode: encode.c model.h
	$(CC) $(CFLAGS) -c encode.c 

arithmetic_encode: arithmetic_encode.c arithmetic_coding.h
	$(CC) $(CFLAGS) -c arithmetic_encode.c

bit_output: bit_output.c
	$(CC) $(CFLAGS) -c bit_output.c

fixed_model: fixed_model.c model.h
	$(CC) $(CFLAGS) -c fixed_model.c

decode_f: decode arithmetic_decode bit_input fixed_model
	$(CC) -o decode_f.exe decode.o arithmetic_decode.o bit_input.o fixed_model.o

decode: decode.c model.h
	$(CC) $(CFLAGS) -c decode.c 

arithmetic_decode: arithmetic_decode.c arithmetic_coding.h
	$(CC) $(CFLAGS) -c arithmetic_decode.c

bit_input: bit_input.c arithmetic_coding.h
	$(CC) $(CFLAGS) -c bit_input.c


# ----------------------------------------------------------------------
# --------------------------- ADAPTIVE MODEL ---------------------------
# ----------------------------------------------------------------------

adaptive: encode_a decode_a

encode_a: encode arithmetic_encode bit_output adaptive_model
	$(CC) -o encode_a.exe encode.o arithmetic_encode.o bit_output.o adaptive_model.o

decode_a: decode arithmetic_decode bit_input adaptive_model
	$(CC) -o decode_a.exe decode.o arithmetic_decode.o bit_input.o adaptive_model.o

adaptive_model: adaptive_model.o model.h
	$(CC) $(CFLAGS) -c adaptive_model.c
