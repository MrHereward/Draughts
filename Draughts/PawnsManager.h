#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Pawn.h"

class PawnsManager
{
private:
	std::vector<Pawn*> Pawns;

	PawnsManager(const std::vector<Pawn*>& _Pawns);

	static PawnsManager* Manager;

public:
	PawnsManager() = delete;

	static PawnsManager* GetInstance(const std::vector<Pawn*>& _Pawns);

	void MousePressed(sf::Vector2i MousePosition);

	void MouseReleased();

	void Move(sf::Vector2i MousePosition);

	void Draw(sf::RenderWindow& Window);

};