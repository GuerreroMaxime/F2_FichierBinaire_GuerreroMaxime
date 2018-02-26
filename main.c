#include <stdio.h>
#include <stdlib.h>
#define ValMax 20

typedef struct ddn{ //type struct pour ecrire la date de naissance
    int j;
    int m;
    int a;
}ddn;

typedef struct cid{ //type struct
    int Numerocarte;
    char Nom[ValMax];
    char Prenom[ValMax];
    char Sexe[1];
    ddn Naissance;
    char Ville[ValMax];
}cid;

FILE* fopen(const char* carte_id, const char* modeOuverture);   //Permet d'ouvrir le fichier
//Prototype
void ecrirefichier(FILE* pFile);
void lecturefichier(FILE* pFile);

int main()
{
    FILE* pFile = NULL; //descripteur de fichier
    char choix=' ';

    do{
        printf("Bonjour\n Veuillez choisir votre action\n 1-Entrer une nouvelle carte\n 2-Voir les cartes rentrer\n 3-Quitter\n");
        scanf("%c",&choix);
        system("cls");

        if(choix=='1')
        {
            ecrirefichier(pFile);
        }

        if(choix=='2')
        {
            lecturefichier(pFile);
        }

    }while(choix!='3');
    return 0;
}

void ecrirefichier(FILE* pFile) //procedure pour ecrire dans le fichier
{
    ddn age;
    cid carte;
    char buffer[20];

    pFile = fopen ("carte_identiter.txt" , "wb");
    if (pFile != NULL){
        printf("Saisir votre Nom \n");
        scanf("%s",carte.Nom);
        printf("Saisir votre Prenom \n");
        scanf("%s",carte.Prenom);
        printf("Saisir votre Ville \n");
        scanf("%s",carte.Ville);
        printf("Saisir le jour de votre naissance \n");
        scanf("%i",&age.j);
        printf("Saisir le mois de votre naissance \n");
        scanf("%i",&age.m);
        printf("Saisir l'annee de votre naissance \n");
        scanf("%i",&age.a);
        printf("Quel est votre sexe (f=Femme,h=Homme)\n");
        scanf("%s",carte.Sexe);
        //On ecrits les valeurs dans le fichier
       /* fprintf(pFile,"Nom : %s \n",&carte.Nom);
        fprintf(pFile,"Prenom : %s \n",&carte.Prenom);
        fprintf(pFile,"Ville : %s \n",&carte.Ville);
        fprintf(pFile,"votre date de naissance : %i / %i / %i \n",age.j,age.m,age.a);
        fprintf(pFile,"Votre sexe : %s \n",&carte.Sexe);
        fwrite (buffer , sizeof(char), sizeof(buffer), pFile);*/
        fwrite (buffer , sizeof('carte.Nom'), sizeof(buffer), pFile);
    }
    fclose (pFile);
    system("pause");

}

void lecturefichier(FILE* pFile) //Permet de lire dans le fichier
{
    int compteur=0;

    pFile = fopen ("carte_identiter.txt" , "r");
    if (pFile != NULL)
    {
        do{
            compteur=fgetc(pFile);
            printf("%c",compteur);
        }while(compteur != EOF);

    }

    fclose (pFile);
    system("pause");
}
