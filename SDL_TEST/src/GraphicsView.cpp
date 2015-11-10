/*
 * GraphicsView.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: thomas
 */

#include "GraphicsView.h"
#include <iostream>
using namespace std;

bool GraphicsView::createWindow() {
	m_Window = SDL_CreateWindow(m_windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);

	if (m_Window == NULL) {
		cout << "Failed to create Window. SDL_ERROR: " << SDL_GetError();
		return false;
	}

	return true;
}

void GraphicsView::updateWindow() {
	SDL_RenderPresent(m_RenderRect);
}

GraphicsView::GraphicsView(string windowTitle, unsigned screenWidth, unsigned screenHeight) {
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_windowTitle = windowTitle;

	m_ScreenSurface = NULL;
	m_RenderRect = NULL;
	m_Window = NULL;
}

bool GraphicsView::initialize() {
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}

	if (!createWindow())
		return false;

	m_ScreenSurface = SDL_GetWindowSurface(m_Window);
	return true;
}

void GraphicsView::createRender() {
	m_RenderRect = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_RenderRect != NULL)
		SDL_RenderClear(m_RenderRect);

	return;
}

void GraphicsView::drawRect(int x, int y, int width, int height) {
	m_rect = { x, y, width, height};

	SDL_RenderClear(m_RenderRect);
	SDL_SetRenderDrawColor(m_RenderRect, 0x00, 0x00, 0xFF, 0xFF );
	SDL_RenderDrawRect(m_RenderRect, &m_rect);
	SDL_RenderFillRect(m_RenderRect, &m_rect);
	SDL_RenderPresent(m_RenderRect);
}

void GraphicsView::close() {
	/* will also destroy the screen surface */
	SDL_DestroyWindow(m_Window);
	m_Window = NULL;

	/* Quit SDL subsystems */
	SDL_Quit();
}

GraphicsView::~GraphicsView() {
	this->close();
}
