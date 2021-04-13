#include "PawnsManager.h"

PawnsManager* PawnsManager::Manager = nullptr;

PawnsManager::PawnsManager()
{

}

PawnsManager* PawnsManager::GetInstance()
{
	if (!Manager)
	{
		Manager = { new PawnsManager };
	}

	return Manager;
}

void PawnsManager::AddPawn(char X, int Y, Pawn* NewPawn, std::map<char, std::map<int, Pawn*>>& Board)
{
	Board[X][Y] = { NewPawn };
}

void PawnsManager::MousePressedPawns(sf::Vector2i MousePosition, std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			Element->MousePressed(MousePosition);
		}
	}
}

void PawnsManager::MouseReleasedPawns(std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			Element->MouseReleased(Board);
		}
	}
}

void PawnsManager::MovePawns(sf::Vector2i MousePosition, std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			Element->Move(MousePosition);
		}
	}
}

void PawnsManager::DrawPawns(sf::RenderWindow& Window, std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			Element->Draw(Window);
		}
	}
}