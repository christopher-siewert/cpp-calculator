main: main.o calculator.o scientific.o
	g++ -o main main.o calculator.o scientific.o

main.o: main.cpp calculator.h scientific.h
	g++ -c main.cpp

calculator.o: calculator.cpp calculator.h
	g++ -c calculator.cpp

scientific.o: scientific.cpp scientific.h
	g++ -c scientific.cpp
