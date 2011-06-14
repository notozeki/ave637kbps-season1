CC=g++
OBJS=main.o Map.o GL.o Vector.o Structure.o StructureManager.o SimpleStructure.o
SRCS=$(OBJS:%.o=%.c)
CXXFLAGS=-g -Wall
LDFLAGS=-lglut -lGL -lGLU -lm

3d-show-map: $(OBJS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS)
