#include "Draughts.h"

Draughts::Draughts()
	: Window(sf::VideoMode(Width, Height), "Draughts", sf::Style::Close)
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

	sf::Sprite WhitePawn;
	sf::Sprite BlackPawn;
	sf::Sprite WhiteQueenPawn;
	sf::Sprite BlackQueenPawn;

	WhitePawn.setTexture(WhiteTexture);
	BlackPawn.setTexture(BlackTexture);
	WhiteQueenPawn.setTexture(WhiteQueenTexture);
	BlackQueenPawn.setTexture(BlackQueenTexture);

	WhitePawn.setPosition(136, 48);
	BlackPawn.setPosition(312, 48);
	WhiteQueenPawn.setPosition(488, 48);
	BlackQueenPawn.setPosition(664, 48);

	while (Window.isOpen())
	{
		while (Window.pollEvent(MainEvent))
		{
			switch (MainEvent.type)
			{
			case sf::Event::Closed:
				Window.close();

				break;

			}
		}

		Window.clear();

		Window.draw(BoardSprite);
		Window.draw(WhitePawn);
		Window.draw(BlackPawn);
		Window.draw(WhiteQueenPawn);
		Window.draw(BlackQueenPawn);

		Window.display();
	}
}