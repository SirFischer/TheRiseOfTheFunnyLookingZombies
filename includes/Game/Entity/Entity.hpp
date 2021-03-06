#pragma once

#include <math.h>
#include "Window.hpp"
#include "ResourceManager.hpp"


enum class EntityState {
	IDLE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

class Entity
{
protected:
	sf::Vector2f	mPos = sf::Vector2f(200, 200);
	sf::Vector2f	mVelocity = sf::Vector2f(0, 0);
	sf::Vector2f	mAcceleration = sf::Vector2f(0.75, 0.75);
	float			mDragCoefficient = 0.90;
	float			mRotation = 0.f;
	int				mHP = 100;

	sf::Texture		mTexture;
	sf::Sprite		mSprite;

	EntityState		mState;

	void			HandleState();

public:

	Entity(/* args */);
	virtual ~Entity(){};

	virtual void	Update();
	void			HandleEvents();
	void			Render(Window *tWindow);

	void			TakeDamage(float tAttackDamage);

	sf::Vector2f	GetPos(){return (mPos);}
	int				GetHP(){return (mHP);}
};

