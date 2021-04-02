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

void Pawn::SetMovePosition(sf::Vector2i _Position)
{
	MovePosition = { _Position };
}

sf::Vector2i Pawn::GetMovePosition()
{
	return MovePosition;
}

void Pawn::SetIsMove(bool _IsMove)
{
	IsMove = { _IsMove };
}

bool Pawn::GetIsMove()
{
	return IsMove;
}

void Pawn::SetPosition()
{
	std::string _Position;

	_Position = { static_cast<char>(((getPosition().x - 48) / 88 + 1) + 48) };
	_Position += static_cast<char>(((getPosition().y - 48) / 88) + 97);

	Position = { _Position };
}

std::string Pawn::GetPosition()
{
	return Position;
}

std::string Pawn::CalcualtePosition()
{
	std::string _Position;

	_Position = { static_cast<char>(((getPosition().x - 48) / 88 + 1) + 48) };
	_Position += static_cast<char>(((getPosition().y - 48) / 88) + 97);

	return _Position;
}