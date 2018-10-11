build : test.o 
	g++ -o build test.o 
test.o : test.cpp
	g++ -g -c test.cpp
clean :
	del test.o build.exe