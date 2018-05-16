// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Grille.h"

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main () {
	printf("Hello world \n");
	
	Grille* laGrille = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	//laGrille.run();
	//cout<<laGrille->to_string()<<endl;

	delete laGrille; //destructeur gère pas ouf nb instances si 2 grilles....

	Grille laPititeGrille(4,4,2,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laPititeGrille.to_string()<<endl;
	cout<<laPititeGrille.affichage()<<endl;

	return 0;
}
