# C++ compiler flags
include ~michael.trigoboff/bin/makeflags_g++

vapp:		car.o plane.o boat.o vehicle.o

car.o:		car.h vehicle.h

plane.o:	plane.h vehicle.h

boat.o:		boat.h vehicle.h

vehicle.o:	vehicle.h

.PHONY: x
x:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o vapp
