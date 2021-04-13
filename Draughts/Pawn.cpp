#include "Pawn.h"

Pawn::Pawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture)
	: PawnType{ _PawnType }, IsMove{ false }, Position{ CalcualtePosition({ x, y }) }
{
	setPosition(x, y);
	setTexture(_Texture);
}

void Pawn::MousePressed(sf::Vector2i MousePosition)
{
	if (getGlobalBounds().contains(MousePosition.x, MousePosition.y))
	{
		if (!IsMove)
		{
			IsMove = { true };
			CurrentPosition = { getPosition() };
		}

		MovePosition = { sf::Vector2i(MousePosition.x - getPosition().x, MousePosition.y - getPosition().y) };
	}
}

std::string Pawn::MouseReleased(const std::map<char, std::map<int, Pawn*>>& Board)
{
	if (IsMove)
	{
		IsMove = { false };

		sf::Vector2f NewPosition{ sf::Vector2f(48 + (88 * static_cast<int>(getPosition().x / 88)), 48 + (88 * static_cast<int>(getPosition().y / 88))) };

		for (const auto& [Character, Map] : Board)
		{
			for (const auto& [Integer, Element] : Map)
			{
				if (Element != nullptr)
				{
					if (Element->Position == Position)
					{
						setPosition(CurrentPosition);

						return "";
					}
				}
			}
		}

		if ((Position[0] + 1 == CalcualtePosition(NewPosition)[0] && Position[1] + 1 == CalcualtePosition(NewPosition)[1]) ||
			(Position[0] - 1 == CalcualtePosition(NewPosition)[0] && Position[1] + 1 == CalcualtePosition(NewPosition)[1]))
		{
			setPosition(NewPosition);

			return Position + CalcualtePosition(NewPosition);
		}

		return "";
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

std::string Pawn::CalcualtePosition(const sf::Vector2f& PositionToCalculate)
{
	std::string _Position;

	_Position = { static_cast<char>(((PositionToCalculate.x - 48) / 88 + 1) + 48) };
	_Position += static_cast<char>(((PositionToCalculate.y - 48) / 88) + 97);

	return _Position;
}