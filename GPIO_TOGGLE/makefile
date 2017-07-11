# ----- Configuration ---------------------------------------------------------

PROJECT_NAME = GPIO_TOGGLE

# ----- Directories and files -------------------------------------------------

LIBS = ../libs
SDK_ROOT = $(LIBS)/XMC_Peripheral_Library

LINKER_SCRIPT = XMC4500x1024.ld

# ----- Symbols ---------------------------------------------------------------

SYMBOLS += XMC4500_F100x1024

# ----- Include directories ---------------------------------------------------

INCLUDE_DIRS += $(SDK_ROOT)/XMCLib/inc
INCLUDE_DIRS += $(SDK_ROOT)/CMSIS/Include
INCLUDE_DIRS += $(SDK_ROOT)/CMSIS/Infineon/XMC4500_series/Include

# Application
# INCLUDE_DIRS += src/config

# ----- Source files ----------------------------------------------------------

SOURCE_FILES += $(wildcard $(SDK_ROOT)/XMCLib/src/*.c)
SOURCE_FILES += $(SDK_ROOT)/CMSIS/Infineon/XMC4500_series/Source/system_XMC4500.c
SOURCE_FILES += $(SDK_ROOT)/CMSIS/Infineon/XMC4500_series/Source/GCC/startup_XMC4500.S

# Add all supported source files found in project folder
SOURCE_FILES += $(shell find src -iregex ".*\.\(c\|cpp\|s\)")

# ----- Libraries -------------------------------------------------------------

LIBRARY_DIRS += $(SDK_ROOT)/CMSIS/Infineon/XMC4500_series/Source/GCC

# ----- Flags -----------------------------------------------------------------

ASMFLAGS += -x assembler-with-cpp

GCCFLAGS += -mcpu=cortex-m4
GCCFLAGS += -mthumb

CPPFLAGS +=

COMMON_CFLAGS += -g
COMMON_CFLAGS += -Og

CFLAGS += -std=gnu11

CXXFLAGS += -std=gnu++14

LDFLAGS += -T $(LINKER_SCRIPT)

# ----- Rules -----------------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-

include $(LIBS)/xXx/utils/rules.mk

download: $(EXECUTABLE)
	$(TOOLCHAIN_PREFIX)gdb -q -x download.gdb $<
