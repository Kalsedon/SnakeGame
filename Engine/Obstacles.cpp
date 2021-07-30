#include "Obstacles.h"


Obstacles::Obstacles(Board& brd, Snake& snake)
	:
	rng(std::random_device()() ),
	brd(brd),
	snake(snake)
{
}

void Obstacles::Spawn(Goal& goal)
{
	if (currentobstacles < maxobstacles)
	{
		currentobstacles++;
	
	int right = brd.getLoc().x + brd.getWidth() - 1;
	int bottom = brd.getLoc().y + brd.getHeight() - 1;
	std::uniform_int_distribution<int> xDist(brd.getLoc().x, right);
	std::uniform_int_distribution<int> yDist(brd.getLoc().y, bottom);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc) && !(newLoc == goal.getLoc()));
	
		obstacles[currentobstacles - 1].setLoc(newLoc);
	}
}

void Obstacles::Draw()
{
	for (int i = 0; i < currentobstacles; i++)
	{
		obstacles[i].Draw(brd);
	}
}

bool Obstacles::eating(const Location next) const
{
	for (int i = 0; i < currentobstacles; i++)
	{
		if (obstacles[i].getLoc() == next)
		{
			return true;
		}
	}
	return false;
}

void Obstacles::Obstacle::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location& Obstacles::Obstacle::getLoc() const
{
	return loc;
}

void Obstacles::Obstacle::setLoc(const Location in_loc)
{
	loc = in_loc;
}
