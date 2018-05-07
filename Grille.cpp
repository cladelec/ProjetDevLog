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
Grille::Grille(const int W, const int H, const int A_init, float Pm, float Pd, float D, float w, float Raa, float Rab, float Rbb, float Rbc) :  W_(W), H_(H), A_init_(A_init), D_(D) {
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


//destructeur 
Grille::~Grille() { 
	vector<Bacterie *>::iterator it=population_.begin(); 
	vector<Bacterie *>::iterator popto_remove;
	while(it != population_.end()){
		 popto_remove = it;
		 ++it; 
		 delete *popto_remove;
	}
	
	vector<vector<Case *>>::iterator cases1D=cases_.begin();
	vector<Case *>::iterator cases2D=cases1D->begin();
	cout <<*cases2D << endl;
	vector<Case *>::iterator casesto_remove;
	while(cases1D != cases_.end()) { 
		while(cases2D != cases1D->end()) { 
			casesto_remove = cases2D;
			delete *casesto_remove;
		}
	}
}

//public function members
void Grille::diffusion(){
	for(int x=0; x<H_; ++x){
		for(int y=0; y<W_;++y){ //on parcourt toutes les cases
			
						
			//Algo de diffusion des métabolites
			int ainit=cases_[x][y]->Aout();
			int binit=cases_[x][y]->Bout();
			int cinit=cases_[x][y]->Cout();
			
			for (int i=-1;i<=1;++i){
				for (int j=-1;j<=1;++j){
					cases_[x][y]->set_A(cases_[x][y]->Aout()+D_*cases_[x+i][y+j]->Aout()); //maj de la concentration en A
					cases_[x][y]->set_B(cases_[x][y]->Bout()+D_*cases_[x+i][y+j]->Bout()); //maj de la concentration en B
					cases_[x][y]->set_C(cases_[x][y]->Cout()+D_*cases_[x+i][y+j]->Cout()); //maj de la concentration en C
				}
			}
			
			cases_[x][y]->set_A(cases_[x][y]->Aout()+D_*9*ainit);
			cases_[x][y]->set_B(cases_[x][y]->Bout()+D_*9*binit);
			cases_[x][y]->set_C(cases_[x][y]->Cout()+D_*9*cinit);
			
			
			
		}
	}
}

void Grille::reproduction(){
	
	
	
}


