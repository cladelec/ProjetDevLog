#include "BactL.h"

//Constructor 
BactL::BactL(float Pm, float Pd, float w, float Raa, float Rab) : Bacterie() { 
	Pdeath_ = Pm;
	Pmut_ = Pd; 
	w_ = w;
	Rab_=Rab;
	Raa_=Raa;
} 

//Methods
void BactL::metaboliser(float * A, float * B, float * C) { 
	*A=-(*A)*Raa_; 
	A_=A_+(*A)*Raa_-A_*Rab_;
	B_=B_+A_*Rab_;
}
