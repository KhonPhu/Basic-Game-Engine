#pragma once

#include "Texture.h"

class Animation
{
public:
	Animation();

	Animation(Texture* spriteSheet, int numberOfFrames, float frameDuration);

	// updates each frame 
	void Update(float deltaTime);

	//draws each frame 
	void Draw(SDL_Renderer* renderer, int x, int y);

	~Animation();

private:
	// Get the number of frames in the sprite sheet 
	int m_numberOfFrames;
	// width of each frame in the sprite sheet 
	int m_frameWidth;
	// height of each frame in the sprite sheet 
	int m_frameHeight;
	// delay between each frame 
	float m_frameDuration;
	// stores the sprite sheet 
	Texture* m_spriteSheet;
	// timer for each frame  
	float m_frameTimer;
	// current frame in the sprite sheet 
	int m_currentFrame;
};


