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
		Grille(const int W, const int H, const int A_init, float Pm, float Pd, float w, float Raa, float Rab, float Rbb, float Rbc);

		//destructeur

		//getters
		inline int W() const;
		inline int H() const;
		inline int A_init() const;

		//setters

		//public function members
    string to_string() const;

	protected :

		//attributs
		int W_;
		int H_;
		int A_init_;
		vector<Bacterie*> population_;
		vector<vector<Case*>> cases_;
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

#endif
