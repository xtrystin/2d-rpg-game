#include "Player.h"

//init func
void Player::initVariables()
{

}

void Player::initComponent()
{
	
}

//constructor
Player::Player(float x, float y, sf::Texture* texture)
{
	this->initVariables();
	this->initComponent();

	this->CreateSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}
