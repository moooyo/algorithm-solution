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
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        int dp[len3 + 1][len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1; i <= len3; i++)
        {
            for (int j = 0; j <= len1 && j <= i; j++)
            {
                int k = i - j;
                if (k > len2)
                {
                    continue;
                }
                char c3 = s3[i - 1];
                if (j > 0)
                {
                    char c1 = s1[j - 1];
                    if (c1 == c3 && dp[i - 1][j - 1][k] == 1)
                    {
                        dp[i][j][k] = 1;
                    }
                }
                if (k > 0)
                {
                    char c2 = s2[k - 1];
                    if (c2 == c3 && dp[i - 1][j][k - 1] == 1)
                    {
                        dp[i][j][k] = 1;
                    }
                }
            }
        }
        return dp[len3][len1][len2];
    }
};

// for test
int main()
{
    Solution s;

    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("", "", "") << endl;
    cout << s.isInterleave("", "b", "b") << endl;
    return 0;
}