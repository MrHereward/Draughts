#pragma once
#include "Pawn.h"

class QueenPawn : public Pawn
{
public:
	QueenPawn(float x, float y, PAWNTYPE _PawnType, sf::Texture& _Texture);

	virtual void Move(sf::Vector2i MousePosition) override;
};