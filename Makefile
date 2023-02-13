BUILD_DIR = ./build/

CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJECTS = $(shell find . -name "*.cpp")

build: setup tex

setup:
	mkdir -p $(BUILD_DIR)

tex: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)$@ $^

clean:
	$(RM) -r $(BUILD_DIR)