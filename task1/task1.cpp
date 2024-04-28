#include <iostream>
#include <string>
#include <vector>

const int MAX_ARGS = 3;

int main(int argc, char* argv[])
{
	const int ARRAY_SIZE = std::stoi(argv[1]);
	std::vector<int> array;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array.push_back(i + 1);
	}

	const int KEY = std::stoi(argv[2]) - 1;

	int result = 0;
	int index = 0;
	do {
		result = (result + array[index]);
		index += KEY;
		if (index >= ARRAY_SIZE) {
			index %= ARRAY_SIZE;
		}
		if (index > 0) {
			result *= 10;
		}
	} while (index > 0);

	std::cout << result;

	return 0;
}
