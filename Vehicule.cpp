#include "Vehicule.hpp"

Vehicule::Vehicule(int vitesseMax=0, int nbPlaces=1, int occupants=0){
	this->vitesseMax_ = vitesseMax;
	this->nbPlaces_ = nbPlaces;
	this->occupants_ = occupants;	
}

virtual void Vehicule::demarrer(){
	etat_ = MARCHE;
}

virtual void Vehicule::arreter(){
	etat_ = ARRET;
}

virtual void Vehicule::depanner(){
	if (etat_ = PANNE_LEGERE or PANNE_SEVERE){
		etat_ = MARCHE;
	}
}

virtual void Vehicule::accelerer(int increment){
	vitesse_ += increment;
	if (vitesse_ > vitesseMax_){
		vitesse_ = vitesseMax_;
	}
}

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
