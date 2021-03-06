#ifndef GRILLE_H_
#define GRILLE_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Bacterie.h"
#include "Case.h"
#include "BactL.h"
#include "BactS.h"

#include <vector>

// ===========================================================================
//                             "using" statements
// ===========================================================================
using namespace std;

class Grille {
	public :
  // =========================================================================
  //                               Constructors
  // =========================================================================
		Grille(const int W, const int H, const float A_init, float Pm, float Pd, float D, float Raa, float Rab, float Rbb, float Rbc);

  // =========================================================================
  //                                Destructor
  // =========================================================================
		~Grille();

  // =========================================================================
  //                                  Getters
  // =========================================================================
		inline int W() const;
		inline int H() const;
		inline int A_init() const;

  // =========================================================================
  //                          Public Function members
  // =========================================================================
		void diffusion();
		void reproduction();
		string to_string() const;
		void maj_gap();
		vector<Case*> moore(Case c);
		void run();
		string affichage();
		void lavage();
		void stats(string const monFichier);
		char etat() ;

	protected :
  // =========================================================================
  //                               Data members
  // =========================================================================
		int W_;
		int H_;
		float A_init_;
		float D_;
		float Pm_;
		float Pd_;
		float Raa_;
		float Rab_;
		float Rbb_;
		float Rbc_;
		vector<Bacterie*> population_;
		vector<vector<Case*>> cases_;
		vector<Case*> gap_;
};

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
inline int Grille::W() const{
	return W_;
}

inline int Grille::H() const{
	return H_;
}

inline int Grille::A_init() const{
	return A_init_;
}


#endif // GRILLE_H_
