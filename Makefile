SOURCES:= \
	main.c \
	system_MK66F18.c \
        k66f_startup.c

CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -g -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
CFLAGS+= -IMK66F18
CFLAGS+= -DCPU_MK66FN2M0VLQ18

LDFLAGS= -nostdlib -T k66f_ls.ld -Wl,-Map=blinky.map

all: main.o system_MK66F18.o k66f_startup.o blinky.elf 

OBJECTS:$(SOURCES:.c=.o)
	$(CC) $(CFLAGS) -o $@ $^


blinky.elf: main.o system_MK66F18.o k66f_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf *.map
