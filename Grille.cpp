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
Grille::Grille(const int W, const int H, const int A_init, float Pm, float Pd, float D, float Raa, float Rab, float Rbb, float Rbc) :  W_(W), H_(H), A_init_(A_init), D_(D), Pm_(Pm), Pd_(Pd), Raa_(Raa), Rab_(Rab), Rbb_(Rbb), Rbc_(Rbc), gap_(vector <Case*>()) {
	//création tableau 2D 
	for(int i=0; i<H_; ++i){
		cases_.push_back(vector<Case*>());
	}
	//ajout cases dans tableau
	for(int i=0; i<H_; ++i){
		for(int j=0; j<W_;++j){
			Case* c = new Case(j,i,A_init_);
			cases_[i].push_back(c);
		}
	}
	//création bactéries
	for(int i=0; i<W_*H_/2;++i){
		BactL* bl = new BactL(Pm,Pd,Raa,Rab);
		BactS* bs = new BactS(Pm,Pd,Rbb,Rbc);
	//ajout dans vecteur Bacterie
		population_.push_back(bl);
		population_.push_back(bs);
	}
	//mélange Bacterie
	random_shuffle ( population_.begin(), population_.end() );
	//distribue Bacterie dans une case
	for(vector<Bacterie*>::iterator it = population_.begin(); it != population_.end(); ++it){
		int x; int y;
		do { 
		y=(rand()%W_);
		x=(rand()%H_);
	//si case déjà occupée recommencer
		} while (cases_[x][y]->get_bact() != nullptr);
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
	//cout <<*cases2D << endl;
	vector<Case *>::iterator casesto_remove;
	while(cases1D != cases_.end()) { 
		vector<Case *>::iterator cases2D=cases1D->begin();
		while(cases2D != cases1D->end()) { 
			casesto_remove = cases2D;
			++cases2D;
			delete *casesto_remove;
		}
		++cases1D;
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
	for(vector<Case*>::iterator it = gap_.begin(); it != gap_.end(); ++it){
		vector<Case*> vois=moore(**it);
		int pos_best=0; //quel est le meilleur ??
		int pos=0;
		for(vector<Case*>::iterator it2 = vois.begin(); it2 != vois.end(); ++it2){
			if( ((*it2)->get_bact())->w() > vois[pos_best]->get_bact()->w() ){
				pos_best=pos;
			}
			++pos;
		}
		vois[pos_best]->get_bact()->set_A(vois[pos_best]->get_bact()->A()/2);
		vois[pos_best]->get_bact()->set_B(vois[pos_best]->get_bact()->B()/2);	
		vois[pos_best]->get_bact()->set_C(vois[pos_best]->get_bact()->C()/2);
		if(vois[pos_best]->get_bact()->typeL()) {
			BactL* b=new BactL(Pm_,Pd_,Raa_,Rab_);
			(*it)->set_bact(b);
			population_.push_back(b);
			b->set_A(vois[pos_best]->get_bact()->A()/2);
			b->set_B(vois[pos_best]->get_bact()->B()/2);
			b->set_C(vois[pos_best]->get_bact()->C()/2);
		} else {
			BactS* b=new BactS(Pm_,Pd_,Rbb_,Rbc_);
			(*it)->set_bact(b);
			population_.push_back(b);
			b->set_A(vois[pos_best]->get_bact()->A()/2);
			b->set_B(vois[pos_best]->get_bact()->B()/2);
			b->set_C(vois[pos_best]->get_bact()->C()/2);
		}					
	}
}

void Grille::maj_gap(){
	for(int x=0; x<H_; ++x){
		for(int y=0; y<W_;++y){ //on parcourt toutes les cases
			if(cases_[x][y]->get_bact()==nullptr) { //si pas de bactérie
				gap_.push_back(cases_[x][y]); //on ajoute dans le vecteur de gap
			}	
		}
	}
	random_shuffle(gap_.begin(),gap_.end());
}

 //Pre-conditions : bien donner une case sans bacterie en paramètre
vector<Case*> Grille::moore(Case c){
	vector<Case*> ret;
	for (int i=-1;i<=1;++i){
		for (int j=-1;j<=1;++j){
			int x=c.get_x()+i;
			int y=c.get_y()+j;
			if(cases_[c.get_x()+i][c.get_y()+j]->get_bact()==nullptr){
				if(c.get_x()+i>H_) { 
					x=0;
				} 
				if(c.get_x()+i<H_) { 
					x=H_-1;
				} 
				if(c.get_y()+j>W_) {
					y=0;
				} 
				if(c.get_y()+j<W_) { 
					y=W_-1;
				}
				ret.push_back(cases_[x][y]);
			}
		}
	}
	return ret;
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

