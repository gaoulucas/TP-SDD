#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#define NOMINAX
#include "Nombre.h"


int main()
{
    int choix;
    char reponse,confirm;
    int p;
    int longueur,t;
    int nombre,b,d,k ,l;
    Nombre*Liste=NULL;
    SetConsoleOutputCP(1252);
    Color(5,0);
    printf("\t\t\t\t*****************************\t\t\n");
    printf("\t\t\t\t*        BIENVENUE!         *\t\t\n");
    printf("\t\t\t\t*****************************\t\t\n");
    Color(15,0);
    printf("\t\t**PROGRAMME DE MANIPULATION SUR LES LISTES CHAINEES**\n");
    do{
        Color(5,0);
        printf("\n\t\t\t\t\t**Menu**\n");
        Color(15,0);
        printf("\t\t\t1- Créer une liste\n");
        printf("\t\t\t2- Afficher de la liste\n");
        printf("\t\t\t3- Longueur de la liste\n");
        printf("\t\t\t-- Ajouter un nombre dans la liste\n");
        printf("\t\t\t\t4- En tête de liste\n ");
        printf("\t\t\t\t5- En fin de liste\n");
        printf("\t\t\t\t6- à une position p donnée\n");
        printf("\t\t\t-- Supprimer un nombre de la liste\n");
        printf("\t\t\t\t7- En tête de liste\n ");
        printf("\t\t\t\t8- En fin de liste\n");
        printf("\t\t\t\t9- à une position p donnée\n");
        printf("\t\t\t10- Rechercher un nombre dans la liste\n");
        printf("\t\t\t11- Trier une liste de nombre dans l'ordre croissant\n");
        printf("\t\t\t12- Ajouter un nombre au bon endroit dans une liste triée\n");
        printf("\t\t\t13- Eliminer des doublons\n");
        printf("\t\t\t14- Quitter\n");
        printf("\t\t\tEntrer votre choix\n");
        printf("\t\t\tchoix\t:\t");
        scanf("%d",&choix);
        fflush(stdin);

        switch(choix)
        {
            case 1:
                Liste= creer_liste();
                system("PAUSE");
             break;
        case 2:
                 affichageDeLaListe(Liste);
            break;
        case 3:
                longueur=longueurDeLaliste(Liste);
                printf(" la longueur est: %d \n",longueur);
            break;
        case 4:
            if(Liste!=NULL)
            {
                 printf("veuillez entrer le nombre à ajouter\n");
                scanf("%d",&nombre);
                InsertionTete(Liste ,nombre );
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;

        case 5:
            if(Liste!=NULL)
            {
                printf("veuillez entrer le nombre à ajouter\n");
                scanf("%d",&b);
                InsertionQueue(Liste,b );
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 6:
            if(Liste!=NULL)
            {
                printf("veuillez entrer l'élément à ajouter: \n");
                scanf("%d",&d);
                printf("Entrer la position de l'élément: \n");
                scanf("%d",&k);
                InsertionEnUnePositionP(Liste,d,k);
            }
            else{
                 printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 7:
            if(Liste!=NULL)
            {
                 suppressionEnTete(Liste);
            }
            else{
                 printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 8:
            if(Liste!=NULL)
            {
                 suppressionEnQueue(Liste);
            }
            else{
                 printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 9:
            if(Liste!=NULL)
            {
                 printf("veuillez entrer la position de l'élément à effacer\n");
                scanf("%d",&p);
                printf("la nouvelle liste est: ");
                suppressionEnPositionP(Liste, p);
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 10:
            if(Liste!=NULL)
            {
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
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 11:
            if(Liste!=NULL)
            {
                 trieCroissant(Liste);
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 12:
            if(Liste!=NULL)
            {
                ajoutAuBonEndroit(Liste);
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 13:
            if(Liste!=NULL)
            {
                eliminDoublons(Liste);
            }
            else{
                printf("Créer d'abord la liste!!!\n");
            }
            break;
        case 14:
            printf("Voulez-vous vraiment sortir? ('O' pour Oui et 'N' pour Non)");
            scanf("%c",&confirm);
            if(confirm=='O')
                exit(0);
            else
                fflush(stdin);
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
