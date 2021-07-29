#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx, Location loc);
	void DrawCell(Location& loc, Color c);
	void DrawBoard();
	int getWidth();
	int getHeight();
	const Location& getLoc() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int dimension = 20;
	const Location boardLoc;
	Graphics& gfx;
};