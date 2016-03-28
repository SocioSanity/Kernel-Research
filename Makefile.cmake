CFLAGS	:= -fno-stack-protector -fno-bulitin -nostdinc -O -g -Wall -I

all:	kernel.bin

kernel.bin:	boot.o	main.open
		ld -T link.ld -o kernel.bin boot.o main.o
		@echo Done!

clean:
	rm -f *.o *.bin