#ifndef BACTL_H_
#define BACTL_H_

#include "Bacterie.h"
#include "Case.h"

class BactL : public Bacterie { 
	public : 
		//Constructor 
		BactL(float Pm, float Pd, float Raa, float Rab);
		
		//Destructor 
		~BactL();
	
		//Methods 
		void metaboliser(Case* c); 

		//Getters
		inline static int nb_instancesL();

	protected : 
		float Raa_;
		float Rab_;

		static int nb_instancesL_;
};

	//getter's definition

inline int BactL::nb_instancesL(){
	return nb_instancesL_;
}

#endif 
