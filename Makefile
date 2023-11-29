# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address

# linker flags
LDFLAGS = -fsanitize=address -lncurses

# source files
SRC += board.cc
SRC += game.cc
SRC += ship.cc
SRC += playerio.cc

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
