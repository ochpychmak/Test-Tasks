#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void parseFile(fstream &file, vector<int64_t> &nums)
{
    int64_t num;
    while (file >> num)
    {
        nums.push_back(num);
    }
}

int64_t getAvg(vector<int64_t> &nums)
{
    int64_t sum = 0;
    for (const auto i : nums)
    {
        sum += i;
    }
    return static_cast<double> (sum) / nums.size();
}

int64_t getMoves(const vector<int64_t> &nums, const int64_t &avg)
{
    int64_t moves = 0;
    for (const auto i : nums)
    {
        moves += abs(i - avg);
    }
    return moves;
}

int main(int argc, char *argv[])
{
    fstream file(argv[1]);
    vector<int64_t> nums;
    parseFile(file, nums);
    file.close();
    int64_t avg = getAvg(nums);
    cout << getMoves(nums, avg);
    return 0;
}