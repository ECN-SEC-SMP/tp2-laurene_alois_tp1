#include <stdlib.h>
#include "Vehicule.hpp"
#include <iostream>

class Voiture : public virtual Vehicule {
private:

public:
    Voiture(int vitesseMax=0, int nbPlaces=1, int occupants=0) : Vehicule(vitesseMax, nbPlaces, occupants) {}
    ~Voiture() override = default;

    friend void Vehicule::demarrer();
    
    friend void Vehicule::arreter();

};