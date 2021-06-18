#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define _DEBUG
using namespace std;
class Solution
{
public:
    const int MAX = 110;
    int lastStoneWeightII(vector<int> &stones)
    {
        int len = stones.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += stones[i];
        }

        bool dp[len + 1][MAX];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= len; i++)
        {
            int stone = stones[i - 1];
            for (int j = 0; j <= sum / 2; j++)
            {
                if (j < stone)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    if (dp[i - 1][j] || dp[i - 1][j - stone])
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[len][i])
            {
                return sum - 2 * i;
            }
        }
        return 0;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeightII(t1) << endl;
    vector<int> t2{31, 26, 33, 21, 40};
    cout << s.lastStoneWeightII(t2) << endl;

    return 0;
}