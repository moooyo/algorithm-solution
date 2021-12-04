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
        for (int i = 0; i < len; i++)
        {
            dp[1][0] = dp[0][1] + nums[i];
            dp[1][1] = max(dp[0][1], dp[0][0]);

            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }

        return max(dp[0][1], dp[0][0]);
    }
};

// for test
int main()
{
    Solution s;
    vector<int> test1{1, 2, 3, 1};
    cout << s.rob(test1) << endl;
    vector<int> test2{2, 7, 9, 3, 1};
    cout << s.rob(test2) << endl;
    return 0;
}