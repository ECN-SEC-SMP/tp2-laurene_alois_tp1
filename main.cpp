#include <iostream>
#include <stdexcept>
#include <string>
#include "Vehicule.hpp"

using std::cout;
using std::endl;
using std::string;

#define ASSERT_TRUE(cond) do { \
  if(!(cond)) { \
    std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ << " => " #cond << std::endl; \
    return false; \
  } \
} while(0)

#define ASSERT_EQ_STR(a,b) do { \
  if((a) != (b)) { \
    std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
              << " => expected '" << (b) << "' got '" << (a) << "'" << std::endl; \
    return false; \
  } \
} while(0)

// Catch n’importe quel type d’exception (std::exception, std::string, etc.)
#define EXPECT_THROW_ANY(stmt) do { \
  bool caught=false; \
  try { stmt; } \
  catch(...) { caught=true; } \
  if(!caught){ \
    std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
              << " => expected exception in: " #stmt << std::endl; \
    return false; \
  } \
} while(0)

#define EXPECT_NO_THROW(stmt) do { \
  try { stmt; } \
  catch(...) { \
    std::cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
              << " => unexpected exception in: " #stmt << std::endl; \
    return false; \
  } \
} while(0)

// ------- TESTS --------

// État nominal: démarre, accélère, s’arrête (pas d’exception)
static bool test_nominal_cycle() {
  Vehicule v(130, 5, 0);                 // vmax=130, places=5, occupants=0
  ASSERT_EQ_STR(v.getEtat(), "ARRET");
  EXPECT_NO_THROW(v.demarrer());
  ASSERT_EQ_STR(v.getEtat(), "MARCHE");
  EXPECT_NO_THROW(v.accelerer(50));
  EXPECT_NO_THROW(v.arreter());
  ASSERT_EQ_STR(v.getEtat(), "ARRET");
  return true;
}

// Démarrer deux fois (doit lever à la 2e)
static bool test_demarrer_deux_fois() {
  Vehicule v(130, 5, 0);
  EXPECT_NO_THROW(v.demarrer());
  ASSERT_EQ_STR(v.getEtat(), "MARCHE");
  EXPECT_THROW_ANY(v.demarrer());        // déjà en marche
  return true;
}

// Démarrer en panne (lève), puis dépanner et redémarrer (OK)
static bool test_panne_demarrer_depanner() {
  Vehicule v(130, 5, 0);
  v.mettreEnPanne(0.2);                  // < 0.5 => PANNE_LEGERE (selon ton implémentation)
  ASSERT_TRUE(v.getEtat() == "PANNE_LEGERE" || v.getEtat() == "PANNE_SEVERE");
  EXPECT_THROW_ANY(v.demarrer());
  EXPECT_NO_THROW(v.depanner());
  // après depanner, on s'attend à pouvoir démarrer
  EXPECT_NO_THROW(v.demarrer());
  ASSERT_EQ_STR(v.getEtat(), "MARCHE");
  return true;
}

// Accélérer: cas limites et erreurs
static bool test_accelerer_borniers() {
  Vehicule v(100, 5, 0);
  EXPECT_NO_THROW(v.demarrer());

  // increment <= 0 -> exception
  EXPECT_THROW_ANY(v.accelerer(0));
  EXPECT_THROW_ANY(v.accelerer(-10));

  // jusqu’à la limite ok
  EXPECT_NO_THROW(v.accelerer(60));
  EXPECT_NO_THROW(v.accelerer(40));      // atteint 100

  // au-delà de Vmax -> exception
  EXPECT_THROW_ANY(v.accelerer(1));
  return true;
}

// Capacités: monter/descendre, erreurs de bornes
static bool test_capacites_places() {
  Vehicule v(130, 2, 0);

  // monter OK
  EXPECT_NO_THROW(v.monter(1));
  EXPECT_NO_THROW(v.monter(1));          // places pleines

  // plus de place
  EXPECT_THROW_ANY(v.monter(1));

  // descendre trop (plus que occupants) -> exception
  EXPECT_THROW_ANY(v.descendre(3));

  // descendre ok
  EXPECT_NO_THROW(v.descendre(2));

  // déjà vide
  EXPECT_THROW_ANY(v.descendre(1));

  // nbOcc invalide
  EXPECT_THROW_ANY(v.monter(0));
  EXPECT_THROW_ANY(v.descendre(0));
  EXPECT_THROW_ANY(v.monter(-1));
  EXPECT_THROW_ANY(v.descendre(-1));
  return true;
}

// Redémarrage après arrêt: OK
static bool test_redemarrer_apres_arret() {
  Vehicule v(130, 5, 0);
  EXPECT_NO_THROW(v.demarrer());
  EXPECT_NO_THROW(v.arreter());
  ASSERT_EQ_STR(v.getEtat(), "ARRET");
  EXPECT_NO_THROW(v.demarrer());
  ASSERT_EQ_STR(v.getEtat(), "MARCHE");
  return true;
}



int main() {
  int passed = 0, total = 0;

  auto RUN = [&](const char* name, bool(*fn)()){
    ++total;
    bool ok = fn();
    if(ok){ ++passed; cout << "[OK]   " << name << "\n"; }
    else    cout << "[FAIL] " << name << "\n";
  };

  RUN("nominal_cycle",              test_nominal_cycle);
  RUN("demarrer_deux_fois",         test_demarrer_deux_fois);
  RUN("panne_demarrer_depanner",    test_panne_demarrer_depanner);
  RUN("accelerer_borniers",         test_accelerer_borniers);
  RUN("capacites_places",           test_capacites_places);
  RUN("redemarrer_apres_arret",     test_redemarrer_apres_arret);

  cout << "\n" << passed << "/" << total << " tests passed\n";
  return (passed==total) ? 0 : 1;
}
