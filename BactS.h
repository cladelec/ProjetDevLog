#ifndef BACTS_H_
#define BACTS_H_

#include "Bacterie.h" 

class BactS : public Bacterie { 
	public : 
		//Constructor 
		BactS(float Pm, float Pd, float Rbb, float Rbc);
		
		//Destructor 
		~BactS();
		
		//Methods 
		void metaboliser(float * A, float * B, float * C); 

		//Getters
		inline static int nb_instancesS();

	protected : 
		float Rbb_;
		float Rbc_;

		static int nb_instancesS_;
}; 

//getter's definition
inline int BactS::nb_instancesS(){
	return nb_instancesS_;
}

#endif 
