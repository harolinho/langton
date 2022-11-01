#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // utile plus tard : fonction usleep();

#define TAILLE 46
extern int fibonacci[TAILLE];

#define DIMX 200
#define DIMY 200

struct etat{
	
	int tableau[DIMX][DIMY];
	int fourmiX;
	int fourmiY;
	int fourmiDirection; // 0 : Nord, 1 : Est, 2: Sud, 3 : Ouest
	struct etat* next; 
	
}; 

struct ListeEtat{
	
	struct etat* premier;

};

typedef struct etat ETAT;
typedef ETAT* ptETAT;
typedef struct ListeEtat LISTETAT;

ptETAT createFirstState(int x, int y, int direction);
void displayState(ETAT * e);
void createNextState(ETAT * tete);
ETAT* createNewState(int direction, int x, int y);
ETAT* createFirstState(int direction, int x, int y);
void start(ETAT *tableau, int duree, int nbreIteration);
