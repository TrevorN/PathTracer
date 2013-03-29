CXX = g++
OBJECTS = Scene.o Vector3.o Main.o Camera.o Ray.o Colour.o PngFactory.o

HEADERS = Scene.hpp Vector3.hpp Camera.hpp Ray.hpp Form.hpp Colour.hpp PngFactory.hpp
CFLAGS =

all : ${OBJECTS}
	${CXX} ${CFLAGS} -o bin/PathTracer ${OBJECTS} ${HEADERS}

clean :
	rm -rf *.o
