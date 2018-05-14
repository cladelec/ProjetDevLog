#ifndef BACTS_H_
#define BACTS_H_

#include "Bacterie.h" 
#include "Case.h"

class BactS : public Bacterie { 
	public : 
		//Constructor 
		BactS(float Pm, float Pd, float Rbb, float Rbc);
		
		//Destructor 
		~BactS();
		
		//Methods 
		void metaboliser(Case* c); 

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
