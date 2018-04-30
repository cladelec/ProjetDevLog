#ifndef BACTS_H_
#define BACTS_H_

#include "Bacterie.h" 

class BactS : public Bacterie { 
	public : 
		//Constructor 
		BactS(float Pm, float Pd, float w, float Rbb, float Rbc);
		
		
		
		//Methods 
		void metaboliser(float * A, float * B, float * C); 

	protected : 
		float Rbb_;
		float Rbc_;

}; 
#endif 
