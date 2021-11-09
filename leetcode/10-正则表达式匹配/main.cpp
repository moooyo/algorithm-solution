#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define _DEBUG */

bool match(char a, char b)
{
    return a == b || b == '.';
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
            if (p[j - 1] == '*' && dp[0][j - 2] == 1)
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i <= lens; i++)
        {
            for (int j = 1; j <= lenp; j++)
            {
                if (match(s[i - 1], p[j - 1]) && dp[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                }
                if (p[j - 1] == '*' && j >= 2 && match(s[i - 1], p[j - 2]) && (dp[i - 1][j] == 1 || dp[i][j - 2] == 1))
                {
                    dp[i][j] = 1;
                }
                //cout << p[j - 1] << " " << dp[i][j - 2] << endl;
                if (p[j - 1] == '*' && j >= 2 && !match(s[i - 1], p[j - 2]) && dp[i][j - 2] == 1)
                {
                    dp[i][j] = 1;
                }
            }
        }

#ifdef _DEBUG
        for (int i = 1; i <= lens; i++)
        {
            for (int j = 1; j <= lenp; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
#endif

        return dp[lens][lenp];
    }
};

// for test
int main()
{
    Solution s;

    string tests1 = "aa";
    string testp1 = "a";
    cout << s.isMatch(tests1, testp1) << endl;

    string tests2 = "aa";
    string testp2 = "a*";
    cout << s.isMatch(tests2, testp2) << endl;

    string tests3 = "ab";
    string testp3 = ".*";
    cout << s.isMatch(tests3, testp3) << endl;
    string tests4 = "aab";
    string testp4 = "c*a*b";
    cout << s.isMatch(tests4, testp4) << endl;

    string tests5 = "mississippi";
    string testp5 = "mis*is*p*.";
    cout << s.isMatch(tests5, testp5) << endl;

    string tests6 = "aaa";
    string testp6 = "ab*a";
    cout << s.isMatch(tests6, testp6) << endl;

    string tests7 = "aaa";
    string testp7 = "ab*a*c*a";
    cout << s.isMatch(tests7, testp7) << endl;

    string tests8 = "aaca";
    string testp8 = "an*a*c*a";
    cout << s.isMatch(tests8, testp8) << endl;

    return 0;
}