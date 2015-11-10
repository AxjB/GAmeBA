/*
 * GraphicsView.h
 *
 *  Created on: Nov 10, 2015
 *      Author: thomas
 */

#ifndef GRAPHICSVIEW_H_
#define GRAPHICSVIEW_H_

#include <SDL2/SDL.h>
#include <string>
using namespace std;

class GraphicsView {
private:
	SDL_Window* m_Window;

	/* surface contained by the window */
	SDL_Surface* m_ScreenSurface;

	/* window specifications */
	unsigned m_screenWidth;
	unsigned m_screenHeight;
	string m_windowTitle;

	/* some drawing objects, need to be shifted out in the future */
	SDL_Renderer* m_RenderRect;
	SDL_Rect m_rect;

	bool createWindow();
public:
	GraphicsView(string windowTitle, unsigned screenWidth=0, unsigned screenHeight=0);
	bool initialize();
	void updateWindow();
	void createRender();
	void drawRect(int x, int y, int width, int height);
	void close();
	~GraphicsView();
};

#endif /* GRAPHICSVIEW_H_ */
