#ifndef BACTERIE_H_
#define BACTERIE_H_


class Bacterie { 
	public : 
		//Constructor
		Bacterie(); 
		//Destructor 
		virtual ~Bacterie();
		//Methods
		virtual void metaboliser()=0;
		
	protected : 
		float Pdeath; 
		float Pmut; 
		float Wmin; 
		float w_;
		
		float A_;
		float B_; 
		float C_;

};
#endif 
