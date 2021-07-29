#pragma once
#include "Board.h"
#include <assert.h>
class Snake
{
private:
	class Segment
	{
	public:
		void Draw(Board& brd);
		void InitHead(const Location loc);
		void InitBody(Color colorcode);
		void Follow(const Segment& next);
		void MoveBy(Location& delta_loc);
		Location getLoc() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location loc);
	void MoveBy(Location& delta_loc);
	void Draw(Board& brd);
	void Grow();
	Location getNextHeadLoc(const Location& delta_loc) const;
	bool IsInTile(const Location& next) const;
private:
	static constexpr Color headColor = { 41, 123, 255 };
	static constexpr int maxSegments = 100;
	int currentsegments = 1;
	Segment segments[maxSegments];
};