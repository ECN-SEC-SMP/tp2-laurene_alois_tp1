#include <iostream>
#include "Vehicule.hpp"




virtual void Vehicule::monter(int nbOcc){
    occupants_ += nbOcc;
}

virtual void Vehicule::descendre(int nbOcc){
    occupants_ -= nbOcc;
}

virtual void Vehicule::mettreEnPanne(double random){
    if(random<0.5) état = PANNE_LEGERE;
    else état = PANNE_SEVERE;
}
    
virtual string Vehicule::getEtat() const{
    return état;
}


