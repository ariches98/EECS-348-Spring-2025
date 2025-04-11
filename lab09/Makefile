# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Output executable
TARGET = lab9

# Source files
SRC = main.cpp
HDR = Matrix.hpp Matrix.tpp

# Build target
$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	rm -f $(TARGET)
