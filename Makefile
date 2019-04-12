CC = gcc
LD = gcc
ERRLVL = -Wall -Wextra -pedantic -Wimplicit-fallthrough=0
CFLAGS = -std=c99 -g $(ERRLVL)
LDFLAGS = -static
TARGETS = rect_test

all : $(TARGETS)

rect_test : rect_test.o rect.o integrals.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

strip : $(TARGET)
	strip -S --strip-unneeded --remove-section=.note.gnu.gold-version \
	--remove-section=.comment --remove-section=.note \
	--remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag $^

clean :
	rm -rf *.o *.csv $(TARGETS)
