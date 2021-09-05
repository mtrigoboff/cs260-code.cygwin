# C compiler flags
include ~michael.trigoboff/bin/makeflags_gcc

vapp:			vapp.o vehicles.o
				$(CC) $(CFLAGS) $^ -o vapp -lm

vapp.o:			vehicles.h vehicles_priv.h

vehicles.o:		vehicles.h vehicles_priv.h

.PHONY: x
x:				# clean the directory
				rm -f *.o vapp
