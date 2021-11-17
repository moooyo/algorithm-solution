#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define DEBUG */

bool match(char a, char b)
{
    return a == b || b == '?';
}

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int lens = s.length();
        int lenp = p.length();
        int dp[lens + 1][lenp + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 1; j <= lenp; j++)
        {
            if (p[j - 1] == '*' && dp[0][j - 1] == 1)
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i <= lens; i++)
        {
            for (int j = 1; j <= lenp; j++)
            {
                if (p[j - 1] == '*')
                {
                    for (int r = 0; r <= i; r++)
                    {
                        if (dp[r][j - 1] == 1)
                        {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
                else if (match(s[i - 1], p[j - 1]) && dp[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                }
            }
        }
#ifdef DEBUG
        for (int i = 0; i <= lens; i++)
        {
            for (int j = 0; j <= lenp; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
#endif

        return dp[lens][lenp] == 1;
    }
};

// for test
int main()
{
    Solution s;

    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("cb", "?a") << endl;
    cout << s.isMatch("adceb", "a*b") << endl;
    cout << s.isMatch("acdcb", "a*c?b") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("adceb", "*a*b") << endl;

    return 0;
}