CXX = g++
OBJECTS = Scene.o Vector3.o Main.o Camera.o #Ray.o

HEADERS = Scene.hpp Vector3.hpp Camera.hpp #Ray.o
CFLAGS =

all : ${OBJECTS}
	${CXX} ${CFLAGS} -o bin/PathTracer ${OBJECTS} ${HEADERS}

