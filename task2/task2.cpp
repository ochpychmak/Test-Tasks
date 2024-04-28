#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

// Boost required: https://www.boost.org/

using namespace std;
using namespace boost::multiprecision;

enum class Dot {
	IS_ON_CIRCLE,
	IS_INSIDE,
	IS_OUTSIDE
};

std::vector<std::pair<cpp_int, cpp_int>> parseCoords(fstream& dots) {
	std::vector<std::pair<cpp_int, cpp_int>> coords;
	std::string line;

	while (std::getline(dots, line)) {
		std::istringstream iss(line);
		cpp_int x, y;
		if (iss >> x >> y) {
			coords.emplace_back(x, y);
		}
		if (coords.size() >= 100) {
			break;
		}
	}

	return coords;
}

Dot dotPosition(cpp_int& circleX, cpp_int& circleY, cpp_int& radius, cpp_int& dotX, cpp_int& dotY) {
	cpp_int sqrDistance = (dotX - circleX) * (dotX - circleX) + (dotY - circleY) * (dotY - circleY);

	if (sqrDistance < radius * radius) {
		return Dot::IS_INSIDE;
	}
	else if (sqrDistance == radius * radius) {
		return Dot::IS_ON_CIRCLE;
	}
	else {
		return Dot::IS_OUTSIDE;
	}
}

int main(int argc, char* argv[]) {
	string circlePath = argv[1];
	string dotsPath = argv[2];

	fstream circle(circlePath);

	string line;
	getline(circle, line);
	istringstream iss(line);
	cpp_int x, y;
	iss >> x >> y;

	getline(circle, line);
	cpp_int radius(line);

	fstream dots(dotsPath);
	std::vector<std::pair<cpp_int, cpp_int>> dotsCoords = parseCoords(dots);

	for (auto& coord : dotsCoords) {
		cout << static_cast<int>(dotPosition(x, y, radius, coord.first, coord.second)) << "\n";
	}

	circle.close();

	return 0;
}
