#@copyright: Ziad Osama
Project_name=unit3_lab4_cortexM4
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AsSRC = $(wildcard *.s)
AsOBJ = $(AsSRC:.s=.o)



all: $(Project_name).bin
	@echo "=============Build Complete============="
#*startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@
#-std=c99

%.o: %.c 
	$(CC)gcc.exe -c $(CFLAGS) -std=c99 $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin
 