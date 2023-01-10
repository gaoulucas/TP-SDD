#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

//création de la structure ou du type
typedef struct Maillon{
    int donnee;
    struct Maillon *next;
}Nombre;


Nombre* creer_maillon(int value);
Nombre* creer_liste();
void affichageDeLaListe(Nombre*tete);
int longueurDeLaliste(Nombre*tete);
void InsertionTete(Nombre*tete, int a);
void InsertionQueue(Nombre*tete, int a);
void InsertionEnUnePositionP(Nombre*tete,int d,int k);
void suppressionEnTete(Nombre*tete);
void suppressionEnPositionP(Nombre*tete, int p);
void suppressionEnQueue(Nombre*tete);
int recherche(Nombre*tete,int a);
void triageCroissant(Nombre*tete);
void eliminDoublons(Nombre*tete);



#endif // NOMBRE_H_INCLUDED
