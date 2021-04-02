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

class Pawn : public sf::Sprite
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

	void SetMovePosition(sf::Vector2i _Position);
	sf::Vector2i GetMovePosition();

	void SetIsMove(bool _IsMove);
	bool GetIsMove();
	
	void SetPosition();
	std::string GetPosition();
	std::string CalcualtePosition();

};