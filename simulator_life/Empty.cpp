#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "Empty.h"
void GenerateEmpty(std::vector<std::vector<char>>& map, unsigned width, unsigned height)
{
	// �������������� ������ �������� ������� maze
	const unsigned output_height = height * 2 + 1;
	const unsigned output_width = width * 2 + 1;

	// ������������� ������ ��������� �� ������
	map.reserve(output_height);

	std::random_device rd;
	std::mt19937 mt(rd());
	// �� 0 �� 2 (2 �� ������) � ����� ���������� � int ����� ���� 0 - ��� ����� ���, ���� 1 - ����� ������ ����������
	std::uniform_int_distribution<int> dist(0, 2);
	for (unsigned i = 0; i < output_height; ++i)
	{
		std::vector<char> row;
		row.reserve(output_width);
		for (unsigned j = 0; j < output_width; ++j)
			if ((i == 0) || (j == 0) || (i == output_height - 1) || (j == output_width - 1))
				row.push_back('#');
			else
				row.push_back(' ');

		map.push_back(std::move(row));
	}
}