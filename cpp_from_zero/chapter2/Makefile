CXX := g++
CXXFLAGS := -std=c++11 #-Wall -Wextra -Wpedantic

BIN_DIR :=./bin
TARGET := $(BIN_DIR)/main

.PHONY: run clean

run: $(TARGET)
	$(TARGET)

$(TARGET): main.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(TARGET)
