#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define DEBUG */

#define MAXLEN (20002)
int dp[MAXLEN][MAXLEN][2];
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int len = nums.size();
        int sum[len + 1];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= len; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int dp[len + 1][len + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++)
        {
            if (i + k > len + 1)
            {
                break;
            }

            dp[i][i + k - 1][0] = sum[i + k - 1] - sum[i - 1];
            dp[i][i + k - 1][1] = i;
#ifdef DEBUG
            printf("dp[%d][%d][0]: %d dp[1]: %d sum[%d]: %d  sum[%d]: %d\n", i, i + k - 1, dp[i][i + k - 1][0], dp[i][i + k - 1][1], i + k - 1, sum[i + k - 1], i, sum[i - 1]);
#endif
        }
        for (int subLen = k + 1; subLen <= len; subLen++)
        {
            for (int i = 1; i <= len; i++)
            {
                int j = i + subLen - 1; // total subLen个元素
                // 计算 [i....j]
                if (j > len)
                {
                    break;
                }
                int preMaxSum = dp[i][j - 1][0];
                int nowSum = sum[j] - sum[j - k];
#ifdef DEBUG
                printf("i: %d j: %d k: %d subLen: %d preMaxSum: %d nowSum: %d \n", i, j, k, subLen, preMaxSum, nowSum);
#endif
                if (nowSum > preMaxSum)
                {
                    dp[i][j][0] = nowSum;
                    dp[i][j][1] = j - k + 1;
                }
                else
                {
                    dp[i][j][0] = preMaxSum;
                    dp[i][j][1] = dp[i][j - 1][1];
                }
            }
        }

        int maxSum = 0;
        vector<int> ret;
#ifdef DEBUG
        cout << "start calculate" << endl;
#endif

        for (int i = k + 1; i < len; i++)
        {
            for (int j = i + k; j < len; j++)
            {
                if (j + k > len + 1)
                {
                    break;
                }
                int sum1 = dp[1][i - 1][0]; // [1][2]
                int sum2 = dp[i][j - 1][0]; // [3][4]
                int sum3 = dp[j][len][0];   // [5][8]
#ifdef DEBUG
                cout << "i: " << i << " j: " << j << " sum1:" << sum1 << " sum2: " << sum2 << " sum3: " << sum3 << endl;
#endif
                if (sum1 + sum2 + sum3 > maxSum)
                {
                    maxSum = sum1 + sum2 + sum3;
                    ret = vector<int>{dp[1][i - 1][1] - 1, dp[i][j - 1][1] - 1, dp[j][len][1] - 1};
                }
            }
        }
        return ret;
    }
};

void printVector(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// for test
int main()
{
    Solution s;
    vector<int> test1{1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> test2{1, 2, 1, 2, 1, 2, 1, 2, 1};
    vector<int> test3{7, 13, 20, 19, 19, 2, 10, 1, 1, 19};

    printVector(s.maxSumOfThreeSubarrays(test1, 2));
    printVector(s.maxSumOfThreeSubarrays(test2, 2));
    printVector(s.maxSumOfThreeSubarrays(test3, 3));
    return 0;
}