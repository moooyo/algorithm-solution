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
    const int MAX = 2011; // 1010 = 0
    const int ZERO = 1010;
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int len = nums.size();
        int dp[len + 1][MAX];
        memset(dp, 0, sizeof(dp));
        dp[0][ZERO] = 1;

        for (int i = 1; i <= len; i++)
        {
            int num = nums[i - 1];
            // 选择+或者选择-
            for (int k = 1; k < MAX; k++)
            {
                if (k - num >= 0)
                {
                    dp[i][k] += dp[i - 1][k - num];
                }
                if (k + num < MAX)
                {
                    dp[i][k] += dp[i - 1][k + num];
                }
#ifdef _DEBUG
                if (dp[i][k] > 0)
                {
                    cout << "i: " << i << " k: " << k << " dp: " << dp[i][k] << endl;
                }
#endif
            }
        }
        return dp[len][ZERO + target];
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(t1, 3) << endl;
    vector<int> t2{1};
    cout << s.findTargetSumWays(t2, 1) << endl;
    return 0;
}