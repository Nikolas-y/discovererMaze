#include "map.h"
//std::mutex mut;
bool Cmapping::generate(unsigned width = 10, unsigned height = 10)
{
	// Проверим ограничения параметров на 0
	if (!_checking_size(width, height))
		return false;
	unsigned x;
	std::cout << "Enter the algorithm for creating a maze\n1 - Eller\n2 - Random\n3 - Empty" << std::endl;
	std::cin >> x;
	switch (x)
	{
	case 1:
		GenerateEller(map, width, height);
		NameCreation= "Eller";
		break;
	case 2:
		GenerateRandom(map, width, height);
		NameCreation = "Random";
		break;
	case 3:
		GenerateEmpty(map, width, height);
		NameCreation = "Empty";
		break;

	}
	return true;
}
void Cmapping::info()
{
	std::cout << NameCreation <<std::endl;
	std::cout << "Size : "<<map.size()/2<<" x "<< map[0].size() / 2 << std::endl;
	for (unsigned i = 0; i < map.size(); ++i)
	{
		for (unsigned j = 0; j < map[i].size(); ++j)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
	
	//Вывод с символами '|' & '=' 
	/*for (unsigned i = 0; i < map.size(); ++i)
	{
		for (unsigned j = 0; j < map[i].size(); ++j)
		{
			if (i == 0 || map.size() - 1 == i)
			{
				std::cout << '-';
			}
			else
			if (j == 0 || map[i].size() - 1 == j)
			{
				std::cout << '|';
			}
			else
				if (map[i][j] == '#')
				{
					if (j % 2 == 0)
						std::cout << '|';

					if (i % 2 == 0 && j % 2 == 1)
						std::cout << '=';
				}
				else
					std::cout << map[i][j];
		}
		std::cout << std::endl;
	}*/
}

bool Cmapping::proofwall(unsigned width, unsigned height)
{
	//mut.lock();
	if (map[width][height] == '#')
		return true;
	return false;
	//mut.unlock();
}
unsigned Cmapping::size_w()
{
	return map.size();
}
unsigned Cmapping::size_h()
{
	return map[0].size();
}
bool Cmapping::_checking_size(const unsigned width, const unsigned height)
{
	if (width < 1 || height < 1)
		return false;

	const auto top_limit = UINT_MAX;
	if (((top_limit - 1) / 2 <= width) || ((top_limit - 1) / 2 <= height))
		return false;

	return true;
}