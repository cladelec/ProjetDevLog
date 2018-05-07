#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Case.h"
#include "Bacterie.h"

using namespace std;

//CONSTRUCTEUR
Case::Case(int x, int y, int Ainit) : x_(x), y_(y), Bout_(0), Aout_(Ainit), bact_(nullptr) {}

//DESTRUCTEUR
Case::~Case()=default;

//GETTERS
float Case::get_x() {
	return x_;
}

float Case::get_y() {
	return y_;
}

float Case::Aout() {
	return Aout_;
}

float Case::Bout() {
	return Bout_;
}

Bacterie* Case::get_bact() {
	return bact_;
}

//SETTERS
void Case::set_A(float a){
	Aout_=a;
}

void Case::set_B(float b){
	Bout_=b;
}

void Case::set_bact(Bacterie* bact){
	bact_=bact;
}

//METHODS
void Case::mort_bact() {
	float proba=(rand()%100+1); //donne une proba entre 1 et 100
	if (proba<bact_->Pdeath()) {
		bact_=nullptr;
		//delete bact_;
	}	
}
	
