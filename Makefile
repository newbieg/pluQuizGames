all: game.h buildQuiz.h gui.h

game.h:
	g++  tuimain.cpp plu.cpp -o game

buildQuiz.h:
	g++ quizBuilder.cpp plu.cpp -o buildQuiz

sdl_game.h: gui.h

gui.h:
	g++ -lSDL2 -ISDL2 sdl_game.cpp main.cpp


