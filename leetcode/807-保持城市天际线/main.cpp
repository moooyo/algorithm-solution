#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define DEBUG
class Solution
{
public:
    int min(int a, int b) { return a < b ? a : b; }
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int len = grid.size();
        int maxx[len];
        int maxy[len];
        memset(maxx, 0, sizeof(maxx));
        memset(maxy, 0, sizeof(maxy));
        for (int i = 0; i < len; i++)
        {
            int xmax = -1;
            int ymax = -1;
            for (int j = 0; j < len; j++)
            {
                if (grid[i][j] > xmax)
                {
                    xmax = grid[i][j];
                }
                if (grid[j][i] > ymax)
                {
                    ymax = grid[j][i];
                }
            }
            maxx[i] = xmax;
            maxy[i] = ymax;
        }
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (grid[i][j] < maxx[i] && grid[i][j] < maxy[j])
                {
                    count += min(maxx[i] - grid[i][j], maxy[j] - grid[i][j]);
                }
            }
        }
        return count;
    }
};
// for test
int main()
{
    Solution s;
    vector<vector<int>> grid{{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}