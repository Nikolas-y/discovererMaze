#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>
#include "discoverer.h"
#include "map.h"
using namespace std;
using namespace chrono;

class Adiscoverer
{
protected:
	std::vector<std::vector<char>> memory;
	std::pair <unsigned, unsigned> pos;
	bool Scouting_time;
	system_clock::duration speed = milliseconds(100);
	system_clock::time_point backtime;
public:
	// Один действие исследователя
	virtual bool DoTick(chrono::system_clock::time_point t)
	{
		if (t - backtime > speed)
		{
			backtime = t;
			Scouting_time = true;
		}
		return true;
	}
	
	virtual void Print_Memory()
	{
		std::cout << "size : " << memory.size() << " x " << memory[0].size() << std::endl;
		for (int i = 0; i < memory.size(); i++)
		{
			for (int j = 0; j < memory[i].size(); j++)
				std::cout << memory[i][j];
			std::cout << std::endl;
		}
	}
	virtual void scouting(Cmapping&,int,int) = 0;

protected:
	virtual void _MemoryAllocationVector(Cmapping& map)
	{
		memory.resize(map.size_w(), std::vector<char>(map.size_h(), '#'));
	}
};

//class RobotDiscoverer :public Adiscoverer
//{
//public:
//	Adiscoverer::DoTick;
//	Adiscoverer::Print_Memory;
//	virtual void scouting(Cmapping& map,int width = 1,int height = 1) override
//	{
//		Scouting_time = false;
//		_MemoryAllocationVector(map);
//		std::queue<std::pair<unsigned, unsigned>> move;
//
//		move.push({ width,height });
//		memory[width][height] = ' ';
//		int koor[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
//		pos = move.front();
//			move.pop();
//		int i = 0;
//		unsigned x = pos.first
//				, y = pos.second;
//		
//		while (true)
//		{
//			while (!map.proofwall(x + koor[i][0], y + koor[i][1]))
//			{
//				if (map.proofwall(x + koor[i][0], y + koor[i][1]))
//				{
//					memory[x + koor[i][0]][y + koor[i][1]] = '#';
//				}
//				else
//					if (memory[x + koor[i][0]][y + koor[i][1]] != ' ')
//					{
//						memory[x + koor[i][0]][y + koor[i][1]] = ' ';
//						move.push({ x + koor[i][0], y + koor[i][1] });
//						Print_Memory();
//					}
// 				x += koor[i][0];
//				y += koor[i][1];
//			}
//			i = (++i) % 4;
//		}
//	}
//private:
//	Adiscoverer::_MemoryAllocationVector;
//};

class RobotDiscoverer :public Adiscoverer
{
public:
	Adiscoverer::DoTick;
	Adiscoverer::Print_Memory;
	virtual void scouting(Cmapping& map, int width = 1, int height = 1) override
	{
		Scouting_time = false;
		_MemoryAllocationVector(map);

		int koor[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
		memory[width][height] = '@';

		for (int i = 0; i < 4; ++i)
		{
			int x = width + koor[i][0]
				, y = height + koor[i][1];
			
			if (map.proofwall(x, y))
			{
				memory[x][y] = '#';
			}
			else
				if (memory[x][y] != ' ')
				{
					while (!Scouting_time) {}

					Print_Memory();
					memory[width][height] = ' ';
					memory[x][y] = ' ';
					scouting(map, x, y);
					
					memory[width][height] = '@';

					Scouting_time = false;
					while (!Scouting_time) {}
				}
				
		}
		Print_Memory();
		memory[width][height] = ' ';
	}
private:
	Adiscoverer::_MemoryAllocationVector;
};