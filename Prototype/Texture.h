#pragma once
#include <SDL.h>
#include <cstddef>

class Texture
{
public:
	Texture();
	bool LoadImageFromFile(const char* path, SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer, int x, int y, SDL_Rect* sourceRect = NULL);

	int GetImageWidth()
	{
		return m_width;
	}
	int GetImageHeight()
	{
		return m_height;
	}

	void ResetTexture();

	~Texture();
private:
	SDL_Texture* m_texture;

	int m_height;
	int m_width;
};

