#pragma once

#include "State.hpp"

#include "Background.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "EventHandler.hpp"
#include "Score.hpp"

#define SPAWN_INTERVAL 2.0

class GameState : public State
{
private:
	Background				mBackground;
	Background				mFog;
	sf::Clock				mFogClock;
	EventHandler			mEventHandler;
	Player					mPlayer;

	sf::Sprite				mTarget;

	void					LoadDefaultKeys();

	//Spawner
	sf::Clock							mSpawnerClock;
	float								mSpawnInterval = SPAWN_INTERVAL;
	std::list<Entity *>					mEntities;
	std::list<std::unique_ptr<Bullet>>	mBullets;
	
	void					HandleBulletLogic();
	void					Spawn();
	void					Despawn();

public:
	GameState(Window *tWindow);
	~GameState();

	void					Init();
	void					HandleEvents();
	void					Update();
	void					Render();
};

