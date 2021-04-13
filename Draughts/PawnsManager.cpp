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

void PawnsManager::MousePressedPawns(sf::Vector2i MousePosition, const std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			if (Element != nullptr)
			{
				Element->MousePressed(MousePosition);
			}
		}
	}
}

void PawnsManager::MouseReleasedPawns(const std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			if (Element != nullptr)
			{
				Element->MouseReleased(Board);
			}
		}
	}
}

void PawnsManager::MovePawns(sf::Vector2i MousePosition, const std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			if (Element != nullptr)
			{
				Element->Move(MousePosition);
			}
		}
	}
}

void PawnsManager::DrawPawns(sf::RenderWindow& Window, const std::map<char, std::map<int, Pawn*>>& Board)
{
	for (const auto& [Character, Map] : Board)
	{
		for (const auto& [Integer, Element] : Map)
		{
			if (Element != nullptr)
			{
				Element->Draw(Window);
			}
		}
	}
}