# Very simple makefile for minimum $(BINNAME)er
# 
BUILDDIR=bin
SRCDIR=src
INC=inc
PREFIX=arm-none-eabi-

# C compiler
CC=$(PREFIX)gcc
CFLAGS=-mthumb -mcpu=cortex-m4 -I$(INC)

# Linker
LD=$(PREFIX)ld
LDFLAGS= -T$(SRCDIR)/simple.ld -nostdlib

SOURCES=$(SRCDIR)/main.c $(SRCDIR)/led.c $(SRCDIR)/startup.s

OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))
ELF=$(BUILDDIR)/program.elf

$(ELF): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

flash: $(ELF)
	openocd -f board/stm32f4discovery.cfg -c "program $(ELF) verify reset exit"
	#./write_bin.sh $(ELF)

clean:
	rm -rf $(BUILDDIR)/*
