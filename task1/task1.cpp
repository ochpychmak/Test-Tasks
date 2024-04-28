#include <iostream>
#include <string>
#include <vector>

const int MAX_ARGS = 3;

int checkArgsAmount(int argc)
{
	if (argc != MAX_ARGS)
	{
		std::cerr << "The number of arguments is either more or less than 2.";
		return argc;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	checkArgsAmount(argc);

	const int ARRAY_SIZE = std::stoi(argv[1]); // n
	std::vector<int> array(ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i + 1;
	}

	const int KEY = std::stoi(argv[2]) - 1; // m

	int result = 0;
	int index = 0;
	do {
		result = (result + array[index]); // key = 4
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
