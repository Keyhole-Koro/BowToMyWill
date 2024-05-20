CC = clang
LD = lld
CFLAGS = -Wall -Wextra
LDFLAGS = -fuse-ld=$(LD)
EXECUTABLE = output
SRC = $(wildcard ./*.c) $(wildcard ./*/*.c)
INCLUDE_DIRS = ./Directory ./Semantic ./Utils /tmp/cJSON

BUILD_DIR = ./build

$(shell mkdir -p $(BUILD_DIR))

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDE_DIRS)) -o $@ $^ $(LDFLAGS) -lcjson

clean:
	rm -f $(BUILD_DIR)/$(EXECUTABLE)

run: $(BUILD_DIR)/$(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)

debug: $(BUILD_DIR)/$(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all clean run debug
