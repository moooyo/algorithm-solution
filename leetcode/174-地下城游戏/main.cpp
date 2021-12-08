#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define DEBUG
#define INF (0x7f7f7f7f)
class Solution
{
public:
    int min(int a, int b) { return a < b ? a : b; }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int lenx = dungeon.size();
        int leny = dungeon[0].size();
        if (lenx == 1 && leny == 1)
        {
            return dungeon[0][0] > 0 ? 1 : -1 * dungeon[0][0] + 1;
        }

        int dp[lenx][leny];
        memset(dp, 0, sizeof(dp));
        dp[lenx - 1][leny - 1] = 1 + (dungeon[lenx - 1][leny - 1] < 0 ? -1 * dungeon[lenx - 1][leny - 1] : 0);
        for (int i = lenx - 1; i >= 0; i--)
        {
            for (int j = leny - 1; j >= 0; j--)
            {
                if (i == lenx - 1 && j == leny - 1)
                {
                    continue;
                }
                int val1, val2;
                val1 = val2 = INF;
                if (i + 1 <= lenx - 1)
                {
                    val1 = dp[i + 1][j];
                }
                if (j + 1 <= leny - 1)
                {
                    val2 = dp[i][j + 1];
                }
                dp[i][j] = min(val1, val2) - dungeon[i][j];
                if (dp[i][j] <= 0)
                {
                    dp[i][j] = 1;
                }
                // cout << "i:  " << i << " j: " << j << " dp[i][j]:" << dp[i][j] << endl;
            }
        }
        return dp[0][0];
    }
};
// for test
int main()
{
    Solution s;

    return 0;
}