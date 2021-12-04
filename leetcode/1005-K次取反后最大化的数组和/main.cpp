#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
#define _DEBUG
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int remain = k;
        for (int i = 0; i < nums.size() && remain > 0; i++)
        {
            if (nums[i] >= 0)
            {
                break;
            }
            nums[i] *= -1;
            remain--;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (remain > 0)
        {
            if (remain % 2 == 0)
            {
                return sum;
            }
            int min = 0x7f7f7f7f;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < min)
                {
                    min = nums[i];
                }
            }
            return sum - 2 * min;
        }

        return sum;
    };
};
// for test
int main()
{
    Solution s;
    vector<int> t1{4, 2, 3};
    cout << s.largestSumAfterKNegations(t1, 3) << endl;
    vector<int> t2{3, -1, 0, 2};
    cout << s.largestSumAfterKNegations(t2, 3) << endl;
    return 0;
}