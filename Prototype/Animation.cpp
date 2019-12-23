#include "Animation.h"

Animation::Animation()
{
	m_numberOfFrames = 0;
	m_frameWidth = 0;
	m_frameHeight = 0;
	m_frameDuration = 0;
	m_spriteSheet = nullptr;
	m_frameTimer = 0;
	m_currentFrame = 0;
}


Animation::Animation(Texture* spriteSheet, int numberOfFrames, float frameDuration)
{
	m_spriteSheet = spriteSheet;
	m_numberOfFrames = numberOfFrames;
	if (m_spriteSheet != nullptr) {
		m_frameWidth = m_spriteSheet->GetImageWidth() / m_numberOfFrames;
		m_frameHeight = m_spriteSheet->GetImageHeight();
	}
	m_frameDuration = frameDuration;
	m_frameTimer = 0.0f;
	m_currentFrame = 0;
}

void Animation::Update(float deltaTime)
{
	// cycle through animation frames 
// update frameTimer 
	m_frameTimer += deltaTime;

	// if the current frame has reached it's duration 
	if (m_frameTimer >= m_frameDuration) {
		// go to the next frame 
		m_currentFrame++;
		// reset frame timer 
		m_frameTimer = 0.0f;

		// if we reached the end of the spritesheet 
		if (m_currentFrame >= m_numberOfFrames) {
			// start again from the first frame 
			m_currentFrame = 0;
		}
	}
}

void Animation::Draw(SDL_Renderer* renderer, int x, int y)
{
	// get the current frame clipping region 
	SDL_Rect clip;
	clip.x = m_currentFrame * m_frameWidth;
	clip.y = 0;
	clip.w = m_frameWidth;
	clip.h = m_frameHeight;
	// draw 
	m_spriteSheet->Draw(renderer, x, y, &clip);

}

Animation::~Animation()
{
	// deallocate the sprite sheet 
	if (m_spriteSheet != nullptr) {
		delete m_spriteSheet;
		m_spriteSheet = nullptr;
	}

}
