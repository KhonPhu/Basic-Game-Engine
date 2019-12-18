#include "Texture.h"
#include <iostream>

using namespace std;

Texture::Texture()
{
	m_texture = nullptr;
	m_width = 0;
	m_height = 0;
}

bool Texture::LoadImageFromFile(const char* path, SDL_Renderer* renderer)
{
	if (m_texture == nullptr) {
		// load the image to the surface 
		SDL_Surface* loadedSurface = SDL_LoadBMP(path);

		// if the image was successfully loaded 
		if (loadedSurface != nullptr) {
			cout << "Load Texture - success" << endl;

			// create texture from surface pixels 
			m_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

			// if the texture was successfully created from the loaded surface
			if (m_texture != nullptr) {

				cout << "Create texture from surface - success" << endl;
				// get texture dimensions 
				m_width = loadedSurface->w;
				m_height = loadedSurface->h;
			}
			else {
				cout << "create texture from surface - failed" << SDL_GetError << endl;
			}

			// free the loaded surface 
			SDL_FreeSurface(loadedSurface);
		}
		else {
			cout << "Load Texture - failed" << SDL_GetError() << endl;
		}
	}
	else {
		cout << "remove the existing texture before loading a texture" << endl;
		return false;
	}
	return m_texture != nullptr;
}


void Texture::Draw(SDL_Renderer* renderer, int x, int y, SDL_Rect* sourceRect)
{
	// set the rendering space and render to dimensions
	SDL_Rect destRect = { x, y, m_width, m_height };

	// set clip rendering dimensions 
	if (sourceRect != nullptr) {
		destRect.w = sourceRect->w;
		destRect.h = sourceRect->h;
	}

	// render to screen 
	SDL_RenderCopy(renderer, m_texture, sourceRect, &destRect);

}

void Texture::ResetTexture()
{
	// deallocate the texture 
	if (m_texture != nullptr) {
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}

}

Texture::~Texture()
{
	ResetTexture();
}
