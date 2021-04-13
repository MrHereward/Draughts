#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Pawn.h"

class PawnsManager
{
private:
	PawnsManager();

	static PawnsManager* Manager;

public:
	static PawnsManager* GetInstance();

	void AddPawn(char X, int Y, Pawn* NewPawn, std::map<char, std::map<int, Pawn*>>& Board);

	void MousePressedPawns(sf::Vector2i MousePosition, const std::map<char, std::map<int, Pawn*>>& Board);

	void MouseReleasedPawns(const std::map<char, std::map<int, Pawn*>>& Board);

	void MovePawns(sf::Vector2i MousePosition, const std::map<char, std::map<int, Pawn*>>& Board);

	void DrawPawns(sf::RenderWindow& Window, const std::map<char, std::map<int, Pawn*>>& Board);

};