#pragma once

class Location
{
public:
	void Add(Location loc)
	{
		x += loc.x;
		y += loc.y;
	}
	bool operator== (const Location rhs) const
	{
		if (x == rhs.x && y == rhs.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int x;
	int y;
};
