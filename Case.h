#ifndef CASE_H_
#define CASE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Bacterie.h"

using namespace std;

class Case {
	
	public : 
		//CONSTRUCTEUR
		Case(int x, int y, int Ainit);
		
		//DESTRUCTEUR
		~Case();
		
		//GETTERS
		float get_x();
		float get_y();
		float Aout();
		float Bout();
		Bacterie* get_bact();
		
		//SETTERS
		void set_A(float a);
		void set_B(float b);
		void set_C(float c);
		void set_bact(Bacterie* bact);

		//METHODS
		void mort_bact() ;
		
	protected :
		float x_;
		float y_;	
		float Aout_;
		float Bout_;
		Bacterie* bact_;
		
	
} ;


#endif
