#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
#define _DEBUG

class Solution
{
public:
    const int INF = 99999999;
    int numSquares(int n)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int min = INF;
            for (int j = 1; j * j <= i; j++)
            {
                int r = j * j;
                int pre = i - r;
                if (dp[pre] + 1 < min)
                {
                    min = dp[pre] + 1;
                }
            }
            dp[i] = min;
        }
        return dp[n];
    }
};

// for test
int main()
{
    Solution s;

    cout << s.numSquares(12) << endl;
    cout << s.numSquares(13) << endl;
    cout << s.numSquares(6052) << endl;
    return 0;
}