mac:
	g++ -c Lab0.cpp
	g++ -c GLSL_helper.cpp
	g++ -c MStackHelp.cpp
	g++ -c GeometryCreator.cpp
	g++ -c Mask.cpp
	g++ -c Plants.cpp
	g++ -c Trees.cpp
	g++ -c MiniMasks.cpp
	g++ -c Trunks.cpp
	g++ -c Creatures.cpp
	g++ -c Animals.cpp
	g++ Lab0.o GLSL_helper.o MStackHelp.o GeometryCreator.o Mask.o Plants.o Trees.o MiniMasks.o Trunks.o Creatures.o Animals.o -DGL_GLEXT_PROTOTYPES -framework OpenGL -framework GLUT
	./a.out
#linux:
#    g++ Lab0.cpp GLSL_helper.cpp MStackHelp.cpp -lGL -lGLU -lglut
