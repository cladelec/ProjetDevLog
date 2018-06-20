// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Grille.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>

#include "Bacterie.h"
#include "Case.h"
#include "BactL.h"
#include "BactS.h"

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

// ===========================================================================
//                             "using" statements
// ===========================================================================
using namespace std;

// ===========================================================================
//                                Constructors
// ===========================================================================
Grille::Grille(const int W, const int H, const float A_init, float Pm, float Pd, float D, float Raa, float Rab, float Rbb, float Rbc) :  W_(W), H_(H), A_init_(A_init), D_(D), Pm_(Pm), Pd_(Pd), Raa_(Raa), Rab_(Rab), Rbb_(Rbb), Rbc_(Rbc), gap_(vector <Case*>()) {
	//création tableau 2D 
	for(int i=0; i<H_; ++i){
		cases_.push_back(vector<Case*>());
	}
	//ajout cases dans tableau
	for(int i=0; i<H_; ++i){
		for(int j=0; j<W_;++j){
			Case* c = new Case(i,j,A_init_);
			cases_[i].push_back(c);
		}
	}
	//création bactéries
	for(int i=0; i<floor(W_*H_/2);++i){ // prend la partie entière si W_*H_/2 n'est pas un int
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


// ===========================================================================
//                                 Destructor
// ===========================================================================
Grille::~Grille() { 
	//supprimer les bactéries de la grille
	vector<Bacterie *>::iterator it=population_.begin(); 
	vector<Bacterie *>::iterator popto_remove;
	while(it != population_.end()){
		 popto_remove = it;
		 ++it; 
		 delete *popto_remove;
	}
	//supprimer les cases de la grille
	vector<vector<Case *>>::iterator cases1D=cases_.begin();
	vector<Case *>::iterator cases2D=cases1D->begin();
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

// ===========================================================================
//                           Public Function members
// ===========================================================================

void Grille::diffusion(){
	for(int x=0; x<H_; ++x){
		for(int y=0; y<W_;++y){ //on parcourt toutes les cases
									
			//Algo de diffusion des métabolites
			float ainit=cases_[x][y]->Aout();
			float binit=cases_[x][y]->Bout();
			float cinit=cases_[x][y]->Cout();
			
			//Grille Toroidale
			for (int i=-1;i<=1;++i){
				int indx=x+i;
				for (int j=-1;j<=1;++j){
					int indy=y+j;
					if(indy>=W_) { 
						indy=0;
					}	
					if(indy<0) { 
						indy=W_-1;
					}
					if(indx>=H_) { 
						indx=0;
					}
					if(indx<0) { 
						indx=H_-1;
					}
					cases_[x][y]->set_A(cases_[x][y]->Aout()+D_*cases_[indx][indy]->Aout()); //maj de la concentration en A
					cases_[x][y]->set_B(cases_[x][y]->Bout()+D_*cases_[indx][indy]->Bout()); //maj de la concentration en B
					cases_[x][y]->set_C(cases_[x][y]->Cout()+D_*cases_[indx][indy]->Cout()); //maj de la concentration en C
				}
			}
			
			cases_[x][y]->set_A(cases_[x][y]->Aout()+D_*9*ainit);
			cases_[x][y]->set_B(cases_[x][y]->Bout()+D_*9*binit);
			cases_[x][y]->set_C(cases_[x][y]->Cout()+D_*9*cinit);		
		}
	}	
}

void Grille::reproduction(){
	maj_gap();
	for(vector<Case*>::iterator it = gap_.begin(); it != gap_.end(); ++it){
		vector<Case*> vois=moore(**it);
		int pos_best=0; //lequel est le meilleur ??
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
			float proba=(rand()%100+1);
			if(proba>Pm_*100) { //la bactérie ne mute pas
				BactL* b=new BactL(Pm_,Pd_,Raa_,Rab_);
				(*it)->set_bact(b);
				population_.push_back(b);
				b->set_A(vois[pos_best]->get_bact()->A()/2);
				b->set_B(vois[pos_best]->get_bact()->B()/2);
				b->set_C(vois[pos_best]->get_bact()->C()/2);
			} else { //la bactérie mute
				BactS* b=new BactS(Pm_,Pd_,Rbb_,Rbc_);
				(*it)->set_bact(b);
				population_.push_back(b);
				b->set_A(vois[pos_best]->get_bact()->A()/2);
				b->set_B(vois[pos_best]->get_bact()->B()/2);
				b->set_C(vois[pos_best]->get_bact()->C()/2);
			}
		} else {
			float proba=(rand()%100+1);
			if(proba>Pm_*100) { //la bactérie ne mute pas
				BactS* b=new BactS(Pm_,Pd_,Rbb_,Rbc_);
				(*it)->set_bact(b);
				population_.push_back(b);
				b->set_A(vois[pos_best]->get_bact()->A()/2);
				b->set_B(vois[pos_best]->get_bact()->B()/2);
				b->set_C(vois[pos_best]->get_bact()->C()/2);
			} else { //la bactérie mute
				BactL* b=new BactL(Pm_,Pd_,Raa_,Rab_);
				(*it)->set_bact(b);
				population_.push_back(b);
				b->set_A(vois[pos_best]->get_bact()->A()/2);
				b->set_B(vois[pos_best]->get_bact()->B()/2);
				b->set_C(vois[pos_best]->get_bact()->C()/2);
			
			}
		}					
	}
}

//met à jour le vecteur de cases vides
void Grille::maj_gap(){
	gap_.erase(gap_.begin(),gap_.end());
	for(int x=0; x<H_; ++x){
		for(int y=0; y<W_;++y){ //on parcourt toutes les cases
			if(cases_[x][y]->get_bact()==nullptr){ //si pas de bactérie
				gap_.push_back(cases_[x][y]); 			 //on ajoute dans le vecteur de gap
			}	
		}
	}
	random_shuffle(gap_.begin(),gap_.end());
}

//renvoie le voisinage de Moore
//Preconditions : fournir une case sans bacterie en paramètre
vector<Case*> Grille::moore(Case c){
	vector<Case*> ret;
	for (int i=-1;i<=1;++i){
		for (int j=-1;j<=1;++j){
			int x=c.get_ord()+i;
			int y=c.get_abs()+j;
			
			//grille Toroidale
			if(x>=H_) { 
				x=0;
			} 
			if(x<0) { 
				x=H_-1;
			} 
			if(y>=W_) {
				y=0;
			} 
			if(y<0) { 
				y=W_-1;
			}
			
			if(cases_[x][y]->get_bact()!=nullptr){
				ret.push_back(cases_[x][y]);
			}
		}
	}
	return ret;
}

//méthodes à effectuer à chaque pas de temps de simulation
void Grille::run() {
	diffusion();

	//mort des bacteries
	for(vector<vector<Case*>>::iterator it=cases_.begin(); it != cases_.end(); ++it){
		for(vector<Case*>::iterator it2 = it->begin(); it2!=it->end(); ++it2){
			(*it2)->mort_bact(population_);
		}
	}
	reproduction();
	
	//métaboliser	
	for(vector<vector<Case*>>::iterator it=cases_.begin(); it != cases_.end(); ++it){
		for(vector<Case*>::iterator it2 = it->begin(); it2!=it->end(); ++it2){
			if((*it2)->get_bact() != nullptr) {
				Bacterie* b_cur=(*it2)->get_bact();
				b_cur->metaboliser(*it2);
			}
		}
	}
}

//renvoie le le nombre de bactéries S et L et l'état de la population
string Grille::to_string() const{
	char delim = '\t';
  stringstream sst;
  sst << "Nombre de Bactérie S"  << delim << BactS::nb_instancesS() << "\n"; //nb d'instances S
  sst << "Nombre de Bactérie L" << delim << BactL::nb_instancesL() << "\n"; //nb d'instances L

	if(BactS::nb_instancesS()==0 && BactL::nb_instancesL()==0){ //extinction
		sst << "L'intégralité de la population est éteinte...Dommage"  << "\n";
	}
	else if(BactS::nb_instancesS()>0 && BactL::nb_instancesL()>0){ //cohabitation
		sst << "Les lignées de bactéries S et de bactéries L cohabitent."  << "\n";
	}
		else if(BactS::nb_instancesS()==0){ //exclusion
		sst << "La lignée S s'est éteinte."  << "\n";
	}
  return sst.str();
}


//renvoie la grille de  jolie manière graphique sur le terminal
string Grille::affichage(){
  stringstream sst;
	for(int i=0; i<H_; ++i){ //séparation entre lignes
			sst << "----";
		for(int k=0; k<W_-1; ++k){ //1ere ligne
			sst << "----";
		}
		sst << "-" << "\n";
		for(int j=0; j<W_;++j){ //pour chaque colonne quel type de bactéries est dans la case
			if(cases_[i][j]->get_bact() == nullptr){
				sst << "|   "; //absence de bactérie
			}else if(cases_[i][j]->get_bact()->typeL()){
				sst << "| L "; //présence bactérie L
			}else{
				sst << "| S "; //présence bactérie S
			}
		}
		sst << "|" << "\n";
	}
	for(int k=0; k<W_; ++k){ //dernière ligne
		sst << "----";
	}
	sst << "-" << "\n";
	return sst.str();
}

//change les métabolites exterieurs : remet tout à 0 et à Ainit
void Grille::lavage() {
	for(vector<vector<Case*>>::iterator it=cases_.begin(); it != cases_.end(); ++it){
		for(vector<Case*>::iterator it2 = it->begin(); it2!=it->end(); ++it2){
				(*it2)->set_A(A_init_);
				(*it2)->set_B(0.0);
				(*it2)->set_C(0.0);
		}
	}
} 

//écrit les stats à la suite du fichier texte passé en paramètre
//Préconditions : Donner un fichier vierge
void Grille::stats(string const monFichier) { 
	ofstream monFlux(monFichier.c_str(),ios::app);
	if(monFlux) { 
		monFlux << BactS::nb_instancesS() << "	"  << BactL::nb_instancesL()  << endl; 

	} else { 
		cout << "ERREUR: Impossible d'ouvrir le fichier" << endl;
	}
}
//renvoie l'état de la grille
char Grille::etat() {
	if(BactL::nb_instancesL()==0){ //extinction
		return 'I';
	}
	else if(BactS::nb_instancesS()>0 && BactL::nb_instancesL()>0){ //cohabitation
		return 'C';
	}
	else if(BactS::nb_instancesS()==0){ //exclusion
		return 'U';
	}
}
