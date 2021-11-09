#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define _DEBUG
typedef struct Point
{
    int x;
    int y;
    Point(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
};
class Solution
{
public:
    class Solution
    {
    public:
        int snakesAndLadders(vector<vector<int>> &board)
        {
            int r = board.size();
            int c = board[0].size();
            map<int, Point> mMap;
            map<int, vector<int>> jumpMap;
            for (int i = r - 1; i >= 0; i--)
            {
                for (int j = 0; j < c; j++)
                {
                    int base = ((r - 1) - i) * c;
                    if (((r - 1) - i) % 2 == 1)
                    {
                        base += c;
                    }
                    int val = base + j + 1;
                    mMap[val] = Point(i, j);
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (board[i][j] != -1)
                    {
                        if (jumpMap[mMap])
                    }
                }
            }
            int maxNum = (r + 1) * (c + 1);
            int dp[maxNum + 1] = {0};
            dp[1] = 1;
            for (int i = 2; i <= maxNum; i++)
            {
                for (int j = i - 1; j >= 0 && j >= i - 6; j--)
                {
                }
            }
        }
    };
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> t1{{1, 2, 3}, {4, 0, 5}};
    cout << s.slidingPuzzle(t1) << endl;
    return 0;
}