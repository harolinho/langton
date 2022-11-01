#include "langton.h"


ETAT* createFirstState(int direction, int x, int y){
	
	int i=0,j=0;
	ptETAT newEtat = calloc(1,sizeof(ETAT));
	
	for(i=0; i < DIMX; i++){
		for(j=0; j < DIMY; j++){
			newEtat->tableau[i][j] +=1;
		}
	}
	
	newEtat->fourmiX = x;
	newEtat->fourmiY = y;
	newEtat->next = NULL;
	newEtat->fourmiDirection = direction;
	return newEtat;
	
}


void afficheTableau(int tab[], int n){
	
	for(int i=0; i < n; i++){
		printf("%d\n", tab[i]);
	}

}


ETAT* createNewState(int direction, int x, int y){
	
	int i=0,j=0;
	ptETAT newEtat = calloc(1,sizeof(ETAT));
	
	for(i=0; i < DIMX; i++){
		for(j=0; j < DIMY; j++){
			newEtat->tableau[i][j] = 0;
		}
	}
	
	newEtat->fourmiX = x;
	newEtat->fourmiY = y;
	newEtat->next = NULL;
	newEtat->fourmiDirection = direction;
	return newEtat;
}


void createNextState(ETAT* tete){
	
	int i=0,j=0;
	ptETAT old = tete;
	ptETAT new = calloc(1,sizeof(ETAT));
	new = createNewState(0,0,0);
	
	while(old->next != NULL){
		old = old->next;
	}
	
	old->next = new;
	
	for(i=0; i < DIMY; i++){
		for(j=0; j < DIMX; j++){
			new->tableau[i][j] = old->tableau[i][j];
		}
	}
	
	new->tableau[old->fourmiX][old->fourmiY] = 1 - new->tableau[old->fourmiX][old->fourmiY];
	
	
	switch(old->tableau[old->fourmiX][old->fourmiY]){
		
		case 0 :
			new->fourmiDirection = old->fourmiDirection +1;
			break;
		case 1 :
			new->fourmiDirection = old->fourmiDirection -1;
			break;
			
	}
	
	
	if(new->fourmiDirection == -1){
		new->fourmiDirection = 4;
	}
	
	if(new->fourmiDirection == 4){
		new->fourmiDirection = 0;
	}
	
	switch(new->fourmiDirection){
		
		case 0 :
				new->fourmiX = old->fourmiX -1;
				new->fourmiY = old->fourmiY;
			break;
		case 1 :
			new->fourmiX = old->fourmiX;
			new->fourmiY = old->fourmiY + 1;
			//new->tableau[old->fourmiX -1][old->fourmiY] = 1 - new->tableau[old->fourmiX][old->fourmiY];
			break;
		case 2 :
			new->fourmiX = old->fourmiX + 1;
			new->fourmiY = old->fourmiY;
			break;
		case 3 :
			new->fourmiX = old->fourmiX;
			new->fourmiY = old->fourmiY -1;
			break;
	}
	
	//new->tableau[new->fourmiX][new->fourmiY] = 1 - old->tableau[old->fourmiX][old->fourmiY];
	
}


void displayState(ETAT * e){
	
	int i=0, j=0;
	
	for(i=0; i < DIMY; i++){
		for(j=0; j < DIMX; j++){
			if(i == e->fourmiX && j == e->fourmiY){
				switch(e->fourmiDirection){
					case 0 :
						printf("^");
						break;
					case 1 :
						printf(">");
						break;
					case 2 :
						printf("v");
						break;
					case 3 :
						printf("<");
						break;
				}
			}else{
				printf("%c",(char)(e->tableau[i][j]<1?'#':'_'));
			}
			//printf("\t");
		}
		printf("\n");
	}
	printf("\n*********************************\n");
}


void start(ETAT *tete, int time, int nbreIteration){
	
	int i=0, decomp = nbreIteration;
	ETAT *temp = tete;
	
	do{
		printf("\e[1;1H\e[2J");
		displayState(temp);
		createNextState(temp);
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		decomp--;
		usleep(time*1000);
		
	}while(decomp!=0);
	

}
