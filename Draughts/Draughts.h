#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Draughts
{
private:
	unsigned int Width{ 800 };
	unsigned int Height{ 800 };

	sf::RenderWindow Window;

	sf::Texture BoardTexture;

	sf::Texture WhiteTexture;
	sf::Texture BlackTexture;
	sf::Texture WhiteQueenTexture;
	sf::Texture BlackQueenTexture;

	sf::Sprite BoardSprite;

public:
	Draughts();

	void MainLoop();
};