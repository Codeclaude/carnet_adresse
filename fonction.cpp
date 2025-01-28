#include<iostream>
#include <cstring>
#include"fonction.h"


void affichercontact(const Contact& contact) {
   std::cout<< "Nom: " << contact.nom  << ", Prenom: " << contact.prenom  << ", Email: " << contact.email << ", Telephone: " << contact.telephone  << std::endl;
}
void afficherlescontacts(Contact contacts[], int taille) {
    if (taille == 0) {
       std::cout << "aucun contact disponible." << std::endl;
    }else{
std::cout << "liste des contacts :" << std::endl;
    for (int i = 0; i < taille; i++) {
        std::cout << i + 1 << ". ";
        affichercontact(contacts[i]);
    }
    }
    
}
void affichermenu() {
    std::cout << "\nMENU PRINCIPAL :" << std::endl;
    std::cout << "1. afficher tous les contacts" << std::endl;
    std::cout << "2. ajouter un contact" << std::endl;
    std::cout << "3.rechercher un contact" << std::endl;
    std::cout << "4. supprimer un contact" << std::endl;
    std::cout << "5.quitter" << std::endl;
    
    std::cout << "choisissez une option : ";
}
void ajoutercontact(Contact contacts[], int& taille, int capacite) {
    if (taille >= capacite) {
        std::cout << "le carnet est plein, impossible d ajouter un nouveau contact." << std::endl;
    }else{
 Contact nouveau;
    std::cout << "Entrer le nom : ";
    std::cin >> nouveau.nom;
    std::cout << "Entrer le prenom : ";
    std::cin >> nouveau.prenom;
    std::cout << "Entrer l'email : ";
    std::cin >> nouveau.email;
    std::cout << "Entrer le telephone : ";
    std::cin >> nouveau.telephone;
    
    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, nouveau.nom) == 0 && strcmp(contacts[i].email, nouveau.email) == 0) {
           std::cout << "Erreur : Un contact avec le meme nom et email existe deja." << std::endl;
        }
     }
contacts[taille] = nouveau;
    taille++;
    std::cout << "Contact ajoute avec succes !" << std::endl;
    }
}

void recherchercontact(Contact contacts[], int taille) {
    if (taille == 0) {
        std::cout << "aucun contact disponible" << std::endl;
    }else{
        char recherche[20];
    std::cout << "Entrer le nom ou l'email a rechercher : ";
    std::cin >> recherche;

    bool trouve = false;
    for (int i = 0; i < taille; i++) {
        if (strcmp(contacts[i].nom, recherche) == 0 || strcmp(contacts[i].email, recherche) == 0) {
            affichercontact(contacts[i]);
            trouve = true;
        }
    }

    if (!trouve) {
        std::cout << "aucun contact correspondant trouve" << std::endl;
    
}
 }

    

    
}
void supprimercontact(Contact contacts[], int& taille) {
    if (taille == 0) {
        std::cout << "aucun contact disponible a supprimer" << std::endl;
        
    }
else{
     char nomsupprimer[20];
    std::cout << "Entrer le nom du contact a supprimer : ";
    std::cin >> nomsupprimer;

    bool trouve = false;
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
   
}