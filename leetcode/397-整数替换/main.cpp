#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/* #define _DEBUG */

class Solution
{
public:
    int integerReplacement(int n)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 2 * n + 1;
            if (i % 2 == 0)
            {
                dp[i] = dp[i / 2] + 1;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp[n];
    }
};

// for test
int main()
{
    Solution s;
    cout << s.integerReplacement(8) << endl;
    cout << s.integerReplacement(7) << endl;
    cout << s.integerReplacement(4) << endl;
    cout << s.integerReplacement(65535) << endl;

    return 0;
}