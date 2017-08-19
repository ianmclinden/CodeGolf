###################
# Ian McLinden
###################
CC=gcc
CFLAGS= -O2 -g
###############

# -------- Master Compilation ---------------------------------------------------------------------------------------- #

all:	build test clean

build:	main.c framework/*.h golfs/*.h
	@$(CC) $(CFLAGS) -o golf main.c

test:
	@./golf

clean:
	@rm -Rf *.dSYM *.o golf
