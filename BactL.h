#ifndef BACTL_H_
#define BACTL_H_

#include "Bacterie.h"

class BactL : public Bacterie { 
	public : 
		//Constructor 
		BactL(float Pm, float Pd, float w, float Raa, float Rab);
		
		
		
		//Methods 
		void metaboliser(float * A, float * B, float * C); 

	protected : 
		float Raa_;
		float Rab_;
};
#endif 
