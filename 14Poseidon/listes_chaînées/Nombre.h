#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

//cr?ation de la structure ou du type
typedef struct Maillon{
    int donnee;
    struct Maillon *next;
}Nombre;


void Color(int couleurDuTexte,int couleurDeFond);
Nombre* creer_maillon(int value);
Nombre* creer_liste();
void affichageDeLaListe(Nombre*tete);
int longueurDeLaliste(Nombre*tete);
void InsertionTete(Nombre*tete, int a);
void InsertionQueue(Nombre*tete, int a);
void InsertionEnUnePositionP(Nombre*tete,int d,int k);
void suppressionEnTete(Nombre*tete);
void suppressionEnTete(Nombre*tete);
void suppressionEnPositionP(Nombre*tete, int p);
void suppressionEnQueue(Nombre*tete);
int recherche(Nombre*tete,int a);
int trieCroissant(Nombre*tete);
void eliminDoublons(Nombre*tete);
void ajoutAuBonEndroit(Nombre*tete);



#endif // NOMBRE_H_INCLUDED
