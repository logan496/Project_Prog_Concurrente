#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

// Classe repr�sentant une commande
class Commande {
public:
    int idCommande; // Identifiant unique de la commande
    vector<string> plats; // Liste des plats dans la commande

    // Constructeur
    Commande(int id, vector<string> p) : idCommande(id), plats(p) {}

    // Afficher les d�tails de la commande
    void afficherDetails() {
        cout << "Commande ID: " << idCommande << " avec plats: ";
        for (const auto &plat : plats) cout << plat << " ";
        cout << endl;
    }
};

// Classe repr�sentant le cuisinier et sa gestion des commandes
class Cuisiner {
private:
    queue<Commande> commandes; // File des commandes
    mutex mtx; // Mutex pour s�curiser l'acc�s concurrent � la file
    condition_variable cv; // Condition variable pour synchroniser les threads

public:
    // M�thode pour recevoir une commande
    void recevoirCommande(Commande commande) {
        unique_lock<mutex> lock(mtx);
        commandes.push(commande);
        cout << "Commande " << commande.idCommande << " re�ue." << endl;
        cv.notify_one(); // Notifier qu'une commande est disponible
    }

    // M�thode pour dispatcher les commandes aux cuisiniers
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

            cout << "Commande " << commande.idCommande << " dispatch�e aux cuisiniers." << endl;
            faireCommande(commande); // Appeler la m�thode pour pr�parer la commande
        }
    }

    // M�thode pour pr�parer une commande
    void faireCommande(Commande commande) {
        cout << "Pr�paration de la commande " << commande.idCommande << " en cours..." << endl;
        this_thread::sleep_for(chrono::seconds(3)); // Simuler le temps de pr�paration
        deposerCommande(commande); // D�poser la commande apr�s pr�paration
    }

    // M�thode pour d�poser la commande sur le comptoir
    void deposerCommande(Commande commande) {
        cout << "Commande " << commande.idCommande << " d�pos�e sur le comptoir." << endl;
    }
};

int main() {
    // Cr�er un objet Cuisiner
    Cuisiner cuisinier;

    // Lancer un thread pour dispatcher les commandes
    thread threadDispatcher(&Cuisiner::dispatcherCommande, &cuisinier);

    // Simuler la r�ception de commandes
    cuisinier.recevoirCommande(Commande(1, {"Pizza", "Salade"}));
    this_thread::sleep_for(chrono::seconds(1));
    cuisinier.recevoirCommande(Commande(2, {"Soupe", "Steak"}));

    // Attendre que l'utilisateur appuie sur Entr�e pour quitter
    cout << "Appuyez sur Entr�e pour quitter..." << endl;
    cin.get();

    // Terminer le thread
    threadDispatcher.detach(); // D�tacher le thread avant de quitter le programme

    return 0;
}
