// ===========================================================================
//                                  Includes
// ===========================================================================
#include "BactS.h"
#include "Case.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
int BactS::nb_instancesS_=0;

// ===========================================================================
//                                Constructors
// =========================================================================== 
BactS::BactS(float Pm, float Pd, float Rbb, float Rbc) { 
	Pdeath_ = Pd;
	Pmut_ = Pm; 
	w_ = 0;
	Rbc_=Rbc;
	Rbb_=Rbb;
	++nb_instancesS_;
	typeL_=0;
} 

// ===========================================================================
//                                 Destructor
// =========================================================================== 
BactS::~BactS() { 
	nb_instancesS_--;
}

// ===========================================================================
//                           Public Function members
// ===========================================================================
void BactS::metaboliser(Case* c) { 
	c->set_B((c->Bout())-(c->Bout()*Rbb_));
	B_=B_+c->Bout()*Rbb_-B_*Rbc_;
	C_=C_+B_*Rbc_;
	
	//modification de la fitness 
	if(C_>Wmin_) { 
		w_=C_;
	} else { 
		w_=0;
	}
}
