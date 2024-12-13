#include <iostream>
#include <vector>
#include <string>

class Commande {
public:
    std::string plat;
    bool estPrete;

    Commande(std::string plat) : plat(plat), estPrete(false) {}

    void preparer() {
        std::cout << "Pr�paration de " << plat << "...\n";
        estPrete = true;
        std::cout << plat << " est pr�t.\n";
    }
};

class ModuleCuisiner {
private:
    std::vector<Commande> commandes;

public:
    void recevoirCommande(std::string plat) {
        commandes.push_back(Commande(plat));
        std::cout << "Commande re�ue : " << plat << "\n";
    }

    void dispatcherCommandes() {
        std::cout << "Dispatching des commandes...\n";
        for (auto& commande : commandes) {
            commande.preparer();
        }
        commandes.clear();  // On vide la liste des commandes apr�s pr�paration
    }

    void deposerCommande() {
        std::cout << "D�poser toutes les commandes sur le comptoir.\n";
    }
};

class Objet {
public:
    std::string nom;
    bool estSale;

    Objet(std::string nom) : nom(nom), estSale(true) {}

    void nettoyer() {
        estSale = false;
        std::cout << nom << " a �t� nettoy�.\n";
    }
};

class ModuleNettoyage {
private:
    std::vector<Objet> objetsSales;

public:
    void recevoirObjet(std::string nom) {
        objetsSales.push_back(Objet(nom));
        std::cout << nom << " a �t� re�u et est maintenant sale.\n";
    }

    void passerAuLaveVaisselle() {
        std::cout << "Lavage des objets...\n";
        for (auto& objet : objetsSales) {
            objet.nettoyer();
        }
        objetsSales.clear();  // On vide la liste des objets sales apr�s nettoyage
    }

    void recupererObjetsPropres() {
        std::cout << "Tous les objets sales ont �t� nettoy�s.\n";
    }
};

int main() {
    ModuleCuisiner moduleCuisiner;
    ModuleNettoyage moduleNettoyage;

    // Module Cuisiner
    moduleCuisiner.recevoirCommande("Pizza");
    moduleCuisiner.dispatcherCommandes();
    moduleCuisiner.deposerCommande();

    // Module Nettoyage
    moduleNettoyage.recevoirObjet("Nappe");
    moduleNettoyage.recevoirObjet("Ustensile 1");
    moduleNettoyage.passerAuLaveVaisselle();
    moduleNettoyage.recupererObjetsPropres();

    return 0;
}
