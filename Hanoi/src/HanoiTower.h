#ifndef HANOI_TOWERS
#define HANOI_TOWERS

#include "Disk.h"
#include <iosfwd>

#include <vector>

class HanoiTowers
{
public:
	HanoiTowers(unsigned size = 5);
	void solve(bool print = true);
	friend std::ostream& operator<<(std::ostream& stream,HanoiTowers& towers);

private:
	void solveRecursively(unsigned int n, std::vector<Disk>& source, std::vector<Disk>& destination, std::vector<Disk>& reserve, bool print);
	static void move(std::vector<Disk>& source, std::vector<Disk>& dest);

	std::vector<Disk> first;
	std::vector<Disk> second;
	std::vector<Disk> third;
	const unsigned int _size;
};

#endif 