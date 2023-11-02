# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address

# linker flags
LDFLAGS = -fsanitize=address

# source files
SRC += board.cc
SRC += board_test.cc
SRC += ship.cc

# object files
OBJ = $(patsubst %.cc, bin/%.o, $(SRC))

# final executable
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
