// ===========================================================================
//                                  Includes
// ===========================================================================

#include "Bacterie.h" 

// ===========================================================================
//                                Constructors
// ===========================================================================

Bacterie::Bacterie() { 
	A_=0;
	B_=0;
	C_=0;
	Wmin_=1;
}

// ===========================================================================
//                                 Destructor
// ===========================================================================

Bacterie::~Bacterie() = default;

// ===========================================================================
//                           Public Function members
// ===========================================================================

//Getters
float Bacterie::Pdeath() { 
	return Pdeath_; 
}

float Bacterie::Pmut() { 
	return Pmut_; 
}

float Bacterie::A() { 
	return A_;
}

float Bacterie::B() { 
	return B_;
}

float Bacterie::C() { 
	return C_;
}

float Bacterie::w() { 
	return w_;
}

bool Bacterie::typeL() { 
	return typeL_;
}

//Setters
void Bacterie::set_A(float A) { 
	A_=A;
}

void Bacterie::set_B(float B) { 
	B_=B;
}

void Bacterie::set_C(float C) { 
	C_=C;
}
