#include "Goal.h"

Goal::Goal(std::mt19937& rng, Board& brd, Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, Board& brd, Snake& snake)
{
	int right = brd.getLoc().x + brd.getWidth() - 1;
	int bottom = brd.getLoc().y + brd.getHeight() - 1;
	std::uniform_int_distribution<int> xDist(brd.getLoc().x, right);
	std::uniform_int_distribution<int> yDist(brd.getLoc().y, bottom);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));
	
	loc = newLoc;
}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

bool Goal::eating(const Location snek)
{
	return
		loc == snek;
}

const Location Goal::getLoc()
{
	return loc;
}
