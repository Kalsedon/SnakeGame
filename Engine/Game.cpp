/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek({ 2,2 }),
	rng(std::random_device()()),
	goal(rng,brd,snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isGameOver && isStarted )
	{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		delta_loc = { 0,-1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		delta_loc = { 0,1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		delta_loc = { 1,0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		delta_loc = { -1,0 };
	}
	
	
		snekMoveCounter++;
		if (snekMoveCounter >= snekMovePeriod)
		{
			snekMoveCounter = 0;
			Location next = snek.getNextHeadLoc(delta_loc);
			bool eatingGoal = goal.eating(next);
			if (eatingGoal)
			{
				goal.Respawn(rng,brd,snek);
				snek.Grow();
			}
			if (!brd.IsInsideBoard(next) || snek.IsInTile(next))
			{
				isGameOver = true;
			}
			else
			{
				snek.MoveBy(delta_loc);
			}
			
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		SpriteCodex::DrawTitle(290, 210, gfx);
	}
	else
	{
		snek.Draw(brd);
		goal.Draw(brd);
	}
	
	if (isGameOver)
	{
		SpriteCodex::DrawGameOver(250, 250, gfx);
	}
}
