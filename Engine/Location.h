#pragma once

class Location
{
public:
	void Add(Location loc)
	{
		x += loc.x;
		y += loc.y;
	}
	int x;
	int y;
};
