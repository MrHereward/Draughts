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

void PawnsManager::AddPawns(const std::vector<Pawn*>& _Pawns)
{
	for (const auto& Element : _Pawns)
	{
		Pawns.push_back(Element);
	}
}

void PawnsManager::MousePressedPawns(sf::Vector2i MousePosition)
{
	for (const auto& Element : Pawns)
	{
		Element->MousePressed(MousePosition);
	}
}

void PawnsManager::MouseReleasedPawns()
{
	for (const auto& Element : Pawns)
	{
		Element->MouseReleased();
	}
}

void PawnsManager::MovePawns(sf::Vector2i MousePosition)
{
	for (const auto& Element : Pawns)
	{
		Element->Move(MousePosition);
	}
}

void PawnsManager::DrawPawns(sf::RenderWindow& Window)
{
	for (const auto& Element : Pawns)
	{
		Element->Draw(Window);
	}
}