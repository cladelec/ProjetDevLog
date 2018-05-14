#include "BactL.h"
#include "Case.h"

//Definition of static attributes
int BactL::nb_instancesL_=0;

//Constructor 
BactL::BactL(float Pm, float Pd, float Raa, float Rab)  { 
	Pdeath_ = Pm;
	Pmut_ = Pd; 
	w_ = 0;
	Rab_=Rab;
	Raa_=Raa;
	++nb_instancesL_;
	typeL_=1;
} 

//Destructor 
BactL::~BactL() { 
	nb_instancesL_--;
}

//Methods
void BactL::metaboliser(Case* c) { 
	/**A=*A-(*A)*Raa_; 
	A_=A_+(*A)*Raa_-A_*Rab_;
	B_=B_+A_*Rab_;*/
	c->set_A(c->Aout()-c->Aout()*Raa_);
	A_=A_+c->Aout()*Raa_-A_*Rab_;
	B_=B_+A_*Rab_;
	
	//modif de la fitness 
	if(B_>Wmin_) { 
		w_=B_;
	} else { 
		w_=0;
	}
}
