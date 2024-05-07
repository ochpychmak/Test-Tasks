#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	const uint64_t ARRAY_SIZE = stoi(argv[1]);
	vector<uint64_t> nums;
	for (uint64_t i = 1; i <= ARRAY_SIZE; i++)
	{
		nums.push_back(i);
	}
	string result;
	uint64_t index = 0;
	const uint64_t KEY = stoi(argv[2]) - 1;
	do
	{
		result += to_string(nums[index]);
		index += KEY;
		if (index >= ARRAY_SIZE)
		{
			index %= ARRAY_SIZE;
		}
	} while (index != 0);
	cout << result;
	return 0;
}
