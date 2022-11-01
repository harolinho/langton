#include "langton.h"
#include <time.h>

void main(int argc, char* argcv[]) {
	
	ETAT* tete = createNewState(1, 175, 95);

	int delai = atoi(argcv[1]); //10
	int nombreIteration = atoi(argcv[2]); //5000
	
	createNextState(tete);
	displayState(tete->next);
	start(tete, delai, nombreIteration);
	
}
