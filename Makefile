CC=g++
CFLAGS=-Wall -g -fno-exceptions -std=c++98
LIBS=-lm
LDFLAGS=

SRC=matrix.cpp quadric.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME=quadric

%.o: %.cpp %.hpp helpers.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.cpp $(OBJ)
	$(CC) $(CFLAGS) $(INCDIR) $(LDFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f *.o
	rm -f $(NAME)
