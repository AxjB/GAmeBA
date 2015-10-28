//============================================================================
// Name        : SDL_TEST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

int main(int argc, char* args[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
int status = SDL_Init(SDL_INIT_EVERYTHING);
cout<<status<<endl;
int c;
cin >> c;

	if (c > 2)
		cout << "you so pro" << endl;

	return 0;


}
