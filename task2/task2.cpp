#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/multiprecision/cpp_dec_float.hpp>

// Boost required: https://www.boost.org/

using namespace std;
using namespace boost::multiprecision;

struct Dot
{
	cpp_dec_float_100 x, y;
};

struct Circle
{
	cpp_dec_float_100 x, y, radius;
};

enum class DotIs
{
	ON_CIRCLE,
	INSIDE,
	OUTSIDE
};

void parseDots(fstream &dotsFile, vector<Dot> &dots)
{
	string line;
	while (getline(dotsFile, line))
	{
		Dot dot;
		istringstream iss(line);
		iss >> dot.x >> dot.y;
		dots.push_back(dot);
	}
}

void printDotsPosition(const vector<Dot> &dots, const Circle &circle)
{
	for (auto const &dot : dots)
	{
		cpp_dec_float_100 distance = sqrt(pow(dot.x - circle.x, 2) + pow(dot.y - circle.y, 2));
		if (distance == circle.radius)
		{
			cout << static_cast<int>(DotIs::ON_CIRCLE);
		}
		else if (distance < circle.radius)
		{
			cout << static_cast<int>(DotIs::INSIDE);
		}
		else
		{
			cout << static_cast<int>(DotIs::OUTSIDE);
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	fstream circleData(argv[1]);
	Circle circle;
	circleData >> circle.x >> circle.y >> circle.radius;
	circleData.close();

	fstream dotsFile(argv[2]);
	vector<Dot> dots;
	parseDots(dotsFile, dots);
	dotsFile.close();

	printDotsPosition(dots, circle);

	return 0;
}
