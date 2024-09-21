# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra -I/mingw32/include -ftest-coverage -fprofile-arcs
LDFLAGS := -L/mingw32/lib -lgtest -lgtest_main -pthread -lgcov

# Directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin
COVERAGE_DIR := coverage

# Target executable
TARGET := $(BIN_DIR)/TestResult.exe

# Source files
SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
SRCS += $(wildcard $(TEST_DIR)/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Ensure build, bin, and coverage directories exist
$(shell if not exist $(subst /,\,$(BUILD_DIR)) mkdir $(subst /,\,$(BUILD_DIR)))
$(shell if not exist $(subst /,\,$(BIN_DIR)) mkdir $(subst /,\,$(BIN_DIR)))
$(shell if not exist $(subst /,\,$(COVERAGE_DIR)) mkdir $(subst /,\,$(COVERAGE_DIR)))

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
	@if exist $(subst /,\,$(COVERAGE_DIR)) rmdir /s /q $(subst /,\,$(COVERAGE_DIR))

# Run target
run: $(TARGET)
	$(TARGET)

# Coverage target
coverage: $(TARGET)
	$(TARGET)
	gcovr -r . --html --html-details -o $(COVERAGE_DIR)/coverage.html --exclude "src/example/.*"
	@echo Coverage report generated. Opening in default browser...
	@python -c "import webbrowser; webbrowser.open('file://$(CURDIR)/$(COVERAGE_DIR)/coverage.html')"

.PHONY: all clean run coverage