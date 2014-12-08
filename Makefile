#
# Unix/Linux GCC Makefile for CDarkFit
#

CC=gcc
CONFIGFLAGS=#-ULINSOLVERS_RETAIN_MEMORY
#ARCHFLAGS=-march=pentium4 # YOU MIGHT WANT TO UNCOMMENT THIS FOR P4
CFLAGS=$(CONFIGFLAGS) $(ARCHFLAGS) -O3 -funroll-loops -Wall #-g #-ffast-math #-pg
LDFLAGS=-L. -L/usr/local/lib
PROGOBJS=singlediode.o function.o cdarkfit.o
PROGSRCS=singlediode.c function.c cdarkfit.c

all: cdarkfit

cdarkfit: $(PROGOBJS) liblevmar.a
	$(CC) $(LDFLAGS) $(PROGOBJS) -o cdarkfit -llevmar -lm -lgsl -lgslcblas

singlediode.o: 

function.o:
	
cdarkfit.o: levmar.h

clean:
	@rm -f $(PROGOBJS)

cleanall: clean
	@rm -f cdarkfit

depend:
	makedepend -f Makefile $(PROGSRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

