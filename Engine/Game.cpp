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
	brd(gfx, boardLoc),
	snek({ 5,4 }),
	rng(std::random_device()()),
	obs(brd,snek),
	goal(rng, brd, snek, obs)
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
	if (isStarted)
	{
		if (!isGameOver)
		{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!(delta_loc.x == 0 && delta_loc.y == 1))
		{
			delta_loc = { 0,-1 };
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!(delta_loc.x == 0 && delta_loc.y == -1))
		{
			delta_loc = { 0,1 };
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!(delta_loc.x == -1 && delta_loc.y == 0))
		{
			delta_loc = { 1,0 };
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!(delta_loc.x == 1 && delta_loc.y == 0))
		{
			delta_loc = { -1,0 };
		}
	}
	
		snekMoveCounter++;
		if (snekMoveCounter >= snekMovePeriod)
		{
			snekMoveCounter = 0;
				
			Location next = snek.getNextHeadLoc(delta_loc);
			bool eatingGoal = goal.eating(next);
			if (eatingGoal)
			{
				goal.Respawn(rng,brd,snek,obs);
				snek.Grow();
			}
			if (!brd.IsInsideBoard(next) || snek.IsInTile(next) || obs.eating(next))
			{
				isGameOver = true;
			}
			else
			{
				snek.MoveBy(delta_loc);
			}
		}
		++snekSpeedUpCounter;
		if (snekSpeedUpCounter > speedUpPeriod)
		{
			snekSpeedUpCounter = 0;
			snekMovePeriod = std::max(6, snekMovePeriod - 1);
		}
		obsCounter++;
		if(obsCounter > obsSpawnPeriod)
		{
			obsCounter = 0;
			obs.Spawn();
			goal.Update(rng, brd, snek, obs);
		}
		}
		else
		{
			if (wnd.kbd.KeyIsPressed(VK_RETURN))
			{
				    isGameOver = false;
					obs.resetObsAmount();
					snek.resetSnake( {5,4} );
					delta_loc = { 1, 0 };
					snekMovePeriod = 16;
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
		brd.DrawBoard();
		snek.Draw(brd);
		goal.Draw(brd);
		obs.Draw();
	}
	
	if (isGameOver)
	{
		SpriteCodex::DrawGameOver(230, 210, gfx);
	}
}
