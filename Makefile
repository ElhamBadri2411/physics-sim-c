CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bin/sim
OBJS = bin/sim.o bin/vector.o
BUILD_DIR = bin

all: $(TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm -lGL -lGLU -lglut

$(BUILD_DIR)/sim.o: sim.c sim.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c sim.c -o $(BUILD_DIR)/sim.o

$(BUILD_DIR)/vector.o: vector.c vector.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c vector.c -o $(BUILD_DIR)/vector.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)


