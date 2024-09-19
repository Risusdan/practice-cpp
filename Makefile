# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra -I/mingw32/include
LDFLAGS := -L/mingw32/lib -lgtest -lgtest_main -pthread

# Directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin

# Target executable
TARGET := $(BIN_DIR)/TestResult.exe

# Source files
SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
SRCS += $(wildcard $(TEST_DIR)/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Ensure build and bin directories exist
$(shell if not exist $(subst /,\,$(BUILD_DIR)) mkdir $(subst /,\,$(BUILD_DIR)))
$(shell if not exist $(subst /,\,$(BIN_DIR)) mkdir $(subst /,\,$(BIN_DIR)))

# Main target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(subst /,\,$(@D)) mkdir $(subst /,\,$(@D))
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	@if exist $(subst /,\,$(BUILD_DIR)) rmdir /s /q $(subst /,\,$(BUILD_DIR))
	@if exist $(subst /,\,$(BIN_DIR)) rmdir /s /q $(subst /,\,$(BIN_DIR))

# Run target
run: $(TARGET)
	$(TARGET)

.PHONY: all clean run