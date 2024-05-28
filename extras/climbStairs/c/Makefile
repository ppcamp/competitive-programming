LIBFILE=libclimbstairs.so
INPUT_FILE=climbstairs.cpp
BRIDGE_FILE=climbstairs.bridge.cpp

FLAGS=-std=c++20 -O3 -Wall -Wextra -fPIC -shared

build:
    # the output file must have this constant name
	g++ -o $(LIBFILE) $(INPUT_FILE) $(BRIDGE_FILE) $(FLAGS)