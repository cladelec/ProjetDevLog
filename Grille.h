#ifndef GRILLE_H_
#define GRILLE_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Bacterie.h"
#include "Case.h"
#include "BactL.h"
#include "BactS.h"

#include <vector>

using namespace std;

class Grille {

	public :

		//constructeurs
		Grille(const int W, const int H, const int A_init, float Pm, float Pd, float D, float w, float Raa, float Rab, float Rbb, float Rbc);

		//destructeur
		~Grille();
		//getters
		inline int W() const;
		inline int H() const;
		inline int A_init() const;
		//inline vector<Bacterie> population() const;
		//inline vector<Case> cases() const;

		//setters

		//public function members
		void diffusion();
		//void reproduction();
		string to_string() const;
		void maj_gap();
		vector<Case*> moore(Case c);
		
	protected :

		//attributs
		int W_;
		int H_;
		int A_init_;
		float D_;
		vector<Bacterie*> population_;
		vector<vector<Case*>> cases_;
		vector<Case*> gap_;
};

	//getter's definition
inline int Grille::W() const{
	return W_;
}

inline int Grille::H() const{
	return H_;
}

inline int Grille::A_init() const{
	return A_init_;
}

/*inline vector<Bacterie> Grille::population() const{
	return population_;
}

inline vector<Case> Grille::cases() const{
	return cases_;
}*/
#endif
