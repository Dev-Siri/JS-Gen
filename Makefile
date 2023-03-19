# Compiler options
CC = gcc
CFLAGS = -g -export-dynamic -Wall -O3 -lm -fPIC -Os -s -Ofast -march=native

# Directories
SRC_DIR = src
OBJ_DIR = bin/objects
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Binary file
EXEC = $(BIN_DIR)/jen

# Build rules
all: $(EXEC)

$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	if [ ! -d "$(BIN_DIR)" ]; then mkdir -p "$(BIN_DIR)"; fi

$(OBJ_DIR):
	if [ ! -d "$(OBJ_DIR)" ]; then mkdir -p "$(OBJ_DIR)"; fi

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(EXEC)

.PHONY: all clean