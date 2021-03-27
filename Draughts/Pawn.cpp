#include "Pawn.h"

Pawn::Pawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture)
	: PawnType{ _PawnType }, IsMove{ false }
{
	setPosition(x, y);
	setTexture(_Texture);
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
	IsMove = { false };
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