#include "BactS.h"

//Definition of static attributes
int BactS::nb_instancesS_=0;

//Constructor 
BactS::BactS(float Pm, float Pd, float w, float Rbb, float Rbc) : Bacterie() { 
	Pdeath_ = Pm;
	Pmut_ = Pd; 
	w_ = w;
	Rbc_=Rbc;
	Rbb_=Rbb;
	++nb_instancesS_;
} 

//Methods
void BactS::metaboliser(float * A, float * B, float * C) { 
	*B=*B-(*B)*Rbb_; 
	B_=B_+(*B)*Rbb_-B_*Rbc_;
	C_=C_+B_*Rbc_;
}

