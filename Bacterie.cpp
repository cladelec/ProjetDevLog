#include "Bacterie.h" 

//Constructor 
Bacterie::Bacterie() { 
	A_=0;
	B_=0;
	C_=0;
	Wmin_=1;
}

//Getters
float Bacterie::Pdeath() { 
	return Pdeath_; 
}

float Bacterie::Pmut() { 
	return Pmut_; 
}

