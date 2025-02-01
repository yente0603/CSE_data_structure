CC = gcc
CXX = g++
CFLAGS = -std=c11
CXXFLAGS = -std=c++11

BUILD_DIR = build

# Check if FILE is specified, but allow 'make clean' to run without FILE
ifneq ($(MAKECMDGOALS), clean)  # If the target is NOT 'clean'
ifndef FILE
$(error Error: Please specify a source file using 'make FILE=filename.c' or 'make FILE=filename.cpp')
endif
endif

# Generate output filename based on input source file
TARGET = $(BUILD_DIR)/$(basename $(FILE)).elf

# Default target to build the specified file
build: $(TARGET)

# Compilation rule for creating the target binary
$(TARGET): $(FILE)
	@mkdir -p $(BUILD_DIR)
	@if echo "$(FILE)" | grep -qE "\.cpp$$"; then \
		$(CXX) $(CXXFLAGS) $(FILE) -o $(TARGET); \
		echo "$(CXX) $(CXXFLAGS) $(FILE) -o $(TARGET)"; \
	else \
		$(CC) $(CFLAGS) $(FILE) -o $(TARGET); \
		echo "$(CC) $(CFLAGS) $(FILE) -o $(TARGET)"; \
	fi
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*.elf $(BUILD_DIR)
