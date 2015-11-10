#include <SDL2/SDL.h>
#include "GraphicsView.h"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400
#define ERROR_ON_INITIALIZATION 1

int main(int argc, char* args[]) {
	SDL_Event e;
	bool quitApplication = false;
	GraphicsView mainView("First Window",SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!mainView.initialize())
		return ERROR_ON_INITIALIZATION;

	mainView.createRender();
	mainView.drawRect(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50,100,100);

	while(!quitApplication) {
		mainView.updateWindow();
		SDL_Delay(20); /* 50 Hz */

		 /* Handle events on queue */
		while( SDL_PollEvent( &e ) != 0 ) { /* quit request */
			if( e.type == SDL_QUIT ) {
				quitApplication = true;
			}
		}
	}

	return 0;
}
