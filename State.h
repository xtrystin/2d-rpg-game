#pragma once

#include <vector>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class State
{
private:
	std::vector<sf::Texture> textures;

public:
	State();
	virtual ~State();

	virtual void update() =0;
	virtual void render() =0;
};

