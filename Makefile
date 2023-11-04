# Detect the operating system
ifeq ($(OS),Windows_NT)
    CXX = clang++
else
    CXX = g++
endif

# Compiler flags
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address

# Linker flags for Clang
LDFLAGS = -fsanitize=address

INCFLAGS = -I/path/to/your/compiler/include

# Source files
SRC += board.cc
SRC += board_test.cc
SRC += ship.cc

# Object files
OBJ = $(patsubst %.cc, bin/%.o, $(SRC))

# Final executable
EXEC = bin/main.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

bin/%.o: %.cc | bin
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin:
	mkdir -p bin

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(OBJ) $(EXEC)
