CC=g++
CCOPT=-lglut -lGL -lGLU -lm
DEBUG=-g

3d-show-map: main.cpp Map.cpp GL.cpp
	$(CC) $(CCOPT) $(DEBUG) -o $@ main.cpp Map.cpp GL.cpp
