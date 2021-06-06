#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG
// submit
class Solution
{
    const int INF = 999999999;

public:
    // m 0 n 1
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        int count1[len + 1];
        int count0[len + 1];
        count1[0] = 0;
        count0[0] = 0;
        int dp[len + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++)
        {
            int tmp1, tmp0;
            count(strs[i - 1], tmp0, tmp1);
            count1[i] = tmp1;
            count0[i] = tmp0;
#ifdef _DEBUG
            cout << "i: " << i << " count0: " << tmp0 << " count1: " << tmp1 << endl;
#endif
        }
        for (int i = 1; i <= len; i++)
        {
            for (int k = 0; k <= m; k++)
            {
                for (int l = 0; l <= n; l++)
                {
                    if (k - count0[i] < 0 || l - count1[i] < 0)
                    {
                        dp[i][k][l] = dp[i - 1][k][l];
                    }
                    else
                    {
                        int max = dp[i - 1][k][l];
                        if (dp[i - 1][k - count0[i]][l - count1[i]] + 1 >= max)
                        {
                            max = dp[i - 1][k - count0[i]][l - count1[i]] + 1;
                        }
                        dp[i][k][l] = max;
                    }
#ifdef _DEBUG
                    cout << "i: " << i << " k: " << k << " l: " << l << " dp: " << dp[i][k][l] << endl;
#endif
                }
            }
        }
        int max = 0;
        for (int i = 0; i <= len; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (dp[i][j][k] >= max)
                    {
                        max = dp[i][j][k];
                    }
                }
            }
        }
        return max;
    };

    void count(string s, int &count0, int &count1)
    {
        count0 = count1 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }
        return;
    }
};

// for test
int main()
{
    Solution s;

    vector<string> t1{"10", "0001", "111001", "1", "0"};
    //    cout << s.findMaxForm(t1, 5, 3) << endl;

    vector<string> t2{"10", "0", "1"};
    cout << s.findMaxForm(t2, 1, 1) << endl;

    vector<string> t3{"11111", "100", "1101", "1101", "11000"};
    //    cout << s.findMaxForm(t3, 5, 7) << endl;
    return 0;
}
