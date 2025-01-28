<<<<<<< HEAD
#include<iostream>
#include <cstring>
#include"fonction.h"


void affichercontact(const Contact& contact) {
   std::cout<< "Nom: " << contact.nom  << ", Prenom: " << contact.prenom  << ", Email: " << contact.email << ", Telephone: " << contact.telephone  << std::endl;
}
void afficherlescontacts(Contact contacts[], int taille) {
    if (taille == 0) {
       std::cout << "aucun contact disponible." << std::endl;
    }
    std::cout << "liste des contacts :" << std::endl;
    for (int i = 0; i < taille; i++) {
        std::cout << i + 1 << ". ";
        affichercontact(contacts[i]);
    }
}
void affichermenu() {
    std::cout << "\nMENU PRINCIPAL :" << std::endl;
    std::cout << "1. afficher tous les contacts" << std::endl;
    std::cout << "2. ajouter un contact" << std::endl;
    std::cout << "3.quitter" << std::endl;
    std::cout << "choisissez une option : ";
}
void ajoutercontact(Contact contacts[], int& taille, int capacite) {
    if (taille >= capacite) {
        std::cout << "le carnet est plein, impossible d ajouter un nouveau contact." << std::endl;
    }

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
=======
#include<iostream>
#include"fonction.h"


void affichercontact(const Contact& contact) {
   std::cout<< "Nom: " << contact.nom  << ", Prenom: " << contact.prenom  << ", Email: " << contact.email << ", Telephone: " << contact.telephone  << std::endl;
}
void afficherlescontacts(Contact contacts[], int taille) {
    if (taille == 0) {
       std::cout << "aucun contact disponible." << std::endl;
        
    }
    std::cout << "liste des contacts :" << std::endl;
    for (int i = 0; i < taille; i++) {
        std::cout << i + 1 << ". ";
        affichercontact(contacts[i]);
    }
}
void affichermenu() {
    std::cout << "\nMENU PRINCIPAL :" << std::endl;
    std::cout << "1. afficher tous les contacts" << std::endl;
    std::cout << "2. ajouter un contact" << std::endl;
    std::cout << "3.quitter" << std::endl;
    std::cout << "choisissez une option : ";
}
void ajoutercontact(Contact contacts[], int& taille, int capacite) {
    if (taille >= capacite) {
        std::cout << "le carnet est plein, impossible d ajouter un nouveau contact." << std::endl;
    
    }

    Contact nouveau;
    std::cout << "Entrer le nom : ";
    std::cin >> nouveau.nom;
    std::cout << "Entrer le prenom : ";
    std::cin >> nouveau.prenom;
    std::cout << "Entrer l'email : ";
    std::cin >> nouveau.email;
    std::cout << "Entrer le telephone : ";
    std::cin >> nouveau.telephone;

    contacts[taille] = nouveau;
    taille++;
    std::cout << "Contact ajoute avec succes !" << std::endl;
>>>>>>> 6f3d766218c86fd5bc42d176e86ecd2c3b0881e8
}