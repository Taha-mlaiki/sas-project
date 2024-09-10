#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;                      
    char nom[50];                
    char prenom[50];             
    char dateNaissance[11];      
    char departement[50];        
    float noteGenerale;          
} Etudiant;

Etudiant etudiants[MAX_STUDENTS];
int nombreEtudiants = 0;

void ajouterEtudiant() {
    if (nombreEtudiants >= MAX_STUDENTS) {
        printf("Capacite maximale atteinte.\n");
        return;
    }

    int method;
    printf("\n 1.Ajouter une seul etudiant\n");
    printf("\n 2.Ajouter plusieurs etudiants\n");
    printf("=>");
    scanf("%d",&method);

    if(method == 1){

    }
    
  
    printf("Entrer le Nom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].nom);
    printf("Entrer le Prenom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].prenom);
    printf("Entrer la Date de naissance (jj/mm/aaaa): ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].dateNaissance);
    printf("Departement: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].departement);
    printf("Note generale: ");
    scanf("%f", &etudiants[nombreEtudiants].noteGenerale);
    etudiants[nombreEtudiants].id = nombreEtudiants + 1;
    nombreEtudiants++;
      // Add to array
    printf("Étudiant ajouté avec succès!\n");
}
