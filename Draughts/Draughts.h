#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Pawn.h"
#include "PawnsManager.h"

class Draughts
{
private:
	PawnsManager* Manager{};

	unsigned int Width{ 800 };
	unsigned int Height{ 800 };

	sf::RenderWindow Window;

	sf::Texture BoardTexture;

	sf::Texture WhiteTexture;
	sf::Texture BlackTexture;
	sf::Texture WhiteQueenTexture;
	sf::Texture BlackQueenTexture;

	sf::Sprite BoardSprite;

	std::string MovesHistory{};

public:
	Draughts();

	void MainLoop();

	std::vector<Pawn*> PlacePawns();
};