#include "Goal.h"

Goal::Goal(std::mt19937& rng, Board& brd, Snake& snake, Obstacles& obs)
{
	Respawn(rng, brd, snake, obs);
}

void Goal::Respawn(std::mt19937& rng, Board& brd, Snake& snake, Obstacles& obs)
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
	} while (snake.IsInTile(newLoc) || obs.eating(newLoc));
	
	loc = newLoc;
}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

bool Goal::eating(const Location snekLoc)
{
	return
		loc == snekLoc;
}

const Location Goal::getLoc()
{
	return loc;
}
