#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_DEPARTMENTS 5

typedef struct
{
  int id;
  char nom[50];
  char prenom[50];
  char dateNaissance[11];
  char departement[30];
  float noteGenerale;
} Etudiant;

Etudiant etudiants[MAX_STUDENTS] = {
    {1234, "taha", "mlaiki", "11/22/2923", "Mathematiques", 10.22},
    {3215, "abdo", "zrwali", "21/12/2342", "Chimie", 10.22},
    {3216, "ahmed", "titwani", "21/12/2342", "Physique", 11.00},
    {3217, "sara", "kamari", "13/12/2342", "Biologie", 12.75},
    {3218, "youssef", "alaoui", "14/12/2342", "Informatique", 14.50},
    {3219, "fatima", "safri", "15/12/2342", "Mathematiques", 9.80},
    {3220, "karim", "jawhari", "16/12/2342", "Chimie", 12.10},
    {3221, "mohamed", "daoudi", "17/12/2342", "Physique", 8.90},
    {3222, "amira", "bennani", "18/12/2342", "Biologie", 13.60},
    {3223, "hanan", "mezouari", "19/12/2342", "Informatique", 15.00}
  };
int nombreEtudiants = 10;

const char departements[MAX_DEPARTMENTS][30] = {
    "Informatique",
    "Mathematiques",
    "Physique",
    "Chimie",
    "Biologie"};

void afficherDepartements()
{
  printf("\nListe des departements:\n");
  for (int i = 0; i < MAX_DEPARTMENTS; i++)
  {
    printf("%d. %s\n", i + 1, departements[i]);
  }
}

void affichertouEtudiant()
{
  for (int i = 0; i < nombreEtudiants; i++)
  {
    printf("\n******** l'etudiant numero %d *********\n", i + 1);
    printf("l'ID => %d\n", etudiants[i].id);
    printf("le nom => %s\n", etudiants[i].nom);
    printf("le prenom => %s\n", etudiants[i].prenom);
    printf("la date de naissance => %s\n", etudiants[i].dateNaissance);
    printf("le departement => %s\n", etudiants[i].departement);
    printf("la note generale => %.2f\n", etudiants[i].noteGenerale);
  }
}

void ajouterUnEtudiant()
{
  // check the maximun number of students I can createe
  if (nombreEtudiants >= MAX_STUDENTS)
  {
    printf("Capacite maximale atteinte. Impossible d'ajouter plus d'etudiants.\n");
    return;
  }

  int id;
  printf("Enter le Id :");
  scanf("%d", &id);
  for (int i = 0; i < nombreEtudiants; i++)
  {
    if (id == etudiants[i].id)
    {
      do
      {
        printf("Enter nouveau ID , car cette ID est deja existante: ");
        scanf("%d", &id);
      } while (id == etudiants[i].id);
    }
  }
  etudiants[nombreEtudiants].id = id;

  printf("Entrer le nom: ");
  scanf(" %[^\n]", etudiants[nombreEtudiants].nom);

  printf("Entrer le prenom: ");
  scanf(" %[^\n]", etudiants[nombreEtudiants].prenom);

  printf("Entrer la date de naissance (jj/mm/aaaa): ");
  scanf(" %[^\n]", etudiants[nombreEtudiants].dateNaissance);

  int choixDepartement;
  // show all the deparetement here
  afficherDepartements(); 
  printf("Choisissez le numero du departement: ");
  printf("=> ");
  scanf("%d", &choixDepartement);

  while (choixDepartement < 1 || choixDepartement > MAX_DEPARTMENTS)
  {
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

void modifierOuSupprimerEtudiant()
{

  affichertouEtudiant();
  int id;
  printf("Entrer l'ID de l'etudiant a modifier ou supprimer: ");
  scanf("%d", &id);

  for (int i = 0; i < nombreEtudiants; i++)
  {
    if (etudiants[i].id == id)
    {
      int choice;
      printf("\n1. Modifier l'etudiant\n");
      printf("2. Supprimer l'etudiant\n");
      printf("Choisissez une option: ");
      scanf("%d", &choice);

      if (choice == 1)
      {
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
        while (choixDepartement < 1 || choixDepartement > MAX_DEPARTMENTS)
        {
          printf("Choix invalide. Veuillez reessayer: ");
          printf("=> ");
          scanf("%d", &choixDepartement);
        }
        strcpy(etudiants[i].departement, departements[choixDepartement - 1]);

        printf("Modifier la note generale: ");
        scanf("%f", &etudiants[i].noteGenerale);

        printf("Etudiant modifie avec succes.\n");
      }
      else if (choice == 2)
      {
        for (int j = i; j < nombreEtudiants - 1; j++)
        {
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

void afficherDetailEtud()
{
  int id;
  printf("Entrer l'ID de l'etudiant a afficher: ");
  scanf("%d", &id);

  for (int i = 0; i < nombreEtudiants; i++)
  {
    if (etudiants[i].id == id)
    {
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

void calculerMoyenneGenerale()
{
  float sommeTotale = 0;
  int totalEtudiants = 0;

  for (int i = 0; i < MAX_DEPARTMENTS; i++)
  {
    float sommeGeneralDepartement = 0;
    int EtudiantOnDepartement = 0;

    for (int j = 0; j < nombreEtudiants; j++)
    {
      if (strcmp(etudiants[j].departement, departements[i]) == 0)
      {
        sommeGeneralDepartement += etudiants[j].noteGenerale;
        EtudiantOnDepartement++;
      }
    }

    if (EtudiantOnDepartement > 0)
    {
      printf("Moyenne pour le departement %s: %.2f\n", departements[i], sommeGeneralDepartement / EtudiantOnDepartement);
    }

    sommeTotale += sommeGeneralDepartement;
    totalEtudiants += EtudiantOnDepartement;
  }

  if (totalEtudiants > 0)
  {
    printf("Moyenne generale pour l'universite: %.2f\n", sommeTotale / totalEtudiants);
  }
  else
  {
    printf("Aucun etudiant trouve pour calculer les moyennes.\n");
  }
}

// show the student that have succssed in each departem
void afficherEtudReussiDepartement() {
    for (int i = 0; i < MAX_DEPARTMENTS; i++) {
        printf("\nEtudiants ayant reussi dans le departement %s :\n", departements[i]);
        int found = 0; 
        for (int j = 0; j < nombreEtudiants; j++) {
            if (strcmp(etudiants[j].departement, departements[i]) == 0 && etudiants[j].noteGenerale >= 10) {
                printf("ID: %d\n, Nom: %s\n, Prenom: %s\n, Note: %.2f\n", etudiants[j].id, etudiants[j].nom, etudiants[j].prenom, etudiants[j].noteGenerale);
                found++;
            }
        }
        if (!found) {
            printf("Aucun etudiant n'a reussi dans ce departement.\n");
        }
    }
}
//************************************* 

// print the top 3 students
void afficherTop3Etudiants()
{

  for (int i = 0; i < nombreEtudiants - 1; i++)
  {
    for (int j = 0; j < nombreEtudiants - i - 1; j++)
    {
      if (etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale)
      {
        Etudiant temp = etudiants[j];
        etudiants[j] = etudiants[j + 1];
        etudiants[j + 1] = temp;
      }
    }
  }

  // Print the top 3 students
  printf("\nLes 3 etudiants ayant les meilleures notes:\n");
  int limit = nombreEtudiants < 3 ? nombreEtudiants : 3; 
  for (int i = 0; i < limit; i++)
  {
    printf("\n******** Etudiant numero %d *********\n", i + 1);
    printf("ID: %d\n", etudiants[i].id);
    printf("Nom: %s\n", etudiants[i].nom);
    printf("Prenom: %s\n", etudiants[i].prenom);
    printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
    printf("Departement: %s\n", etudiants[i].departement);
    printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
  }
}
//********************

// statistics
void afficherStatistiques()
{

  if (nombreEtudiants <= 0)
  {
    printf("\nAucun etudiant disponible\n");
    return;
  }
  // 1 le nombre total d'étudiants inscrits
  printf("\nNombre total d'etudiants: %d\n", nombreEtudiants);

  // 2 le nombre d'étudiants dans chaque département
  for (int i = 0; i < MAX_DEPARTMENTS; i++)
  {
    int count = 0;
    for (int j = 0; j < nombreEtudiants; j++)
    {
      if (strcmp(etudiants[j].departement, departements[i]) == 0)
      {
        count++;
      }
    }
    if (count > 0)
    {
      printf("Nombre d'etudiants en %s: %d\n", departements[i], count);
    }
  }

  // 3 les étudiants ayant une moyenne générale supérieure à un certain seuil.
  int seuil;
  printf("\nentrer le seuil => ");
  scanf("%d", &seuil);
  printf("\nEtudiants ayant une moyenne generale superieure a %d:\n", seuil);
  for (int i = 0; i < nombreEtudiants; i++)
  {
    if (etudiants[i].noteGenerale > seuil)
    {
      printf("ID: %d, Nom: %s, Note generale: %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].noteGenerale);
    }
  }

  // 4 les 3 étudiants ayant les meilleures notess.
  afficherTop3Etudiants();

  // 5 Afficher le nombre d'étudiants ayant réussi dans chaque département (ceux ayant une note supérieure ou égale à 10/20).
  afficherEtudReussiDepartement();
}
// *******************

// Search for students 
void rechercherEtudiants()
{
  if (nombreEtudiants <= 0)
  {
    printf("\nAucun etudiant disponible\n");
    return;
  }
  int choix;
  printf("\n 1.Rechercher un etudiant par son nom\n");
  printf("2.Afficher la liste des etudiants inscrits dans un departement spe1cifique\n");
  printf("=> ");
  scanf("%d", &choix);

  while (choix != 1 && choix != 2)
  {
    printf("Choix invalid. Veuillez reessayer");
    printf("=> ");
    scanf("%d", &choix);
  }

  switch (choix)
  {
  case 1:
    char nom[50];
    printf("Entrez le nom de l'etudiant a rechercher: ");
    scanf(" %[^\n]", nom);

    int found = 0;
    for (int i = 0; i < nombreEtudiants; i++)
    {
      if (strcmp(etudiants[i].nom, nom) == 0)
      {
        printf("\nID: %d\n", etudiants[i].id);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
        printf("Departement: %s\n", etudiants[i].departement);
        printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
        found = 1;
      }
    }

    if (!found)
    {
      printf("Aucun etudiant trouve avec ce nom.\n");
    }
    break;
  case 2:
    int choix;
    afficherDepartements();
    printf("entrer un choix");
    while (choix < 1 || choix > MAX_DEPARTMENTS)
    {
      printf("Choix invalide. Veuillez reessayer: ");
      printf("=> ");
      scanf("%d", &choix);
    }
    printf("\nliste des etudiants inscrits dans cette département\n");
    for (int i = 0; i < nombreEtudiants; i++)
    {
      if (strcmp(departements[choix - 1], etudiants[i].departement) == 0)
      {
        printf("\nID: %d\n", etudiants[i].id);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
        printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
      }
    }

    break;
  }
}
// *************************

// ******** sorting **********

void sortByName()
{
  int choix;
  printf("Choisissez l'ordre de tri pour les noms:\n");
  printf("1. Trier par nom \n");
  printf("2. Trier par nom \n");
  printf("Choix: ");
  scanf("%d", &choix);

  if (choix == 1)
  {
    // ascending
    for (int i = 0; i < nombreEtudiants - 1; i++)
    {
      for (int j = 0; j < nombreEtudiants - i - 1; j++)
      {
        if (strcmp(etudiants[j].nom, etudiants[j + 1].nom) > 0)
        {
          Etudiant temp = etudiants[j];
          etudiants[j] = etudiants[j + 1];
          etudiants[j + 1] = temp;
        }
      }
    }
    printf("Les etudiants ont ete tries par nom en ordre croissant.\n");
  }
  else if (choix == 2)
  {
    // Bubble sort in descending
    for (int i = 0; i < nombreEtudiants - 1; i++)
    {
      for (int j = 0; j < nombreEtudiants - i - 1; j++)
      {
        if (strcmp(etudiants[j].nom, etudiants[j + 1].nom) < 0)
        {
          Etudiant temp = etudiants[j];
          etudiants[j] = etudiants[j + 1];
          etudiants[j + 1] = temp;
        }
      }
    }
    printf("Les etudiants ont ete tries par nom en ordre decroissant (Z-A).\n");
  }
  else
  {
    printf("Choix invalide.\n");
    return;
  }

  affichertouEtudiant();
}

void sortByPassStatus()
{

  printf("Les etudiant qui as resussite :\n");
  for(int i = 0;i<nombreEtudiants;i++ ){
    if(etudiants[i].noteGenerale >= 10){
        printf("\nID: %d\n", etudiants[i].id);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
        printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
    }
  }

  printf("\nLes etudiant qui as resussite :\n");
  for(int i = 0;i<nombreEtudiants;i++ ){
    if(etudiants[i].noteGenerale < 10){
        printf("\nID: %d\n", etudiants[i].id);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prenom: %s\n", etudiants[i].prenom);
        printf("Date de naissance: %s\n", etudiants[i].dateNaissance);
        printf("Note generale: %.2f\n", etudiants[i].noteGenerale);
    }
  }
}

void sortByNote()
{
  int choice;
  printf("Choisissez l'ordre de tri pour les notes:\n");
  printf("1. Tri croissant\n");
  printf("2. Tri decroissant \n");
  printf("Choix: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    // Bubble sort in ascending order
    for (int i = 0; i < nombreEtudiants - 1; i++)
    {
      for (int j = 0; j < nombreEtudiants - i - 1; j++)
      {
        if (etudiants[j].noteGenerale > etudiants[j + 1].noteGenerale)
        {
          Etudiant temp = etudiants[j];
          etudiants[j] = etudiants[j + 1];
          etudiants[j + 1] = temp;
        }
      }
    }
    printf("Les etudiants ont ete tries par note en ordre croissant.\n");
    break;
  case 2:
    // Bubble sort in descending order
    for (int i = 0; i < nombreEtudiants - 1; i++)
    {
      for (int j = 0; j < nombreEtudiants - i - 1; j++)
      {
        if (etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale)
        {
          Etudiant temp = etudiants[j];
          etudiants[j] = etudiants[j + 1];
          etudiants[j + 1] = temp;
        }
      }
    }
    printf("Les etudiants ont ete tries par note en ordre decroissant.\n");
    break;
  default:
    printf("Choix invalide.\n");
    return;
  }

  affichertouEtudiant();
}

void trieEtudiants()
{

  if (nombreEtudiants <= 0)
  {
    printf("\nAucun etudiant disponible\n");
    return;
  }
  int choice;
  printf("\n--- Tri des etudiants ---\n");
  printf("1. Trier par nom\n");
  printf("2. Trier par note\n");
  printf("3. Trier par statut de reussite\n");
  printf("Choisissez une option: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    sortByName();
    break;
  case 2:
    sortByNote();
    break;
  case 3:
    sortByPassStatus();
    break;
  }
}

// *************************

 // Menu 
void menu()
{
  printf("\n--- Menu Principal ---\n");
  printf("1. Ajouter un etudiant\n");
  if (nombreEtudiants > 0)
  {
    printf("2. Modifier ou supprimer un etudiant\n");
    printf("3. Afficher les details d'un etudiant\n");
    printf("4. Calculer la moyenne generale\n");
    printf("5. Afficher les statistiques\n");
    printf("6. Rechercher un etudiant\n");
    printf("7. Trier etudiants\n");
  }
  printf("8. Quitter\n");
  printf("Choix: ");
}

int main()
{
  int choix;
  do
  {
    menu();
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
      ajouterUnEtudiant();
      break;
    case 2:
      modifierOuSupprimerEtudiant();
      break;
    case 3:
      afficherDetailEtud();
      break;
    case 4:
      calculerMoyenneGenerale();
      break;
    case 5:
      afficherStatistiques();
      break;
    case 6:
      rechercherEtudiants();
      break;
    case 7:
      trieEtudiants();
      break;
    case 8:
      printf("Merci d'avoir utilise notre systeme de gestion des etudiants.\n");
      exit(0);
      break;
    default:
      printf("Choix invalide. Veuillez reessayer.\n");
    }
  } while (choix != 6);

  return 0;
}
