// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "Grille.h"

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main () {
	printf("Hello world \n");
	
	/*Grille* laGrille = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	for(int i=0;i<5;++i){
		laGrille->run();
	}
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	delete laGrille;
	*/

	/*Grille* laPititeGrille = new Grille(3,3,2,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laPititeGrille->to_string()<<endl;
	cout<<laPititeGrille->affichage()<<endl; 
	float proba=(rand()%100+1); 
	std::cout << proba << std::endl; 
	
	int i;
	for(i=0;i<100;++i) { 
		laPititeGrille->run();
		cout<<laPititeGrille->to_string()<<endl;
		cout<<laPititeGrille->affichage()<<endl;
	}
	cout<<laPititeGrille->to_string()<<endl;
	
	for(int i=0;i<3;++i) {
		laPititeGrille->run();
		cout<<laPititeGrille->to_string()<<endl;
	}
	cout<<laPititeGrille->affichage()<<endl;
	
	delete laPititeGrille;*/
	
	Grille* test = new Grille(10,10,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	
	/*cout<<test->to_string()<<endl;
	cout<<test->affichage()<<endl;
	
	for(int i=0;i<10000;++i) { 
		test->run();
	}
	cout<<test->to_string()<<endl;
	cout<<test->affichage()<<endl;*/
	
	delete test;
	
	Grille* laGrille = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	remove("stats.txt");
	for(int i=0;i<5000;++i){
		laGrille->run();
		laGrille->stats("stats.txt");
	}
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	delete laGrille;
	
	
	return 0;
}
