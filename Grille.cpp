#include "Grille.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Bacterie.h"
#include "Case.h"
#include "BactL.h"
#include "BactS.h"

#include <vector>
#include <algorithm>

using namespace std;

//constructeur
Grille::Grille(const int W, const int H, const int A_init, float Pm, float Pd, float w, float Raa, float Rab, float Rbb, float Rbc) :  W_(W), H_(H), A_init_(A_init){
	//création tableau 2D 
	for(int i=0; i<H_; ++i){
		cases_.push_back(vector<Case*>(W_));
	}
	//ajout cases dans tableau
	for(int i=0; i<H_; ++i){
		for(int j=0; j<W_;++i){
			Case* c = new Case(j,i,A_init_);
			cases_[i].push_back(c);
		}
	}
	//création bactéries
	for(int i=0; i<W_*H_/2;++i){
		BactL* bl = new BactL(Pm,Pd,w,Raa,Rab);
		BactS* bs = new BactS(Pm,Pd,w,Rbb,Rbc);
		population_.push_back(bl);
		population_.push_back(bs);
	}
	random_shuffle ( population_.begin(), population_.end() );
	for(vector<Bacterie*>::iterator it = population_.begin(); it != population_.end(); ++it){
		float x=(rand()%W_+1);
		float y=(rand()%H_+1);
		while (cases_[x][y]->get_bact() != nullptr){
			x=(rand()%W_+1);
			y=(rand()%H_+1);
		}
		cases_[x][y]->set_bact(*it);
	}
}
