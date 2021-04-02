#include "PawnsManager.h"

PawnsManager* PawnsManager::Manager = nullptr;

PawnsManager::PawnsManager(const std::vector<Pawn*>& _Pawns)
	: Pawns{ _Pawns }
{

}

PawnsManager* PawnsManager::GetInstance(const std::vector<Pawn*>& _Pawns)
{
	if (!Manager)
	{
		Manager = { new PawnsManager(_Pawns) };
	}

	return Manager;
}

void PawnsManager::MousePressed(sf::Vector2i MousePosition)
{
	for (const auto& Element : Pawns)
	{
		if (Element->getGlobalBounds().contains(MousePosition.x, MousePosition.y))
		{
			Element->SetIsMove(true);

			Element->SetMovePosition(sf::Vector2i(MousePosition.x - Element->getPosition().x, MousePosition.y - Element->getPosition().y));
		}
	}
}

void PawnsManager::MouseReleased()
{
	for (const auto& Element : Pawns)
	{
		if (Element->GetIsMove())
		{
			sf::Vector2f CurrentPosition{ Element->getPosition() };

			Element->SetIsMove(false);

			sf::Vector2f NewPosition{ sf::Vector2f(48 + (88 * static_cast<int>(Element->getPosition().x / 88)), 48 + (88 * static_cast<int>(Element->getPosition().y / 88))) };

			Element->setPosition(NewPosition);



			//Element->SetPosition();
		}
	}
}

void PawnsManager::Move(sf::Vector2i MousePosition)
{
	for (const auto& Element : Pawns)
	{
		if (Element->GetIsMove())
		{
			Element->setPosition(MousePosition.x - Element->GetMovePosition().x, MousePosition.y - Element->GetMovePosition().y);
		}
	}
}

void PawnsManager::Draw(sf::RenderWindow& Window)
{
	for (const auto& Element : Pawns)
	{
		Window.draw(*Element);
	}
}