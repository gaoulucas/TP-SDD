#include "Nombre.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//cr?ation d'un maillon
Nombre* creer_maillon(int value)
{
    Nombre*maillon = malloc(sizeof(Nombre));
    maillon->donnee=value;
    maillon->next=NULL;
    return maillon;
}
//cr?ation d'une liste de nombre
Nombre* creer_liste()
{
    int taille;
    int i,nbre;
    Nombre*tete;
    Nombre*Liste=NULL;
    printf("veuillez entrer la taille de la liste :\n  Taille = ");
    scanf("%d",&taille);
    for(i=0; i<taille; i++)
    {
        printf("veuillez entrer un nombre: \n");
        scanf("%d",&nbre);
        tete=creer_maillon(nbre);
        tete->next=Liste;
        Liste=tete;
    }
    return Liste;
}
void affichageDeLaListe( Nombre* tete)
{
    Nombre* Now = tete;
    if(Now==NULL)
    {
        printf("la liste est vide\n");
    }else{
        while(Now!=NULL)
        {
            printf("%5d\t",Now->donnee);
            Now = Now->next;
        }
    }
    printf("\n");
}
int longueurDeLaliste(Nombre*tete)
{
    int longueur = 0;
    Nombre* Now=tete;
    while(Now!=NULL)
    {
        longueur++;
        Now=Now->next;
    }
    return longueur;
}

void InsertionTete(Nombre*tete,int a)          //Nombre**tete pour d?signer le contenu de la tete
{
    Nombre*Nouveau=creer_maillon(a);
    Nouveau->next= tete;     // le nouveau noeud pointe vers l'?lement de la tete
    tete = Nouveau;
    affichageDeLaListe(tete);
}
void InsertionQueue(Nombre*tete, int a)
{
    Nombre*Nouveau=creer_maillon(a);
    Nombre*Now=tete;

    while(Now->next!=NULL)
    {
        Now=Now->next;
    }
    Now->next=Nouveau;
    Nouveau->next=NULL;
    affichageDeLaListe(tete);
}
void InsertionEnUnePositionP(Nombre*tete,int d,int k)
{
    Nombre*Ancien=NULL;
    Nombre*Nouveau=creer_maillon(d);
    Nombre*Now=tete;
    int i=1;
    if(k==1)
    {
        Nouveau->next=Now;
        tete=Nouveau;
    }
    else
    {
        while((Now!=NULL)&&(i<(k-1)))
        {
            i++;
            Ancien=Now;
            Now=Now->next;
        }
        Ancien->next=Nouveau;
        Nouveau->next=Now;
    }

   affichageDeLaListe(tete);
}
void suppressionEnTete(Nombre*tete)    //suppression du contenu du pointeur tete
{
    Nombre*Now=tete;
    tete = Now->next;
    free(Now);
    affichageDeLaListe(tete);
}
void suppressionEnPositionP(Nombre*tete,int p)
{
    Nombre*AncienNombre;
    Nombre*Now=tete;
    int i;

    if(p<=0)
    {
        printf("Suppression en tete\n");
        return suppressionEnTete(tete);
    }
    for (i=1; i<(p-1) && Now!=NULL; i++)
    {
        Now=Now->next;
    }
    if(Now==NULL)
    {
        printf("suppression en queue\n");
        return suppressionEnQueue(tete);
    }

    AncienNombre=Now->next;        //l'?l?ment point? par le nouveau noeud est l'?lement point? par le noeud courant ou noeud actuel
    Now->next= Now->next->next;     //saut
    free(AncienNombre);             //l'?lement point? par le courant ou actuel est le nouveau noeud
    affichageDeLaListe(tete);
}
void suppressionEnQueue(Nombre*tete)
{

    Nombre * Now=tete;
    Now=malloc(sizeof(Nombre));
    if(tete!=NULL)
    {
        if(tete->next==NULL)
        {
            free(tete);
            tete==NULL;
        }
        else{
            Now=tete;
            while(Now->next->next!=NULL)
            {
                Now=Now->next;
            }
            free(Now->next);
            Now->next=NULL;

        }
    }
    printf("Op?ration r?ussie!!\n");
    printf("Affichage de la nouvelle liste: ");
    affichageDeLaListe(tete);

}
int recherche(Nombre*tete, int a)
{
    Nombre*Now=tete;
    int i=0;              //affiche "0" si on a pas trouver la valeur et affiche "1" si la valeur n'est pas trouv?

    while(Now!=NULL && !i)
    {
        if(Now->donnee==a)
            i=1;
        //avancer dans la liste
        Now=Now->next;
    }
    return i;
}
int trieCroissant(Nombre*tete)
{
    Nombre*Now;         //pointeur qui parcours la liste
    Nombre*Apres;      //pointeur qui parcours aussi la liste mais en fonction de Now
    int Trie;
    if(tete!=NULL)
    {
        for(Now=tete; Now->next!=NULL; Now=Now->next)
        {
            for(Apres=Now->next; Apres!=NULL; Apres=Apres->next)
            {
                if(Apres->donnee < Now->donnee)
                {
                    Trie=Apres->donnee;
                    Apres->donnee=Now->donnee;
                    Now->donnee=Trie;
                }
            }
        }
    }
    return 0;
}
void eliminDoublons(Nombre*tete)
{

    Nombre*Now=tete;
    Nombre*Ancien;

    if(tete==NULL)
        printf("liste vide donc pas de doublons!\n ");
    while(Now->next!=NULL)                          //tans que le pointeur suivant le pointeur parcours existe
    {
        if(Now->donnee==Now->next->donnee)      //si la donn?e du pointeur parcours=donn?e du pointeur suivant du parcours
        {
            Ancien=Now->next;               //initialisation de Ancien ? Now->next (Ancien prend la valeur de l'?l?ment suivant le pointeur de parcours
            Now->next= Ancien->next;        //d?calage du pointeur suivant du pointeur parcours
            free(Ancien);                   //lib?ration de l'?l?mentt contenant le doublon
        }
        else
        {
            Now=Now->next;
        }
    }
    affichageDeLaListe(tete);
}
void ajoutAuBonEndroit(Nombre*tete)
{
    int donnee=0;
    Nombre*Newelement=creer_maillon(donnee);
    Nombre*Now=tete, *Next;

    if(trieCroissant(tete)!=0)
    {
        printf("\nListe non tri?e ! Veuillez choisir l'option '11-' pour trier la liste\n");
    }
    else
    {
         printf("veuillez entrer l'?l?ment ? ajouter dans la liste: \n ?l?ment =");
        scanf("%d",&donnee);
          while(Now->next!=NULL)
        {
            Next=Now;
            Now=Now->next;
            if(Next->donnee<=Newelement->donnee && Now->donnee>Newelement->donnee)
            {
                Next->next=Newelement;
                Newelement->next=Now;
            }
        }
        if(Now->next == NULL)
        {
            Now->next=Newelement;
            Newelement=NULL;
        }
        printf("Op?ration r?ussi!!!");
        affichageDeLaListe(tete);
    }

}
