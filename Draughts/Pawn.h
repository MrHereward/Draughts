#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

enum class PAWNTYPE : unsigned char
{
	WHITE,
	BLACK,
};

class Pawn : public sf::Sprite
{
protected:
	PAWNTYPE PawnType;

	sf::Vector2i MovePosition{};

	std::string Position;

	bool IsMove;

public:
	Pawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture);
	
	Pawn() = default;

	virtual void MousePressed(sf::Vector2i MousePosition);

	//std::string
	virtual void MouseReleased();

	virtual void Move(sf::Vector2i MousePosition);

	virtual void Draw(sf::RenderWindow& Window);

	std::string CalcualtePosition();

};