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

	Manager = { PawnsManager::GetInstance() };

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
					Manager->MousePressedPawns(MousePosition, Board);
				}

				break;

			case sf::Event::MouseButtonReleased:
				if (MainEvent.key.code == sf::Mouse::Left)
				{
					Manager->MouseReleasedPawns(Board);
				}

				break;

			}
		}

		Manager->MovePawns(MousePosition, Board);

		Window.clear();

		Window.draw(BoardSprite);

		Manager->DrawPawns(Window, Board);

		Window.display();
	}
}

void Draughts::PlacePawns()
{
	/*std::vector<Pawn*> Pawns;

	for (int i = 48; i < 312; i += 88)
	{
		for (int j = 48 + (1 - ((i / 88) % 2)) * 88; j < 752; j += 176)
		{
			Pawns.push_back(new Pawn(static_cast<float>(j), static_cast<float>(i), PAWNTYPE::WHITE, WhiteTexture));
		}
	}

	for (int i = 488; i < 752; i += 88)
	{
		for (int j = 48 + (1 - ((i / 88) % 2)) * 88; j < 752; j += 176)
		{
			Pawns.push_back(new Pawn(static_cast<float>(j), static_cast<float>(i), PAWNTYPE::BLACK, BlackTexture));
		}
	}

	return Pawns;*/
	
	for (int i = 1; i <= 8; ++i)
	{
		for (char j = 97; j < 105; ++j)
		{
			Board[j][i] = { nullptr };
		}
	}

	for (int i = 1; i <= 3; ++i)
	{
		for (char j = (i % 2 == 0) ? 97 : 98; j < 105; j += 2)
		{
			Board[j][i] = { new Pawn((j - 97) * 88 + 48, (i - 1) * 88 + 48, PAWNTYPE::WHITE, WhiteTexture) };
		}
	}

	for (int i = 6; i <= 8; ++i)
	{
		for (char j = (i % 2 == 1) ? 98 : 97; j < 105; j += 2)
		{
			Board[j][i] = { new Pawn((j - 97) * 88 + 48, (i - 1) * 88 + 48, PAWNTYPE::BLACK, BlackTexture) };
		}
	}
}