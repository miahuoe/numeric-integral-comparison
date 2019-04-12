CC = gcc
LD = gcc
ERRLVL = -Wall -Wextra -pedantic -Wimplicit-fallthrough=0
CFLAGS = -std=c99 -g $(ERRLVL)
LDFLAGS = -static
TARGETS = integral

all : $(TARGETS)

integral : integral.o random.o monte_carlo.o rect.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

strip : $(TARGET)
	strip -S --strip-unneeded --remove-section=.note.gnu.gold-version \
	--remove-section=.comment --remove-section=.note \
	--remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag $^

clean :
	rm -rf *.o $(TARGETS)
