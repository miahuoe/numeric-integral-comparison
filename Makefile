CC = gcc
LD = gcc
ERRLVL = -Wall -Wextra -pedantic -Wimplicit-fallthrough=0
CFLAGS = -std=c99 -O2 $(ERRLVL)
LDFLAGS = -lm
TARGETS = rect_test

all : $(TARGETS)

rect_test : rect_test.o rect.o integrals.o trapez.o
	$(LD) $(LDFLAGS) $^ -o $@

plot1 : rect_test
	./rect_test
	./generate_gnuplot.sh rect_test left middle right trapez

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

strip : $(TARGET)
	strip -S --strip-unneeded --remove-section=.note.gnu.gold-version \
	--remove-section=.comment --remove-section=.note \
	--remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag $^

clean :
	rm -rf *.o *.csv *.png $(TARGETS)
