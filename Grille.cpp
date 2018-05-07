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
#include <sstream>
#include <string>

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
	//ajout dans vecteur Bacterie
		population_.push_back(bl);
		population_.push_back(bs);
	}
	//mélange Bacterie
	random_shuffle ( population_.begin(), population_.end() );
	//distribue Bacterie dans une case
	for(vector<Bacterie*>::iterator it = population_.begin(); it != population_.end(); ++it){
		float x; float y;
		do { 
		x=(rand()%W_+1);
		y=(rand()%H_+1);
	//si case déjà occupée recommencer
		} while (cases_[x][y]->get_bact() != nullptr);
		cases_[x][y]->set_bact(*it);
	}
}

string Grille::to_string() const{
  char delim = '\t';
  stringstream sst;
  sst << "Nombre de Bactérie S"  << delim << BactS::nb_instancesS() << "\n";
  sst << "Nombre de Bactérie L" << delim << BactL::nb_instancesL() << "\n";

	if(BactS::nb_instancesS()==0 && BactL::nb_instancesL()==0){
		sst << "L'intégralité de la population est éteinte..."  << "\n";
	}
	else if(BactS::nb_instancesS()>0 && BactL::nb_instancesL()>0){
		sst << "Les lignées de bactéries S et de bactéries L cohabitent."  << "\n";
	}
		else if(BactS::nb_instancesS()==0){
		sst << "La lignée S s'est éteinte."  << "\n";
	}
  return sst.str();
}
