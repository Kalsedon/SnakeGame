#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void Draw(Board& brd);
		void InitHead(const Location loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(Location& delta_loc);
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location loc);
	void MoveBy(Location& delta_loc);
	void Draw(Board& brd);
	void Grow();
private:
	static constexpr Color headColor = Colors::Green;
	static constexpr Color bodyColor = Colors::LightGray;
	static constexpr int maxSegments = 100;
    int currentsegments = 1;
	Segment segments[maxSegments];
};