#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;
/* #define _DEBUG */
class Solution
{
public:
    int min(int a, int b) { return a < b ? a : b; }
    int minCut(string s)
    {
        int len = s.length();
        bool judge[len + 1][len + 1];
        memset(judge, 0, sizeof(judge));
        for (int sublen = 1; sublen <= len; sublen++)
        {
            for (int i = 1; i <= len; i++)
            {
                int j = i + sublen - 1;
                if (j > len)
                {
                    break;
                }

                char a = s[i - 1];
                char b = s[j - 1];
                bool substrJudge = false;
                if (i + 1 > j - 1)
                {
                    substrJudge = true;
                }
                else
                {
                    substrJudge = judge[i + 1][j - 1];
                }

                if (a == b && substrJudge)
                {
                    judge[i][j] = true;
                }
            }
        }
        int dp[len + 1];
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= i; j++)
            {
#ifdef _DEBUG
                string substr = s.substr(j - 1, i - j + 1); // [i,j]
                cout << "i: " << i << " j: " << j << " substr: " << substr << " judge[j][i]: " << judge[j][i] << endl;
#endif
                if (judge[j][i])
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len] - 1;
    }
};

// for test
int main()
{
    Solution s;
    /*     printVec(s.partition("aab")); */
    cout << s.minCut("aab") << endl;
    cout << s.minCut("a") << endl;
    cout << s.minCut("ab") << endl;
    cout << s.minCut("efefeefe") << endl;
    return 0;
}