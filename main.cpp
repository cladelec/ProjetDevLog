#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Grille.h"

int main () {
	printf("Hello world \n");
	
	Grille laGrille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille.to_string()<<endl;
	
	laGrille.run();
	cout<<laGrille.to_string()<<endl;


	//Grille laPititeGrille(3,3,2,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	//cout<<laPititeGrille.to_string()<<endl;
	cout<<laGrille.affichage()<<endl;

	return 0;
}
