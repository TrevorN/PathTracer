CXX = g++
OBJECTS = Scene.o Vector3.o Main.o Camera.o Ray.o Form.o

HEADERS = Scene.hpp Vector3.hpp Camera.hpp Ray.hpp Form.hpp
CFLAGS =

all : ${OBJECTS}
	${CXX} ${CFLAGS} -o bin/PathTracer ${OBJECTS} ${HEADERS}

clean :
	rm -rf *.o
