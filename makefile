CC = clang
LD = lld
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -fuse-ld=$(LD)
EXECUTABLE = output
SRC = $(wildcard ./src/*.c) $(wildcard ./src/**/*.c) $(wildcard ./src/**/**/*.c)
INCLUDE_DIR = ./inc
BUILD_DIR = ./build

INC_FILES := $(wildcard ./inc/*.h)

$(shell mkdir -p $(BUILD_DIR))

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(BUILD_DIR)/$(EXECUTABLE)

$(ASM_BUILD): $(BUILD_DIR)/$(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)
debug: $(BUILD_DIR)/$(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all clean run