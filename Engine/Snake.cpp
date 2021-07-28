#include "Snake.h"

Snake::Snake(const Location loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(Location& delta_loc)
{
	for (int i = currentsegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < currentsegments; i++)
	{
		segments[i].Draw(brd);
	}
}

void Snake::Grow()
{
	++currentsegments;
	segments[currentsegments - 1].InitBody();
}


void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::InitHead(const Location in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(Location& delta_loc)
{
	loc.Add(delta_loc);
}
