#compiler we are using
CC = clang++

#compiler flag 
COMPILER_FLAGS = -Weverything -Wno-c++98-compat -std=c++1z # -Weverything opens all warnings -std=c++1z is c++17

#Linker flags
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf 

OBJ_NAME = tictactoe

#output
tictactoe: game.o board.o button.o textureManager.o
	$(CC) tictactoe.cpp game.o  board.o button.o textureManager.o $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#textureManager
textureManager.o: textureManager.hpp textureManager.cpp
	$(CC) -c textureManager.cpp $(COMPILER_FLAGS)
#game
game.o: game.cpp game.hpp button.o board.o 
	$(CC) -c game.cpp  $(COMPILER_FLAGS)
# board
board.o: board.cpp board.hpp myTexture.hpp myTexture.hpp textureManager.hpp
	$(CC) -c  board.cpp $(COMPILER_FLAGS)

#button
button.o: button.cpp button.hpp myTexture.hpp textureManager.hpp
	$(CC) -c button.cpp   $(COMPILER_FLAGS)
clean:
	rm *.o tictactoe 
