#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

// nlohmann's JSON required: https://github.com/nlohmann/json

using json = nlohmann::json;
using namespace std;

void updateValues(json &test, json &jValues)
{
    for (const auto &v : jValues["values"])
    {
        if (test.at("id") == v.at("id"))
        {
            test.at("value") = v.at("value");
            break;
        }
    }
    if (test.contains("values"))
    {
        for (auto &iter : test["values"])
        {
            updateValues(iter, jValues);
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream tests(argv[1]);
    if (!tests.is_open())
    {
        return 1;
    }

    json jTests = json::parse(tests);
    tests.close();

    ifstream values(argv[2]);
    if (!values.is_open())
    {
        return 1;
    }

    json jValues = json::parse(values);
    values.close();

    for (auto &iter : jTests["tests"])
    {
        updateValues(iter, jValues);
    }

    ofstream report(argv[3]);
    report << setw(4) << jTests << endl;
    report.close();

    return 0;
}
