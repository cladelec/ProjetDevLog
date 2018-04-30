#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Case.h"
#include "Bacterie.h"

using namespace std;

//CONSTRUCTEUR
Case::Case(int x, int y, int Ainit) : x_(x), y_(y), B_(0), C_(0) {
	A_=Ainit;
	bact_=nullptr;
}

//GETTERS
float Case::get_x() {
	return x_;
}

float Case::get_y() {
	return y_;
}

float Case::get_A() {
	return A_;
}

float Case::get_B() {
	return B_;
}

float Case::get_C() {
	return C_;
}

Bacterie* Case::get_bact() {
	return bact_;
}

//SETTERS
void Case::set_A(float a){
	A_=a;
}

void Case::set_B(float b){
	B_=b;
}

void Case::set_C(float c){
	C_=c;
}

void Case::set_bact(Bacterie* bact){
	bact_=bact;
}
	
