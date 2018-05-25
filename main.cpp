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
	
	/*Grille* laGrille = new Grille(32,32,20.0,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	for(int i=0;i<5;++i){
		laGrille->run();
	}
	cout<<laGrille->to_string()<<endl;
	cout<<laGrille->affichage()<<endl;
	
	delete laGrille;
	

	Grille* laPititeGrille = new Grille(3,3,2,0.0,0.02,0.1,0.1,0.1,0.1,0.1);
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
	
	for(int i=0;i<5000;++i){
		laGrille->run();
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
	
	Grille* Grille1 = new Grille(32,32,15.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille1->run();
		if(i%6==0){
			Grille1->lavage();
		}
	}	
	
	cout<<"Grille 1 : "<<endl;
	cout<<Grille1->to_string()<<endl;
	delete Grille1;
	
	Grille* Grille2 = new Grille(32,32,30.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille2->run();
		if(i%6==0){
			Grille2->lavage();
		}
	}
	
	cout<<"Grille 2 : "<<endl;
	cout<<Grille2->to_string()<<endl;
	
	delete Grille2;	
	
	Grille* Grille3 = new Grille(32,32,45.0,0.001,0.02,0.1,0.1,0.1,0.1,0.1);
	
	for(int i=0;i<5000;++i){
		Grille3->run();
		if(i%6==0){
			Grille3->lavage();
		}
	}	
	
	cout<<"Grille 3 : "<<endl;
	cout<<Grille3->to_string()<<endl;
	
	delete Grille3;
	*/
	
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
	
	return 0;
}



