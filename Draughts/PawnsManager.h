#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Pawn.h"

class PawnsManager
{
private:
	std::vector<Pawn*> Pawns{};

	PawnsManager();

	static PawnsManager* Manager;

public:
	static PawnsManager* GetInstance();

	void AddPawns(const std::vector<Pawn*>& _Pawns);

	void MousePressedPawns(sf::Vector2i MousePosition);

	void MouseReleasedPawns();

	void MovePawns(sf::Vector2i MousePosition);

	void DrawPawns(sf::RenderWindow& Window);

};