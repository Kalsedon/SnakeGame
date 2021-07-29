#include "Board.h"

Board::Board(Graphics& gfx, Location loc)
	:
	gfx(gfx),
	boardLoc(loc)
{
	
}

void Board::DrawCell(Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension + 1, loc.y * dimension + 1, dimension - 2, dimension - 2, c);
}

void Board::DrawBoard()
{
	int x = boardLoc.x * dimension;
	int y = boardLoc.y * dimension;
	int right = x + width * dimension;
	int bottom = y + height * dimension;
	int boardwidth = width * dimension + 8;

	for (int i = x - 4; i < right + 4; i++)
	{
		for (int j = y - 4; j < bottom + 4; j++)
		{
			if (i < x || i > right || j < y || j > bottom)
			{
				gfx.PutPixel(i, j, Colors::LightGray);
			}
			
		}
	}
}

int Board::getWidth()
{
	return width;
}

int Board::getHeight()
{
	return height;
}

const Location& Board::getLoc() const
{
	return boardLoc;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	int right = boardLoc.x + width;
	int bottom = boardLoc.y + height;
	return loc.x >= boardLoc.x && loc.x < right
		&& loc.y >= boardLoc.y && loc.y < bottom;
}
