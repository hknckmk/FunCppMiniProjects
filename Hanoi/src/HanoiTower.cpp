#include "HanoiTower.h"
#include <ostream>
#include <iostream>

constexpr unsigned char light = 176;
constexpr unsigned char shade = 178;
constexpr unsigned char dark = 219;

HanoiTowers::HanoiTowers(unsigned int size) : _size {size}
{
	for (unsigned int i = 0; i < _size ; i++)
	{
		first.push_back(Disk{ _size - i });
	}
}

void HanoiTowers::solve(bool print)
{
	std::cout << *this << "\n";
	solveRecursively(_size, first, second, third, print);
}

void printOneRow(int index, std::ostream& stream, std::vector<Disk>& tower, int towerLength, int totalHeight)
{
	int currentSize = 0;
	if (index < tower.size())
		currentSize = tower[index].size;

	for (int i = 0; i < towerLength; i++)
	{
		if (i < totalHeight - currentSize)
			stream << light;

		else if (i < totalHeight)
			stream << shade;

		else if (i == totalHeight && currentSize == 0)
			stream << dark;

		else if (i <= totalHeight + currentSize)
			stream << shade;

		else
			stream << light;
	}
}

std::ostream& operator<<(std::ostream& stream, HanoiTowers& towers)
{
	int towerLength = (2 * towers._size + 1);
	int totalLength = 3 * towerLength + 2;
	int totalHeight = towers._size;

	for (int i = totalHeight - 1; i >= 0; i--)
	{
		printOneRow(i, stream, towers.first, towerLength, totalHeight);
		stream << light;
		printOneRow(i, stream, towers.second, towerLength, totalHeight);
		stream << light;
		printOneRow(i, stream, towers.third, towerLength, totalHeight);
		stream << "\n";
	}

	for (int i = 0; i < totalLength; i++)
	{
		stream << dark;
	}

	stream << "\n";

	return stream;
}


void HanoiTowers::move(std::vector<Disk>& source, std::vector<Disk>& dest)
{
	dest.push_back(source.back());
	source.pop_back();
}

void HanoiTowers::solveRecursively(unsigned int n, std::vector<Disk>& source, std::vector<Disk>& destination, std::vector<Disk>& reserve, bool print)
{
	if (n == 0)
		return;

	solveRecursively(n - 1, source, reserve, destination, print);
	move(source, destination);
	if (print)
		std::cout << *this << "\n";
	solveRecursively(n - 1, reserve, destination, source, print);
}
