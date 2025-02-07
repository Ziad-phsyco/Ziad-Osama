#@copyright: Ziad Osama
Project_name=learn-in-depth-cortex-m3
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AsSRC = $(wildcard *.s)
AsOBJ = $(AsSRC:.s=.o)



all: $(Project_name).bin
	@echo "===========Build Complete============="
#*startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c 
	$(CC)gcc.exe -c -std=c99 $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin
 