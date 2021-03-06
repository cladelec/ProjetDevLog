// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "Grille.h"

#include <time.h>

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main () {
	printf("Hello world \n");
	srand(time(NULL)); //permet d'éviter d'avoir toujours les mêmes aléatoires
	
	
// ===========================================================================
//                                   TESTS
// ===========================================================================
	
/*
	//test du constructeur
	Grille* laGrille = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
  //test de la méthode run()
	for(int i=0;i<5;++i){
		laGrille->run();
	}
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
  //test du destructeur
	delete laGrille;
	
	Grille* laPititeGrille = new Grille(3,3,2,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laPititeGrille->to_string()<<endl;
	cout<<laPititeGrille->affichage()<<endl; 

	//test random
	float proba=(rand()%100+1); 
	std::cout << proba << std::endl;
*/ 
	
/*
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
	
	delete laPititeGrille;
	
	Grille* test = new Grille(10,10,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	
	cout<<test->to_string()<<endl;
	cout<<test->affichage()<<endl;
	
	for(int i=0;i<10000;++i) { 
		test->run();
	}
	cout<<test->to_string()<<endl;
	cout<<test->affichage()<<endl;
	
	delete test; 
	*/
	
	/*
	Grille* laGrille1 = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	remove("stats.txt");
	for(int i=0;i<5000;++i){
		laGrille->run();
		laGrille->stats("stats.txt");
		if(i%3==0){
			laGrille->lavage();
		}
	}
	
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	delete laGrille;
	*/
	
	// ===========================================================================
	//                          	SIMULATIONS
	// ===========================================================================
	
 	//test pour différentes valeurs de T et Ainit
	int T=6; //temps entre deux lavages
	
	Grille* Grille1 = new Grille(32,32,15.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille1->run();
		if(i%T==0){
			Grille1->lavage();
		}
	}	
	
	cout<<"Grille 1 : "<<endl;
	cout<<Grille1->to_string()<<endl;
	delete Grille1;
	
	Grille* Grille2 = new Grille(32,32,30.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille2->run();
		if(i%T==0){
			Grille2->lavage();
		}
	}
	
	cout<<"Grille 2 : "<<endl;
	cout<<Grille2->to_string()<<endl;
	
	delete Grille2;	
	
	Grille* Grille3 = new Grille(32,32,45.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille3->run();
		if(i%T==0){
			Grille3->lavage();
		}
	}	
	
	cout<<"Grille 3 : "<<endl;
	cout<<Grille3->to_string()<<endl;
	
	delete Grille3;
	
	
/*
	Grille * Grille1 = new Grille(32,32,30.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	remove("stats1.txt");
	for(int i=0;i<5000;++i){
		Grille1->run();
		Grille1->stats("stats1.txt");
		if(i%3==0){
			Grille1->lavage();
		}
	}	
	delete Grille1; 
	
	
	Grille * Grille2 = new Grille(32,32,45.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	remove("stats2.txt");
	for(int i=0;i<5000;++i){
		Grille2->run();
		Grille2->stats("stats2.txt");
		if(i%3==0){
			Grille2->lavage();
		}
	}	
	delete Grille2;
	
	
	Grille * Grille3 = new Grille(32,32,60.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	remove("stats3.txt");
	for(int i=0;i<5000;++i){
		Grille3->run();
		Grille3->stats("stats3.txt");
		if(i%3==0){
			Grille3->lavage();
		}
	}	
	delete Grille3;
*/
	
	// ===========================================================================
	//                  DETERMINATION DES TRANSITIONS DE PHASE
	// ===========================================================================
	
/*
	char etat_cur='C';
	char etat_prev='C';
	
	for(float A=0.0;A<=50.0;A=A+5.0) {
		for(int T=1;T<=1500;T=T+50) {
			Grille * test = new Grille(32,32,A,0.0,0.02,0.1,0.1,0.1,0.1,0.1);		
			for(int i=0;i<5000;++i){
				test->run();
				if(i%T == 0){
					test->lavage();
				}
			}
			etat_prev=etat_cur;
			etat_cur=test->etat();
			if(etat_cur!=etat_prev) {
				cout<<"A= "<<A<<"	T= "<<T<<"	"<<etat_cur<<endl;
			}
			delete test;	
		}
	}
*/
	
	return 0;
}

