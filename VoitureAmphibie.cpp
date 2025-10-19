#include "VoitureAmphibie.hpp"


void VoitureAmphibie::afficherCapacites()
{
        std::cout << "Amphibie \"" << name_ << "\"\n";
        std::cout << "  masse: " << mass_ << " kg\n";
        std::cout << "  vmax route: " << vmax_route_ << " km/h\n";
        std::cout << "  vmax eau:   " << vmax_eau_   << " nds\n";
    }

void VoitureAmphibie::demarrer() {
        Voiture::demarrer();
        Bateau::demarrer();
}

void VoitureAmphibie::arreter() {
    Voiture::arreter();
    Bateau::arreter();
}