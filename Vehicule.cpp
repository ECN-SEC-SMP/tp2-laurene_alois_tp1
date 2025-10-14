#include <iostream>
#include "Vehicule.hpp"




virtual void Vehicule::monter(int nbOcc){
    occupants_ += nbOcc;
}

virtual void Vehicule::descendre(int nbOcc){
    occupants_ -= nbOcc;
}

virtual void Vehicule::mettreEnPanne(double random){
    if(random<0.5) etat_ = PANNE_LEGERE;
    else etat_ = PANNE_SEVERE;
}
    
virtual string Vehicule::getEtat() const{
    return etat_;
}


