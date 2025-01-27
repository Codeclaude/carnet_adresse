#include <iostream>
#include"fonction.h"
  const int TAILLE_INITIALE = 100;

int main(){
  Contact contacts[TAILLE_INITIALE];
    int taille = 0;
    int capacite = TAILLE_INITIALE;

    int choix;
    do {
        affichermenu();
        std::cin >> choix;

        switch (choix) {
            case 1:
                afficherlescontacts(contacts, taille);
                break;
             case 2:
                ajoutercontact(contacts, taille, capacite);
               break;
            case 3:
                std::cout << "Au revoir !" << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez reessayer une autre option." << std::endl;
        }
    } while (choix != 3);

    return 0;
}