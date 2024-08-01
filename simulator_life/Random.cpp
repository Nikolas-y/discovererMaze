#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "Random.h"
void GenerateRandom(std::vector<std::vector<char>>& map, unsigned width, unsigned height)
{
	// Инициализируем размер конечной матрицы maze
	const unsigned output_height = height * 2 + 1;
	const unsigned output_width = width * 2 + 1;

	// Зарезервируем размер лабиринта по высоте
	map.reserve(output_height);

	std::random_device rd;
	std::mt19937 mt(rd());
	// от 0 до 2 (2 не входит) и после привидения к int будет либо 0 - где стены нет, либо 1 - стену решили установить
	std::uniform_int_distribution<int> dist(0, 2);
	for (unsigned i = 0; i < output_height; ++i)
	{
		std::vector<char> row;
		row.reserve(output_width);
		for (unsigned j = 0; j < output_width; ++j)
			// Если этот элемент в строке является ячейкой в правом нижнем угле области 2x2 - то это пустая ячейка в лабиринте
			if ((i == 0) || (j == 0) || (i == output_height - 1) || (j == output_width - 1))
				row.push_back('#');
			else
				// Если это область для стены справа или область для стены снизу - то инициализируем этот элемент пустой ячейкой в лабиринте
				if (((i % 2 == 1) && (j % 2 == 0))
					|| ((j % 2 == 1) && (i % 2 == 0)))
				{
					auto wall = dist(mt);
					if (!wall)
						row.push_back('#');
					else
						row.push_back(' ');
				}
				else
					// Во всех остальных случаях устанавливаем стену
					row.push_back(' ');

		map.push_back(std::move(row));
	}

	for (unsigned i = 1; i < output_height - 1; ++i)
	{
		for (unsigned j = 1; j < output_width - 1; ++j)
			// Если этот элемент в строке является ячейкой в правом нижнем угле области 2x2 - то это пустая ячейка в лабиринте
			if (map[i][j] == '#')
			{
				if ((i % 2 == 1) && (j % 2 == 0))
				{
					map[i - 1][j] = '#';
					map[i + 1][j] = '#';
				}
				if ((i % 2 == 0) && (j % 2 == 1))
				{
					map[i][j - 1] = '#';
					map[i][j + 1] = '#';
				}
			}
	}
}