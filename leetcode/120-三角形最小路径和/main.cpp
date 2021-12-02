#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define _DEBUG */

class Solution
{
    const int INF = 1e8 + 3;
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int maxLen = triangle.size();
        int size = triangle[maxLen - 1].size();
        int dp[maxLen + 1][size + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = triangle[0][0];
        for (int i = 2; i <= maxLen; i++)
        {
            for (int j = 1; j <= triangle[i - 1].size(); j++)
            {
                int cmpA = INF;
                int cmpB = INF;
                if (j > 1)
                {
                    cmpA = dp[i - 1][j - 1];
                }
                if (j < triangle[i - 1].size())
                {
                    cmpB = dp[i - 1][j];
                }
                dp[i][j] = min(cmpA, cmpB) + triangle[i - 1][j - 1];
#ifdef _DEBUG
                cout << "i: " << i << " j:" << j << " cmpA:" << cmpA << " cmpB:" << cmpB << "dp[i][j]: " << dp[i][j] << endl;
#endif
            }
        }
        int answer = INF;
        for (int i = 1; i <= size; i++)
        {
#ifdef _DEBUG
            cout << dp[maxLen][i] << " ";
#endif
            if (dp[maxLen][i] < answer)
            {
                answer = dp[maxLen][i];
            }
        }
        return answer;
    }
};
// for test
int main()
{
    Solution s;
    vector<vector<int>> test{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << s.minimumTotal(test) << endl;
    vector<vector<int>> test2{{-10}};
    cout << s.minimumTotal(test2) << endl;
    return 0;
}