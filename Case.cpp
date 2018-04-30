#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Case.h"
#include "Bacterie.h"

using namespace std;


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
