/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Location.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacles.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Location boardLoc = { 4,3 };
	Board brd;
	Location delta_loc = { 1, 0 };
	Snake snek;
	std::mt19937 rng;
	Obstacles obs;
	Goal goal;
	int snekMoveCounter = 0;
	int snekMovePeriod = 16;
	int snekSpeedUpCounter = 0;
	static constexpr int speedUpPeriod = 260;
	int obsCounter = 0;
	static constexpr int obsSpawnPeriod = 300;
	bool isGameOver = false;
	bool isStarted = false;
	bool restart = false;
	/********************************/
	/*  User Variables              */
	/********************************/
};