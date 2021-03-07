#include "Entity.h"

//initializer
void Entity::initVariables()
{
	this->sprite = nullptr;
	this->texture = nullptr;
	this->movementSpeed = 100.f;
}

//constructor / detructor
Entity::Entity()
{
	//this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->initVariables();

}

Entity::~Entity()
{
	delete this->sprite;
}

//component func
void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::setPosition(const float x, const float y)
{
	if (this->sprite)
		this->sprite->setPosition(x, y);
}

//func
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if(this->sprite)
		this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	if(this->sprite)
		target->draw(*this->sprite);
}
