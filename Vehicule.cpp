#include "Vehicule.hpp"

Vehicule::Vehicule(int vitesseMax=0, int nbPlaces=1, int occupants=0){
	this->vitesseMax_ = vitesseMax;
	this->nbPlaces_ = nbPlaces;
	this->occupants_ = occupants;	
}

virtual void Vehicule::demarrer(){
    try{
        if(etat_ == ARRET){
            etat_ = MARCHE;
        } else cout<<"La voiture ne peut pas démarrer..."<<endl; 
        if(etat_ == PANNE_LEGERE){
        } else throw std::string("à cause d'une panne légère");
        if(etat_ == PANNE_SEVERE){
        } else throw std::string("à cause d'une panne sévère");
        if(etat_ == MARCHE){
        } else throw std::string("parce qu'elle est déjà en marche");
    } catch (std::string const& err_msg) {
        std::cerr << "Exception: " << err_msg << std::endl;
    }
	
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
    try{
        if(vitesse_<0) {
            if (vitesse_+increment < vitesseMax_){
                vitesse_ += increment;
            } else throw std::string("Vitesse max atteinte !");  
        } else throw std::string("Vitesse négative !");  
    } catch (std::string const& err_msg) {
        std::cerr << "Exception: " << err_msg << std::endl;
    }

	
}

virtual void Vehicule::monter(int nbOcc){
    try{
        if(occupants+nbOcc < nbPlaces){
            occupants_ += nbOcc;
        } else throw std::string("La voiture est complète : plus assez de place !");    
    } catch (std::string const& err_msg) {
        std::cerr << "Exception: " << err_msg << std::endl;
    }
    
}

virtual void Vehicule::descendre(int nbOcc){
    try{
        if(nbPlaces != 0){
            occupants_ -= nbOcc;
        } else throw std::string("Tout les passagers sont déjà descendu !"); 
    } catch (std::string const& err_msg) {
        std::cerr << "Exception: " << err_msg << std::endl;
    }
}

virtual void Vehicule::mettreEnPanne(double random){
    if(random<0.5) etat_ = PANNE_LEGERE;
    else etat_ = PANNE_SEVERE;
}
    
virtual string Vehicule::getEtat() const{
    return etat_;
}
