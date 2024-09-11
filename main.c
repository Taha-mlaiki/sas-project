#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_DEPARTMENTS 5

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char dateNaissance[11];
    char departement[30];
    float noteGenerale;
} Etudiant;

Etudiant etudiants[MAX_STUDENTS];
int nombreEtudiants = 0;

const char* departements[MAX_DEPARTMENTS] = {
    "Informatique",
    "Mathematiques",
    "Physique",
    "Chimie",
    "Biologie"
};

void afficherDepartements() {
    printf("\nListe des departements:\n");
    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        printf("%d. %s\n", i + 1, departements[i]);
    }
}

void affichertouEtudiant() {
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("\n******** l'etudiant numero %d *********\n", i + 1);
        printf("l'ID => %d\n", etudiants[i].id);
        printf("le nom => %s\n", etudiants[i].nom);
        printf("le prenom => %s\n", etudiants[i].prenom);
        printf("la date de naissance => %s\n", etudiants[i].dateNaissance);
        printf("le departement => %s\n", etudiants[i].departement);
        printf("la note generale => %.2f\n", etudiants[i].noteGenerale);
    }
}

void ajouterUnEtudiant() {
    // check the maximun number of students can I create
    if (nombreEtudiants >= MAX_STUDENTS) {
        printf("Capacite maximale atteinte. Impossible d'ajouter plus d'etudiants.\n");
        return;
    }

    if (nombreEtudiants > 0) {
        printf("le dernier Id => %d \n\n", etudiants[nombreEtudiants - 1].id);
    }

    int id;
    printf("Enter le Id :");
    scanf("%d", &id);
    while (id <= nombreEtudiants) {
        printf("\nCette ID existe deja, Veuillez reessayer\n");
        printf("=> ");
        scanf("%d", &id);
    }
    etudiants[nombreEtudiants].id = id;

    printf("Entrer le nom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].nom);

    printf("Entrer le prenom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].prenom);

    printf("Entrer la date de naissance (jj/mm/aaaa): ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].dateNaissance);

    int choixDepartement;
    afficherDepartements(); // show all the deparetement here 
    printf("Choisissez le numero du departement: ");
    printf("=> ");
    scanf("%d", &choixDepartement);

    while (choixDepartement < 1 || choixDepartement > MAX_DEPARTMENTS) {
        printf("Choix invalide. Veuillez reessayer: ");
        printf("=> ");
        scanf("%d", &choixDepartement);
    }

    strcpy(etudiants[nombreEtudiants].departement, departements[choixDepartement - 1]);

    printf("Note generale: ");
    scanf("%f", &etudiants[nombreEtudiants].noteGenerale);
    nombreEtudiants++;

    printf("Etudiant ajoute avec succes!\n");
}

void modifierOuSupprimerEtudiant() {
  if(nombreEtudiants > 1){
    affichertouEtudiant();
    int id;
    printf("Entrer l'ID de l'etudiant a modifier ou supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].id == id) {
            int choice;
            printf("\n1. Modifier l'etudiant\n");
            printf("2. Supprimer l'etudiant\n");
            printf("Choisissez une option: ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Modifier le nom: ");
                scanf(" %[^\n]", etudiants[i].nom);
                printf("Modifier le prenom: ");
                scanf(" %[^\n]", etudiants[i].prenom);
                printf("Modifier la date de naissance: ");
                scanf(" %[^\n]", etudiants[i].dateNaissance);

                int choixDepartement;
                afficherDepartements();
                printf("Choisissez un nouveau departement: ");
                scanf("%d", &choixDepartement);
                //
                while (choixDepartement < 1 || choixDepartement > MAX_DEPARTMENTS) {
                      printf("Choix invalide. Veuillez reessayer: ");
                      printf("=> ");
                      scanf("%d", &choixDepartement);
                }
                strcpy(etudiants[i].departement, departements[choixDepartement - 1]);

                printf("Modifier la note generale: ");
                scanf("%f", &etudiants[i].noteGenerale);

                printf("Etudiant modifie avec succes.\n");
            } else if (choice == 2) {
                for (int j = i; j < nombreEtudiants - 1; j++) {
                    etudiants[j] = etudiants[j + 1];
                }
                nombreEtudiants--;
                printf("Etudiant supprime avec succes.\n");
            }
            return;
        }
    }
    printf("Etudiant non trouve.\n");
  }
}

void afficherEtudiant() {
    int id;
    printf("Entrer l'ID de l'etudiant a afficher: ");
    scanf("%d", &id);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].id == id) {
            printf("\nID: %d\n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

void calculerMoyenneGenerale() {
    float sommeTotale = 0;
    int totalEtudiants = 0;

    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        float sommeDepartement = 0;
        int totalDepartement = 0;

        for (int j = 0; j < nombreEtudiants; j++) {
            if (strcmp(etudiants[j].departement, departements[i]) == 0) {
                sommeDepartement += etudiants[j].noteGenerale;
                totalDepartement++;
            }
        }

        if (totalDepartement > 0) {
            printf("Moyenne pour le departement %s: %.2f\n", departements[i], sommeDepartement / totalDepartement);
        }

        sommeTotale += sommeDepartement;
        totalEtudiants += totalDepartement;
    }

    if (totalEtudiants > 0) {
        printf("Moyenne generale pour l'universite: %.2f\n", sommeTotale / totalEtudiants);
    } else {
        printf("Aucun etudiant trouve pour calculer les moyennes.\n");
    }
}

void afficherStatistiques() {
    printf("\nNombre total d'etudiants: %d\n", nombreEtudiants);

    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        int count = 0;
        for (int j = 0; j < nombreEtudiants; j++) {
            if (strcmp(etudiants[j].departement, departements[i]) == 0) {
                count++;
            }
        }
        printf("Nombre d'etudiants en %s: %d\n", departements[i], count);
    }

    printf("\nEtudiants ayant une moyenne generale superieure a 10:\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].noteGenerale > 10) {
            printf("ID: %d, Nom: %s, Note generale: %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].noteGenerale);
        }
    }
}

void menu() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Modifier ou supprimer un etudiant\n");
    printf("3. Afficher les details d'un etudiant\n");
    printf("4. Calculer la moyenne generale\n");
    printf("5. Afficher les statistiques\n");
    printf("6. Quitter\n");
    printf("Choix: ");
}

int main() {
    int choix;
    do {
        menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterUnEtudiant();
                break;
            case 2:
                modifierOuSupprimerEtudiant();
                break;
            case 3:
                afficherEtudiant();
                break;
            case 4:
                calculerMoyenneGenerale();
                break;
            case 5:
                afficherStatistiques();
                break;
            case 6:
                printf("Merci d'avoir utilise notre systeme de gestion des etudiants.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
