#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	//variables

	//init func
	void initVariables();
	void initComponent();

public:
	Player(float x, float y, sf::Texture* texture);
	virtual ~Player();

	//func
};


