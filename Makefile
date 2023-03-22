main:
	gcc -o cfunc.o -c cfunc.c
	g++ -o src.o -c src.cpp
	g++ -o testsrc.o -c testsrc.cpp
	g++ -o testsrc2.o -c testsrc2.cpp
	g++ -o testcfunc.o -c testcfunc.cpp
	g++ -o testmain.o -c testmain.cpp
	g++ -o main *.o  -lgtest -pthread


clean:
	rm *.o main