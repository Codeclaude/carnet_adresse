#include<iostream>
#include<cstring>//pour utiliserstrcmp
#include <fstream>//pour la mainipulation des fichiers
#include<string>//pour utiliser getline et std::string
#include"fonction.h"//pour les prototypes de nos fonctions

// fonction pour afficher un contact
void affichercontact(const Contact& contact) {
   std::cout<< "Nom: " << contact.nom  << ", Prenom: " << contact.prenom  << ", Email: " << contact.email << ", Telephone: " << contact.telephone  << std::endl;
}

// fonction pour afficher la liste des contacts
void afficherlescontacts(Contact contacts[], int taille) {
    if (taille == 0) {
       std::cout << "aucun contact disponible." << std::endl;
       return ;
    }
std::cout << "liste des contacts :" << std::endl;
// parcours et affichage de chaque contact
    for (int i = 0; i < taille; i++) {
        std::cout << i + 1 << ". ";
        affichercontact(contacts[i]);
    }
    
    
}
// fonction pour afficher le menu de navigation
void affichermenu() {
    std::cout << R"(

===============================================================================================================
     __  __  ______  _   _  _    _   _____   _____   _____  _   _   _____  _____  _____          _           
 |  \/  ||  ____|| \ | || |  | | |  __ \ |  __ \ |_   _|| \ | | / ____||_   _||  __ \  /\    | |       _  
 | \  / || |__   |  \| || |  | | | |__) || |__) |  | |  |  \| || |       | |  | |__) |/  \   | |      (_) 
 | |\/| ||  __|  | . ` || |  | | |  ___/ |  _  /   | |  | . ` || |       | |  |  ___// /\ \  | |          
 | |  | || |____ | |\  || |__| | | |     | | \ \  _| |_ | |\  || |____  _| |_ | |   / ____ \ | |____   _  
 |_|  |_||______||_| \_| \____/  |_|     |_|  \_\|_____||_| \_| \_____||_____||_|  /_/    \_\|______| (_) 

===============================================================================================================
    
                   ----------------------1. AFFICHER TOUS LES CONTACTS----------------
                      ------------------------2. AJOUTER UN CONTACT-----------------
                        --------------------3.RECHERCHER UN CONTACT---------------
                         ------------------4. SUPPRIMMER UN CONTACT-------------
                           ----------------5. MODIFIER UN CONTACT-------------
                             --------------6. SAUVEGARDER CONTACT(S)-------
                               ------------7. CHARGER CONTACT(S)---------
                                  ---------------8. QUITTER------------
     )";                          
  std::cout<<"        CHOISISSEZ UNE OPTION:" ; 
                     
}

// fonction pour ajouter un contact
void ajoutercontact(Contact contacts[], int& taille, int capacite) {
    if (taille >= capacite) {
        std::cout << "le carnet est plein, impossible d ajouter un nouveau contact." << std::endl;
    return ;
    }
 Contact nouveau;
    std::cout << "Entrer le nom : ";
    std::cin >> nouveau.nom;
    std::cout << "Entrer le prenom : ";
    std::cin >> nouveau.prenom;
    std::cout << "Entrer l'email : ";
    std::cin.ignore();
    std::getline(std::cin,nouveau.email);
    std::cout << "Entrer le telephone : ";
    std::cin >> nouveau.telephone;
    
    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, nouveau.nom) == 0 && contacts[i].email.compare(nouveau.email) == 0) {
           std::cout << "Erreur : Un contact avec le meme nom et email existe deja." << std::endl;
        return;
        }
     }
contacts[taille] = nouveau;
    taille++;
    std::cout << "Contact ajoute avec succes !" << std::endl;
    
}
// fonction pour rechercher un contact parmi la liste des contacts
void recherchercontact(Contact contacts[], int taille) {
    if (taille == 0) {
        std::cout << "aucun contact disponible" << std::endl;
        return;
    }
        char recherche[20];
    std::cout << "Entrer le nom ou l'email a rechercher : ";
    std::cin >> recherche;

    bool trouve = false;
    // comparaison de l element rechercher au nom ou mail de chaque contact
    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, recherche) == 0 || contacts[i].email.compare(recherche) == 0) {
            affichercontact(contacts[i]);
            trouve = true;
        }
    }

    if (!trouve) {
        std::cout << "aucun contact correspondant trouve" << std::endl;
    
}
 

    

    
}

// fonction pour supprimer un contact de la liste de contacts
void supprimercontact(Contact contacts[], int& taille) {
    if (taille == 0) {
        std::cout << "aucun contact disponible a supprimer" << std::endl;
        return;
    }

     char nomsupprimer[20];
    std::cout << "Entrer le nom du contact a supprimer : ";
    std::cin >> nomsupprimer;

    bool trouve = false;
    // deplacement des indices et reduction de la taille du tableau si le nom du contact y est
    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, nomsupprimer) == 0) {
            for (int j = i; j < taille - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            taille--;
            trouve = true;
            std::cout << "Contact supprime avec succes !" << std::endl;
            break;
        }
    }

    if (!trouve) {
        std::cout << "aucun contact trouve avec ce nom" << std::endl;
    }

   
}

// fonction pour modifier un contact 
void modifiercontact(Contact contacts[], int taille) {
    if (taille == 0) {
       std::cout << "Aucun contact disponible a modifier." << std::endl;
        return;
    }

    char modifier[20];
    std::cout << "Entrer le nom du contact a modifier : ";
    std::cin >> modifier;

    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, modifier) == 0) {
              std::cout << "Entrer le nouveau nom : ";
            std::cin >> contacts[i].nom;
            std::cout << "Entrer le nouveau prenom : ";
            std::cin >> contacts[i].prenom;
            std::cout << "Entrer le nouveau email : ";
             std::cin.ignore();
            std::getline(std::cin,contacts[i].email);
            std::cout << "Entrer le nouveau telephone : ";
            std::cin >> contacts[i].telephone;
            std::cout << "Contact modifier avec succes !" << std::endl;
            return;
        }
    }

    std::cout << "Aucun contact trouve avec ce nom." << std::endl;
}
// fonction permettant la sauvegarde du contact dans le fichier
void sauvegarderfichier(Contact contacts[], int taille) {
    // ouverture du fichier
    std::ofstream fichier("contacts.txt");
    if (!fichier) {
        std::cout << "Erreur lors de louverture du fichier " << std::endl;
        return;
    }
// ecriture des informations du contact dans le fichier
    for (int i = 0; i < taille; i++) {
        fichier << contacts[i].nom << " "<< contacts[i].prenom << " "<< contacts[i].email << " "<< contacts[i].telephone << std::endl;
    }
    fichier.close();
    std::cout << "Contacts sauvegardes avec succes " << std::endl;
}

// fonction permettant de charger les contacts sauvegarder dans le fichier afin de les afficher
void chargerfichier(Contact contacts[], int& taille, int capacite) {
    // ouverture du fichier en mode lecture
    std::ifstream fichier("contacts.txt");
    if (!fichier) {
        std::cout << "Erreur lors de l'ouverture du fichier pour le chargement." << std::endl;
        return;
    }

    taille = 0; 
    // chargement des informations de chaque contact du fichier
    while (fichier >> contacts[taille].nom >> contacts[taille].prenom >> contacts[taille].email >> contacts[taille].telephone) {
        taille++;
        if (taille >= capacite) {
            std::cout << "Capacite maximale atteinte lors du chargement des contacts." << std::endl;
            break;
        }
    }
    fichier.close();
    std::cout << "Contacts charges avec succes !" << std::endl;
}

