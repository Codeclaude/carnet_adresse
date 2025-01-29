#ifndef FONCTION_H
#define FONCTION_H
#include<string>
struct Contact {
    char nom[20];
    char prenom[20];
    std::string email;
    char telephone[9];
};
void affichercontact(const Contact& contact);
void afficherlescontacts(Contact contacts[], int taille);
void ajoutercontact(Contact contacts[], int& taille, int capacite);
 void affichermenu();
 void supprimercontact(Contact contacts[], int& taille);
 void recherchercontact(Contact contacts[], int taille);
 void modifiercontact(Contact contacts[], int taille);
 void sauvegarderfichier(Contact contacts[], int taille);
 void chargerfichier(Contact contacts[], int& taille, int capacite);
 #endif