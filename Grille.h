#ifndef GRILLE_H_
#define GRILLE_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Bacterie.h"
#include "Case.h"

#include <vector>

using namespace std;

class Grille {

	public :

		//constructeurs
		Grille(const int W, const int H, const int A_init);

		//destructeur

		//getters
		inline int W() const;
		inline int H() const;
		inline int A_init() const;
		//inline vector<Bacterie> population() const;
		//inline vector<Case> cases() const;

		//setters

		//public function members

	protected :

		//attributs
		int W_;
		int H_;
		int A_init_;
		vector<Bacterie> population_;
		vector<Case> cases_;
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
