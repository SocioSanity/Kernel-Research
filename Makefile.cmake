CFLAGS	:= -fno-stack-protector -fno-bulitin -nostdinc -O -g -Wall -I

all:	kernel.bin

kernel.bin:	boot.o	main.o mem.o basicio.o scrn.o
		ld -T link.ld -o kernel.bin boot.o main.o mem.o basicio.o scrn.o
		@echo Done!