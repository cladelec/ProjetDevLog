#ifndef CASE_H_
#define CASE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Bacterie.h"

using namespace std;

class Case {
	
	public : 
		//GETTERS
		float get_x();
		float get_y();
		float get_A();
		float get_B();
		float get_C();
		Bacterie* get_bact();
		
		//SETTERS
		void set_A(float a);
		void set_B(float b);
		void set_C(float c);
		void set_bact(Bacterie* bact);
	
	protected :
		float x_;
		float y_;	
		float A_;
		float B_;
		float C_;
		Bacterie* bact_;
		
	
} ;


#endif
