CXX =  clang++

CFLAGS = -stdlib=libc++ -std=c++11 -march=native -Wall -g -c

LFLAGS = -lpng

SOURCES = Scene.cpp Vector3.cpp Main.cpp Camera.cpp Ray.cpp Colour.cpp Diffuse.cpp Emissive.cpp PngFactory.cpp Sphere.cpp Mirror.cpp Cylinder.cpp Plane.cpp Triangle.cpp Refractive.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXE = bin/PathTracer

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CXX) $(LFLAGS) $(OBJECTS) -o $(EXE)

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean :
	rm -rf *.o
