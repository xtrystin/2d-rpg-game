#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Entity
{
private:
	void initVariables();

protected:
	sf::Texture * texture;	//from outside
	sf::Sprite * sprite;

	//sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//component func
	void CreateSprite(sf::Texture* texture);

	//func
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float x, const float y);

	virtual void update(const float& dt); //=0;
	virtual void render(sf::RenderTarget* target); //=0;
};

