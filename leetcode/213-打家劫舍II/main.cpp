#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
class Solution
{
public:
    int max(int a, int b) { return a > b ? a : b; }
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        int dp[2][2];
        // 0 偷
        // 1 不偷

        memset(dp, 0, sizeof(dp));
        // 0号位偷
        dp[0][0] = nums[0];
        dp[0][1] = -1 * 0x7f7f7f7f;
        for (int i = 1; i < len; i++)
        {
            if (i == len - 1)
            {
                // 此时一定不能偷
                dp[1][0] = -1 * 0x7f7f7f7f;
            }
            else
            {
                dp[1][0] = dp[0][1] + nums[i];
            }

            dp[1][1] = max(dp[0][1], dp[0][0]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }

        int ret1 = max(dp[0][1], dp[0][0]);

        // 0号位不偷
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[1][0] = dp[0][1] + nums[i];
            dp[1][1] = max(dp[0][1], dp[0][0]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }

        int ret2 = max(dp[0][1], dp[0][0]);

        return max(ret1, ret2);
    }
};

// for test
int main()
{
    Solution s;
    vector<int> test1{2, 3, 2};
    cout << s.rob(test1) << endl;
    vector<int> test2{1, 2, 3, 1};
    cout << s.rob(test2) << endl;
    vector<int> test3{0};
    cout << s.rob(test3) << endl;
    vector<int> test4{1, 2};
    cout << s.rob(test4) << endl;
    return 0;
}