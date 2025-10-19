#include <stdlib.h>
#include "Vehicule.hpp"
#include <iostream>

class Bateau : public virtual Vehicule {
private:

public:
    Bateau(int vitesseMax=0, int nbPlaces=1, int occupants=0) : Vehicule(vitesseMax, nbPlaces, occupants) {}
    ~Bateau() override = default;

    void demarrer() override;
    void arreter()  override;

};