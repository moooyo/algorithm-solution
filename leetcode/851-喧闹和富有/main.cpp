#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define DEBUG
#define INF 0x7f7f7f7f
#define MAXLEN 503

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
    }
};

// for test
int main()
{
    Solution s;

    /*     vector<vector<int>> richer1{{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
        vector<int> quiet1{3, 2, 5, 4, 6, 1, 7, 0};
        printVector(s.loudAndRich(richer1, quiet1)); */

    vector<vector<int>> richer2{{0, 1}, {1, 2}};
    vector<int> quiet2{0, 1, 2};
    printVector(s.loudAndRich(richer2, quiet2));

    return 0;
}