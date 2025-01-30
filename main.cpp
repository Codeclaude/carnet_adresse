#include <iostream>

#include"fonction.h"
  const int TAILLE_INITIALE = 100;

int main(){
  // declaration d un tableau de type Contact
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
                recherchercontact(contacts, taille);
                break;
                 case 4:
                supprimercontact(contacts, taille);
               break;
                case 5:
                   modifiercontact(contacts, taille);
                break;
            case 6:
                sauvegarderfichier(contacts, taille);
                break;
                case 7:
                 chargerfichier(contacts, taille, capacite);
               break;
                case 8:
                  std::cout << "AU REVOIR !" << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez reessayer une autre option." << std::endl;
        }
    } while (choix != 8);

    return 0;
}