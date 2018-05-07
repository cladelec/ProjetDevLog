#include "BactL.h"

//Definition of static attributes
int BactL::nb_instancesL_=0;

//Constructor 
BactL::BactL(float Pm, float Pd, float w, float Raa, float Rab) : Bacterie() { 
	Pdeath_ = Pm;
	Pmut_ = Pd; 
	w_ = w;
	Rab_=Rab;
	Raa_=Raa;
	++nb_instancesL_;
} 

//Methods
void BactL::metaboliser(float * A, float * B, float * C) { 
	*A=*A-(*A)*Raa_; 
	A_=A_+(*A)*Raa_-A_*Rab_;
	B_=B_+A_*Rab_;
}
