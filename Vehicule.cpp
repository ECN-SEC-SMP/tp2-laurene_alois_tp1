#include <iostream>
#include "Vehicule.hpp"


Vehicule::Vehicule(int vitesseMax=0, int nbPlaces=1, int occupants=0){
    vitesseMax_ = vitesseMax;

}

virtual void mettreEnPanne(double random){
    if(random<0.5) EtatVehicule = PANNE_LEGERE;
    else EtatVehicule = PANNE_SEVERE;
}
    
virtual string getEtat() const{
    return EtatVehicule;
}


