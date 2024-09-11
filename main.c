#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_DEPARTMENTS 5

// Structure to represent a student
typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char dateNaissance[11];  // Format: jj/mm/aaaa
    char departement[50];
    float noteGenerale;
} Etudiant;

// Array to store students and count of students
Etudiant etudiants[MAX_STUDENTS];
int nombreEtudiants = 0;
int nextId = 1;  // Variable to assign unique IDs

// List of available departments
const char* departements[MAX_DEPARTMENTS] = {
    "Informatique",
    "Mathematiques",
    "Physique",
    "Chimie",
    "Biologie"
};

// Function to display the list of departments
void afficherDepartements() {
    printf("\nListe des départements:\n");
    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        printf("%d. %s\n", i + 1, departements[i]);
    }
}

// Function to add a single student
void ajouterUnEtudiant() {
    if (nombreEtudiants >= MAX_STUDENTS) {
        printf("Capacité maximale atteinte. Impossible d'ajouter plus d'étudiants.\n");
        return;
    }

    printf("Entrer le nom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].nom);

    printf("Entrer le prénom: ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].prenom);

    printf("Entrer la date de naissance (jj/mm/aaaa): ");
    scanf(" %[^\n]", etudiants[nombreEtudiants].dateNaissance);

    // Choose department
    int choixDepartement;
    afficherDepartements();
    printf("Choisissez le numéro du département: ");
    scanf("%d", &choixDepartement);

    // Validate the department selection
    while (choixDepartement < 1 || choixDepartement > MAX_DEPARTMENTS) {
        printf("Choix invalide. Veuillez réessayer: ");
        scanf("%d", &choixDepartement);
    }

    // Assign the selected department to the student
    strcpy(etudiants[nombreEtudiants].departement, departements[choixDepartement - 1]);

    printf("Note générale: ");
    scanf("%f", &etudiants[nombreEtudiants].noteGenerale);

    // Assign a unique ID to the student
    etudiants[nombreEtudiants].id = nextId;
    nextId++;  // Increment the ID for the next student
    nombreEtudiants++;

    printf("Étudiant ajouté avec succès! ID: %d\n", etudiants[nombreEtudiants - 1].id);
}

// Function to modify or delete a student
void modifierOuSupprimerEtudiant() {
    int id;
    printf("Entrer l'ID de l'étudiant à modifier ou supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].id == id) {
            int choice;
            printf("\n1. Modifier l'étudiant\n");
            printf("2. Supprimer l'étudiant\n");
            printf("Choisissez une option: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Modify student
                printf("Modifier le nom: ");
                scanf(" %[^\n]", etudiants[i].nom);
                printf("Modifier le prénom: ");
                scanf(" %[^\n]", etudiants[i].prenom);
                printf("Modifier la date de naissance: ");
                scanf(" %[^\n]", etudiants[i].dateNaissance);

                int choixDepartement;
                afficherDepartements();
                printf("Choisissez un nouveau département: ");
                scanf("%d", &choixDepartement);
                strcpy(etudiants[i].departement, departements[choixDepartement - 1]);

                printf("Modifier la note générale: ");
                scanf("%f", &etudiants[i].noteGenerale);

                printf("Étudiant modifié avec succès.\n");
            } else if (choice == 2) {
                // Delete student
                for (int j = i; j < nombreEtudiants - 1; j++) {
                    etudiants[j] = etudiants[j + 1];
                }
                nombreEtudiants--;
                printf("Étudiant supprimé avec succès.\n");
            }
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

// Function to display a student's details
void afficherEtudiant() {
    int id;
    printf("Entrer l'ID de l'étudiant à afficher: ");
    scanf("%d", &id);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].id == id) {
            printf("\nID: %d\n", etudiants[i].id);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prénom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
            printf("Département: %s\n", etudiants[i].departement);
            printf("Note générale: %.2f\n", etudiants[i].noteGenerale);
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

// Function to calculate average grades by department and overall
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
            printf("Moyenne pour le département %s: %.2f\n", departements[i], sommeDepartement / totalDepartement);
        }

        sommeTotale += sommeDepartement;
        totalEtudiants += totalDepartement;
    }

    if (totalEtudiants > 0) {
        printf("Moyenne générale pour l'université: %.2f\n", sommeTotale / totalEtudiants);
    } else {
        printf("Aucun étudiant trouvé pour calculer les moyennes.\n");
    }
}

// Function to display statistics
void afficherStatistiques() {
    printf("\nNombre total d'étudiants: %d\n", nombreEtudiants);

    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        int count = 0;
        for (int j = 0; j < nombreEtudiants; j++) {
            if (strcmp(etudiants[j].departement, departements[i]) == 0) {
                count++;
            }
        }
        printf("Nombre d'étudiants en %s: %d\n", departements[i], count);
    }

    printf("\nÉtudiants ayant une moyenne générale supérieure à 10:\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].noteGenerale > 10) {
            printf("ID: %d, Nom: %s, Note générale: %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].noteGenerale);
        }
    }
}

// Menu function
void menu() {
    int choix;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Modifier ou supprimer un étudiant\n");
        printf("3. Afficher les détails d'un étudiant\n");
        printf("4. Calculer la moyenne générale\n");
        printf("5. Afficher les statistiques\n");
        printf("6. Quitter\n");
        printf("Choix: ");
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
                printf("Merci d'avoir utilisé l'application!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);
}

// Main function
int main() {
    menu();
    return 0;
}
