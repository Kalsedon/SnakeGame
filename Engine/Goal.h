#pragma once
#include <random>
#include "Snake.h"
#include "Board.h"
#include "Location.h"
#include "Obstacles.h"
class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, Snake& snake, Obstacles& obs);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake, Obstacles& obs);
	void Draw(Board& brd);
	bool eating(const Location snekLoc);
	const Location getLoc();
private:
	Color c = { 252, 186, 3 };
	Location loc;
};