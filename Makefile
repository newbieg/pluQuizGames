all: game.h buildQuiz.h gui.h

game.h:
	g++  tuimain.cpp plu.cpp -o game

buildQuiz.h:
	g++ quizBuilder.cpp plu.cpp -o buildQuiz

sdl_game.h: gui.h

gui.h:
	g++ -lSDL2 -lSDL2_image -ISDL2  gui_game.cpp plu.cpp main.cpp
	
test.h:
	g++ -lSDL2 -lSDL2_image -ISDL2 rendererTest.cpp -o rend.o
