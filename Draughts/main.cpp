#include "Draughts.h"
#include <iostream>
#include <map>

int main()
{
	auto Game{ new Draughts };
	Game->MainLoop();
	return 0;
}