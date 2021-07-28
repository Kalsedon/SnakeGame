#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::getWidth()
{
	return width;
}

int Board::getHeight()
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x <= width
		&& loc.y >= 0 && loc.y <= height;
}
