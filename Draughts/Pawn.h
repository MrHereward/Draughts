#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

enum class PAWNTYPE : unsigned char
{
	WHITE,
	BLACK,
	WHITEQUEEN,
	BLACKQUEEN
};

class Pawn : sf::Sprite
{
private:
	PAWNTYPE PawnType;

	sf::Vector2i MovePosition{};

	std::string Position;

	bool IsMove;

public:
	Pawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture);

	void SetPawnType(PAWNTYPE _PawnType, sf::Texture _Texture);

	PAWNTYPE GetPawnType();

	void MousePressed(sf::Vector2i MousePosition);

	void MouseReleased();

	void Move(sf::Vector2i MousePosition);

	void Draw(sf::RenderWindow& Window);

	std::string GetPosition();
	void SetPosition();

};