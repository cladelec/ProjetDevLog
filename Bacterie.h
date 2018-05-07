#ifndef BACTERIE_H_
#define BACTERIE_H_


class Bacterie { 
	public : 
		//Constructor
		Bacterie(); 
	

		//Methods
		virtual void metaboliser(float * A, float * B, float * C)=0;
		//Getters 
		float Pdeath();
		float Pmut();
		float A();
		float B();
		float C();
		
		//Setters
		void set_A(float A);
		void set_B(float B);
		void set_C(float C);
	protected : 
		float Pdeath_; 
		float Pmut_; 
		float Wmin_; 
		float w_;
		
		float A_;
		float B_; 
		float C_;

};
#endif 
