#include "Draughts.h"

Draughts::Draughts()
	: Window{ sf::VideoMode(Width, Height), "Draughts", sf::Style::Close }
{
	BoardTexture.loadFromFile("Board.png");

	WhiteTexture.loadFromFile("White.png");
	BlackTexture.loadFromFile("Black.png");
	WhiteQueenTexture.loadFromFile("White queen.png");
	BlackQueenTexture.loadFromFile("Black queen.png");

	BoardSprite.setTexture(BoardTexture);
}

void Draughts::MainLoop()
{
	sf::Event MainEvent;

	sf::Vector2i MousePosition;

	PlacePawns();

	while (Window.isOpen())
	{
		MousePosition = sf::Mouse::getPosition(Window);

		while (Window.pollEvent(MainEvent))
		{
			switch (MainEvent.type)
			{
			case sf::Event::Closed:
				Window.close();

				break;

			case sf::Event::MouseButtonPressed:
				if (MainEvent.key.code == sf::Mouse::Left)
				{
					for (const auto& Element : Pawns)
					{
						Element->MousePressed(MousePosition);
					}
				}

				break;

			case sf::Event::MouseButtonReleased:
				if (MainEvent.key.code == sf::Mouse::Left)
				{
					for (const auto& Element : Pawns)
					{
						Element->MouseReleased();
					}
				}

				break;

			}
		}

		for (const auto& Element : Pawns)
		{
			Element->Move(MousePosition);
		}

		Window.clear();

		Window.draw(BoardSprite);

		for (const auto& Element : Pawns)
		{
			Element->Draw(Window);
		}

		Window.display();
	}
}

void Draughts::PlacePawns()
{
	for (int i = 48; i < 312; i += 88)
	{
		for (int j = 48 + (1 - ((i / 88) % 2)) * 88; j < 752; j += 176)
		{
			Pawns.push_back(new Pawn(j, i, PAWNTYPE::WHITE, WhiteTexture));
		}
	}

	for (int i = 488; i < 752; i += 88)
	{
		for (int j = 48 + (1 - ((i / 88) % 2)) * 88; j < 752; j += 176)
		{
			Pawns.push_back(new Pawn(j, i, PAWNTYPE::BLACK, BlackTexture));
		}
	}
}