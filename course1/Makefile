#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [BASENAME] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Global Project Definitions
BASENAME = c1m4
MYCUSTOMFLAG = COURSE1
MYCUSTOMPRINT = VERBOSE

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

ARM_ARCH = armv7e-m
ARM_FABI= hard
ARM_FPU = fpv4-sp-d16

CFLAGS = -Wall -Werror -g -O0 -std=c99
LDFLAGS = -Wl,-Map=$(BASENAME).map
CPPFLAGS = -D$(PLATFORM) -D$(MYCUSTOMFLAG) -D$(MYCUSTOMPRINT)

# Choose platform: HOST or MSP432
ifeq ($(PLATFORM), HOST)
    CC = gcc
    LD = ld	
    OBJDMP = objdump
    SIZE = size
else
	ifeq ($(PLATFORM), MSP432)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LDFLAGS += -T $(LINKER_FILE)
		CFLAGS += -mcpu=$(CPU) -m$(ARCH) -march=$(ARM_ARCH) -mfloat-abi=$(ARM_FABI) -mfpu=$(ARM_FPU) --specs=$(SPECS)
		OBJDMP = arm-none-eabi-objdump
		SIZE = arm-none-eabi-size
	endif
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

# Generate preprocessed file .i
%.i : %.c
	$(CC) -E $^ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

# Generate assembled file .asm
%.asm : %.c
	$(CC) -S $^ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

# Generate object file .o
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

# Generate all object files .o
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $^ $(CFLAGS) $(CPPFLAGS) $(INCLUDES)

# Generate final executable .out
.PHONY: build
build:$(BASENAME).out
$(BASENAME).out: $(OBJS)
	# Generate .d files
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -MD $(SOURCES)
	# Compile to BASENAME.out
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@ $^
	# Display Size Information: B = Berkley format; t = show totals; d = decimal
	$(SIZE) -Btd $(OBJS) $(BASENAME).out

# Using objdump utility: D=disassemble
$(BASENAME).asm: build
	$(OBJDMP) -D $(BASENAME).o > $(BASENAME).asm

MYSRC = src
# Clean
.PHONY: clean
clean:
	rm -rf *.o *.out *.map *.asm *.i *.d $(MYSRC)/*.o $(MYSRC)/*.out $(MYSRC)/*.map $(MYSRC)/*.asm $(MYSRC)/*.i $(MYSRC)/*.d

