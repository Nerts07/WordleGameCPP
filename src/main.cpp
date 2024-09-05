#include <memory>
#include "worlde.h"

int main()
{
	std::unique_ptr<Wordle> wordle = std::make_unique<Wordle>();
	wordle->playGame();
	return 0;
}