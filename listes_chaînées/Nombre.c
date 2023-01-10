#include "Nombre.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//création d'un maillon
Nombre* creer_maillon(int value)
{
    Nombre*maillon = malloc(sizeof(Nombre));
    maillon->donnee=value;
    maillon->next=NULL;
    return maillon;
}
//création d'une liste de nombre
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

void InsertionTete(Nombre* tete,int a)          //Nombre**tete pour désigner le contenu de la tete
{
    Nombre*Nouveau=creer_maillon(a);
    Nouveau->next= tete;     // le nouveau noeud pointe vers l'élement de la tete
    tete=Nouveau;           //le contenu de la tete prend le nouvelle valeur du nouveau
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
    int i=0;
    if(k==0)
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

    AncienNombre=Now->next;        //l'élément pointé par le nouveau noeud est l'élement pointé par le noeud courant ou noeud actuel
    Now->next= Now->next->next;     //saut
    free(AncienNombre);             //l'élement pointé par le courant ou actuel est le nouveau noeud
    affichageDeLaListe(tete);
}
void suppressionEnQueue(Nombre*tete)
{
    Nombre*AncienNombre;
    Nombre*Now=tete;
    Nombre*nbreSupp=NULL;

    while(Now->next!=NULL)
    {
        Now=Now->next;
    }
    nbreSupp=Now;
    AncienNombre->next=nbreSupp->next;
    free(nbreSupp);
    affichageDeLaListe(tete);
}
int recherche(Nombre*tete, int a)
{
    Nombre*Now=tete;
    int i=0;              //affiche "0" si on a pas trouver la valeur et affiche "1" si la valeur n'est pas trouvé

    while(Now!=NULL && !i)
    {
        if(Now->donnee==a)
            i=1;
        //avancer dans la liste
        Now=Now->next;
    }
    return i;
}
void triageCroissant(Nombre*tete)
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
    affichageDeLaListe(tete);
}
void eliminDoublons(Nombre*tete)
{

    Nombre*Now=tete;
    Nombre*Ancien;

    if(tete==NULL)
        printf("liste vide donc pas de doublons!\n ");
    while(Now->next!=NULL)                          //tans que le pointeur suivant le pointeur parcours existe
    {
        if(Now->donnee==Now->next->donnee)      //si la donnée du pointeur parcours=donnée du pointeur suivant du parcours
        {
            Ancien=Now->next;               //initialisation de Ancien à Now->next (Ancien prend la valeur de l'élément suivant le pointeur de parcours
            Now->next= Ancien->next;        //décalage du pointeur suivant du pointeur parcours
            free(Ancien);                   //libération de l'élémentt contenant le doublon
        }
        else
        {
            Now=Now->next;
        }
    }
    affichageDeLaListe(tete);
}
ajoutAuBonEndroit()
{

}

