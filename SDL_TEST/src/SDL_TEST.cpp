//============================================================================
// Name        : SDL_TEST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define NOMINMAX

#include <iostream>
//#include <windows.h>
#include "SDL2/SDL.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
int status = SDL_Init(SDL_INIT_EVERYTHING);
cout<<status<<endl;


	return 0;
}
