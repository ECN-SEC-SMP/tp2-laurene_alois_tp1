all: main.exe

main.exe: main.o Vehicule.o 
	g++ -o main.exe main.o Vehicule.o

main.o: main.cpp
	g++ -c main.cpp

Vehicule.o: Vehicule.cpp
	g++ -c Vehicule.cpp

