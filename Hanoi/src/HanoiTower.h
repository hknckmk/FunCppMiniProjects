#ifndef HANOI_TOWERS
#define HANOI_TOWERS

#include "Disk.h"
#include <iosfwd>

#include <vector>

class HanoiTowers
{
public:
	enum class Place { second, third };

	HanoiTowers(unsigned size = 5);
	void solve(Place place = Place::third, bool clear = true, int milliseconds = 300);
	friend std::ostream& operator<<(std::ostream& stream,HanoiTowers& towers);

private:
	void solveRecursively(unsigned int n, std::vector<Disk>& source, std::vector<Disk>& destination, std::vector<Disk>& reserve, bool clear, int milliseconds);
	static void move(std::vector<Disk>& source, std::vector<Disk>& dest);

	std::vector<Disk> first;
	std::vector<Disk> second;
	std::vector<Disk> third;
	const unsigned int _size;
};

#endif 