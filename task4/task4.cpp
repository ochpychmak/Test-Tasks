#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> getNumbers(const string& filename) {
    vector<int> nums;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        int number;
        nums.push_back(stoi(line));
    }
    file.close();
    return nums;
}

int getAvg(const vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return sum / nums.size();
}

int calcMoves(const vector<int>& nums, int avg) {
    int total = getAvg(nums);
    int steps = 0;
    for (int num : nums) {
        steps += abs(num - avg);
    }
    return steps;
}

int main(int argc, char *argv[]) {
    const string filename = argv[1];
    vector<int> nums = getNumbers(filename);
    int avg = getAvg(nums);
    int moves = calcMoves(nums, avg);
    cout << moves;
    return 0;
}