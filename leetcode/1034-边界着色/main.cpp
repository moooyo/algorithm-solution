#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define _DEBUG

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

int nextStep[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        queue<pair<int, int>> q;
        vector<pair<int, int>> vec;
        unordered_set<pair<int, int>, pair_hash> st;
        q.push(pair<int, int>(row, col));
        while (!q.empty())
        {
            auto point = q.front();
            cout << point.first << " " << point.second << endl;

            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = point.first + nextStep[i][0];
                int y = point.second + nextStep[i][1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == grid[point.first][point.second])
                {
                    pair<int, int> nextPoint(x, y);
                    if (st.count(nextPoint) == 1)
                    {
                        continue;
                    }
                    else
                    {
                        st.insert(nextPoint);
                        q.push(nextPoint);
                    }
                }
                else
                {
                    vec.push_back(point);
                }
            }
        }
        for (int i = 0; i < vec.size(); i++)
        {
            auto point = vec[i];
            grid[point.first][point.second] = color;
        }
        return grid;
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}