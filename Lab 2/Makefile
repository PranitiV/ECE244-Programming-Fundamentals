SRCS = playMove.cpp GameState.cpp tictactoe.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

tictactoe.exe: $(OBJS)
	g++ $^ -o $@
%.o:	%.cpp
	g++ -c -g $< -o $@
clean:
	rm -f *.o  tictactoe.exe core

