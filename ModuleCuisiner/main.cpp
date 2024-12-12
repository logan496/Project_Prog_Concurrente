#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

// Classe représentant une commande
class Commande {
public:
    int idCommande; // Identifiant unique de la commande
    vector<string> plats; // Liste des plats dans la commande

    // Constructeur
    Commande(int id, vector<string> p) : idCommande(id), plats(p) {}

    // Afficher les détails de la commande
    void afficherDetails() {
        cout << "Commande ID: " << idCommande << " avec plats: ";
        for (const auto &plat : plats) cout << plat << " ";
        cout << endl;
    }
};

// Classe représentant le cuisinier et sa gestion des commandes
class Cuisiner {
private:
    queue<Commande> commandes; // File des commandes
    mutex mtx; // Mutex pour sécuriser l'accès concurrent à la file
    condition_variable cv; // Condition variable pour synchroniser les threads

public:
    // Méthode pour recevoir une commande
    void recevoirCommande(Commande commande) {
        unique_lock<mutex> lock(mtx);
        commandes.push(commande);
        cout << "Commande " << commande.idCommande << " reçue." << endl;
        cv.notify_one(); // Notifier qu'une commande est disponible
    }

    // Méthode pour dispatcher les commandes aux cuisiniers
    void dispatcherCommande() {
        while (true) {
            Commande commande(0, {});
            {
                unique_lock<mutex> lock(mtx);
                // Attendre qu'une commande soit disponible
                cv.wait(lock, [&]() { return !commandes.empty(); });
                commande = commandes.front();
                commandes.pop();
            }

            cout << "Commande " << commande.idCommande << " dispatchée aux cuisiniers." << endl;
            faireCommande(commande); // Appeler la méthode pour préparer la commande
        }
    }

    // Méthode pour préparer une commande
    void faireCommande(Commande commande) {
        cout << "Préparation de la commande " << commande.idCommande << " en cours..." << endl;
        this_thread::sleep_for(chrono::seconds(3)); // Simuler le temps de préparation
        deposerCommande(commande); // Déposer la commande après préparation
    }

    // Méthode pour déposer la commande sur le comptoir
    void deposerCommande(Commande commande) {
        cout << "Commande " << commande.idCommande << " déposée sur le comptoir." << endl;
    }
};

int main() {
    // Créer un objet Cuisiner
    Cuisiner cuisinier;

    // Lancer un thread pour dispatcher les commandes
    thread threadDispatcher(&Cuisiner::dispatcherCommande, &cuisinier);

    // Simuler la réception de commandes
    cuisinier.recevoirCommande(Commande(1, {"Pizza", "Salade"}));
    this_thread::sleep_for(chrono::seconds(1));
    cuisinier.recevoirCommande(Commande(2, {"Soupe", "Steak"}));

    // Attendre que l'utilisateur appuie sur Entrée pour quitter
    cout << "Appuyez sur Entrée pour quitter..." << endl;
    cin.get();

    // Terminer le thread
    threadDispatcher.detach(); // Détacher le thread avant de quitter le programme

    return 0;
}
