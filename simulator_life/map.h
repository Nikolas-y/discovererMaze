#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <random>
//#include "Eller's_Algorithm.cpp"
#include "Random.h"
#include "Eller's_Algorithm.h"
#include "Empty.h"
#include <mutex>
//http://www.neocomputer.org/projects/eller.html
class Cmapping
{
private:
	std::vector<std::vector<char>> map;
	std::string NameCreation;
public:
	bool generate(unsigned width, unsigned height);
	void info();
	bool proofwall(unsigned width, unsigned height);
	unsigned size_w();
	unsigned size_h();
private:
	//проверка размеров карты
	bool _checking_size(const unsigned width, const unsigned height);
	//Cmapping() = default;
};