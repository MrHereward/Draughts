#include "Draughts.h"

int main()
{
	auto Game{ new Draughts };
	Game->MainLoop();
	return 0;
}