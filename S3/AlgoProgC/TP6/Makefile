#makefile pile dynamique
CC = cc
CFLAGS =-Wall -g

EXECS = \
	tri_rapide_moodle

all : $(EXECS)

clean:
	rm -rf $(EXECS) *.o

tri_rapide_moodle: tri_rapide_moodle.o pile.o
	$(CC) -o $@ $^ $(CFLAGS)

pile.o: pile.h

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
