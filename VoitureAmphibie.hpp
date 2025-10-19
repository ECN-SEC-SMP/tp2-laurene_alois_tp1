#include "Voiture.hpp"
#include "Bateau.hpp"
#include <iostream>
#pragma once

class VoitureAmphibie : public Voiture, public Bateau {
private:
    std::string name_;
    double mass_;
    int vmax_route_;
    int vmax_eau_;

public:
    VoitureAmphibie(int vitesseMax=0, int nbPlaces=1, int occupants=0) 
        : Vehicule(vitesseMax, nbPlaces, occupants), 
          Voiture(vitesseMax, nbPlaces, occupants), 
          Bateau(vitesseMax, nbPlaces, occupants) {}
    ~VoitureAmphibie() override = default;

    void afficherCapacites();

    void demarrer() override;

    void arreter() override;
};