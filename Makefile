all: main.exe

main.exe: main.o Vehicule.o Voiture.o Bateau.o VoitureAmphibie.o
	g++ -o main.exe main.o Vehicule.o Voiture.o Bateau.o VoitureAmphibie.o

main.o: main.cpp
	g++ -c main.cpp

Vehicule.o: Vehicule.cpp
	g++ -c Vehicule.cpp

Voiture.o: Voiture.cpp
	g++ -c Voiture.cpp

Bateau.o: Bateau.cpp
	g++ -c Bateau.cpp

VoitureAmphibie.o: VoitureAmphibie.cpp
	g++ -c VoitureAmphibie.cpp
