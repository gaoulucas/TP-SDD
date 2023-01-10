#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "Nombre.h"


int main()
{
    int choix;
    char reponse;
    int p;
    int longueur,t;
    int nombre,b,d,k ,l;
    Nombre*Liste=NULL;


    printf("\t\t\t\t**PROGRAMME DE MANIPULATION SUR LES LISTES CHAINEES**\n");
    do{
        printf("\n\t\t**Menu**\n");
        printf("1- créer une liste\n");
        printf("2- Affichage de la liste\n");
        printf("3- longueur de la liste\n");
        printf("-- Ajout d'un nombre dans la liste\n");
        printf("\t4- En tête de liste\n ");
        printf("\t5- En fin de liste\n");
        printf("\t6- à une position p donnée\n");
        printf("-- suppression d'un nombre de la liste\n");
        printf("\t7- En tête de liste\n ");
        printf("\t8- En fin de liste\n");
        printf("\t9- à une position p donnée\n");
        printf("10- Recherche d'un nombre dans la liste\n");
        printf("11- triage d'une liste de nombre dans l'ordre croissant\n");
        printf("12- Ajout d'un nombre au bon endroit dans une liste triée\n");
        printf("13- Elimination des doublons\n");
        scanf("%d",&choix);
        fflush(stdin);

        switch(choix)
        {
        case 1:
         Liste= creer_liste();
             break;
        case 2:
            affichageDeLaListe(Liste);
            break;
        case 3:
            longueur=longueurDeLaliste(Liste);
            printf(" la longueur est: %d \n",longueur);
            break;
        case 4:
            printf("veuillez entrer le nombre à ajouter\n");
            scanf("%d",&nombre);
            InsertionTete(Liste ,nombre );
            break;

        case 5:
            printf("veuillez entrer le nombre à ajouter\n");
            scanf("%d",&b);
            InsertionQueue(Liste,b );
            break;
        case 6:
            printf("veuillez entrer l'élément à ajouter: \n");
            scanf("%d",&d);
            printf("Entrer la position de l'élément: \n");
            scanf("%d",&k);
            InsertionEnUnePositionP(Liste,d,k);
            break;
        case 7:
            suppressionEnTete(Liste);
            break;
        case 8:
            suppressionEnQueue(Liste);
            break;
        case 9:
            printf("veuillez entrer la position de l'élément à effacer\n");
            scanf("%d",&p);
            printf("la nouvelle liste est: ");
            suppressionEnPositionP(Liste, p);
            break;
        case 10:
            printf("veuillez entrer le nombre recherché :\t");
            scanf("%d",&t);
            l=recherche(Liste, t);
            if(l==1)
            {
                printf("le nombre %d retrouvé\n",t);
            }
            else
            {
                 printf("le nombre %d introuvable dans la liste\n",t);
            }
            break;
        case 11:
            triageCroissant(Liste);
            break;
        case 12:

            break;
        case 13:
            eliminDoublons(Liste);
            break;
        default:
            printf("Mauvaix choix!!!\n");
            break;
        }
            fflush(stdin);

        printf("Continuer?(O/N)");
        scanf("%c",&reponse);
        fflush(stdin);
    }while(reponse=='O');

    return 0;
}
