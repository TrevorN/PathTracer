CXX = g++ -g
OBJECTS = Scene.o Vector3.o Main.o Camera.o Ray.o Colour.o Diffuse.o PngFactory.o Sphere.o Mirror.o

HEADERS = Scene.hpp Vector3.hpp Camera.hpp Ray.hpp Form.hpp Colour.hpp Diffuse.hpp PngFactory.hpp Material.hpp Sphere.hpp Mirror.hpp

CFLAGS = -lpng

all : ${OBJECTS}
	${CXX} ${CFLAGS} -o bin/PathTracer ${OBJECTS} -x c++-header ${HEADERS}

clean :
	rm -rf *.o
