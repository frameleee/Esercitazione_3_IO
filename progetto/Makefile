CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC_DIR = src
OBJ_DIR = obj

all: main

main: main.o Utils.o
	$(CXX) $(CXXFLAGS) -o main main.o Utils.o

main.o: main.cpp $(SRC_DIR)/Utils.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Utils.o: $(SRC_DIR)/Utils.cpp $(SRC_DIR)/Utils.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Utils.cpp

clean:
	rm -f *.o main
