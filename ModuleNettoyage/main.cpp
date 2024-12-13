#include <iostream>
#include <vector>
#include <string>

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

class LaveVaisselle {
public:
    void laver(std::vector<Objet>& objets) {
        std::cout << "Lavage des objets...\n";
        for (auto& objet : objets) {
            if (objet.estSale) {
                objet.nettoyer();
            }
        }
    }
};

class ModuleNettoyage {
private:
    std::vector<Objet> objetsSales;
    LaveVaisselle laveVaisselle;
    std::vector<Objet> objetsPropres;

public:
    void recevoirObjet(std::string nom) {
        objetsSales.push_back(Objet(nom));
        std::cout << nom << " a �t� re�u et est maintenant sale.\n";
    }

    void passerAuLaveVaisselle() {
        if (objetsSales.empty()) {
            std::cout << "Aucun objet � laver.\n";
            return;
        }
        laveVaisselle.laver(objetsSales);
        objetsPropres.insert(objetsPropres.end(), objetsSales.begin(), objetsSales.end());
        objetsSales.clear();  // On vide la liste des objets sales apr�s nettoyage
    }

    void recupererObjetsPropres() {
        std::cout << "R�cup�ration des objets propres :\n";
        for (const auto& objet : objetsPropres) {
            std::cout << "- " << objet.nom << " est propre.\n";
        }
        objetsPropres.clear();  // On vide la liste des objets propres apr�s r�cup�ration
    }

    void afficherObjetsSales() {
        std::cout << "Objets sales :\n";
        for (const auto& objet : objetsSales) {
            std::cout << "- " << objet.nom << "\n";
        }
    }
};

int main() {
    ModuleNettoyage module;

    // Recevoir des objets sales
    module.recevoirObjet("Nappe");
    module.recevoirObjet("Ustensile 1");
    module.recevoirObjet("Ustensile 2");

    // Afficher les objets sales
    module.afficherObjetsSales();

    // Passer au lave-vaisselle
    module.passerAuLaveVaisselle();

    // R�cup�rer les objets propres
    module.recupererObjetsPropres();

    return 0;
}
