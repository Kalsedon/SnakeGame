#pragma once
#include <random>
#include "Snake.h"
#include "Board.h"
#include "Location.h"
class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, Snake& snake);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board& brd);
	bool eating(const Location snek);
	const Location getLoc();
private:
	Color c = { 252, 186, 3 };
	Location loc;
};