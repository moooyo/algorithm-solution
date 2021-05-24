#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define _DEBUG
class Solution
{
public:
    int strangePrinter(string s)
    {
        int len = s.length();
        int dp[len][len];
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }
        for (int subLen = 1; subLen < len; subLen++)
        {
            for (int i = len - 1; i >= 0; i--)
            {
                int j = i + subLen;
                if (j >= len)
                {
                    continue;
                }
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }
                int min = 99999999;
                for (int k = i; k < j; k++)
                {
                    int a = dp[i][k] + dp[k + 1][j];
                    //  cout << "i:" << i << " k:" << k << " j:" << j << " dp[i][k]: " << dp[i][k] << " dp[k+1][j]: " << dp[k + 1][j] << endl;

                    if (a < min)
                    {
                        min = a;
                    }
                }
                dp[i][j] = min;
                //cout << "i: " << i << " j: " << j << " dp[i][j]: " << dp[i][j] << endl;
            }
        }
        return dp[0][len - 1];
    }
};

// for test
int main()
{
    Solution s;
    cout << s.strangePrinter(string("tbgtgb")) << endl;

    return 0;
}