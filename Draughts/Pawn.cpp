#include "Pawn.h"

Pawn::Pawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture)
	: PawnType{ _PawnType }, IsMove{ false }
{
	setPosition(x, y);
	setTexture(_Texture);
	SetPosition();
}

void Pawn::SetPawnType(PAWNTYPE _PawnType, sf::Texture _Texture)
{
	PawnType = { _PawnType };
	setTexture(_Texture);
}

PAWNTYPE Pawn::GetPawnType()
{
	return PawnType;
}

void Pawn::MousePressed(sf::Vector2i MousePosition)
{
	if (getGlobalBounds().contains(MousePosition.x, MousePosition.y))
	{
		IsMove = { true };

		MovePosition = { sf::Vector2i(MousePosition.x - getPosition().x, MousePosition.y - getPosition().y) };
	}
}

void Pawn::MouseReleased()
{
	if (IsMove)
	{
		sf::Vector2f CurrentPosition{ getPosition() };

		IsMove = { false };

		sf::Vector2f NewPosition{ sf::Vector2f(48 + (88 * static_cast<int>(getPosition().x / 88)), 48 + (88 * static_cast<int>(getPosition().y / 88))) };

		setPosition(NewPosition);

		SetPosition();
	}
}

void Pawn::Move(sf::Vector2i MousePosition)
{
	if (IsMove)
	{
		setPosition(MousePosition.x - MovePosition.x, MousePosition.y - MovePosition.y);
	}
}

void Pawn::Draw(sf::RenderWindow& Window)
{
	Window.draw(*this);
}

std::string Pawn::GetPosition()
{
	return Position;
}

void Pawn::SetPosition()
{
	std::string _Position;

	_Position = { static_cast<char>(((getPosition().x - 48) / 88 + 1) + 48) };
	_Position += static_cast<char>(((getPosition().y - 48) / 88) + 97);

	Position = { _Position };
}