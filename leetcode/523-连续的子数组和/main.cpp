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
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int len = nums.size();
        int sum[len + 1];
        map<int, int> modCount;
        modCount[0] = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= len; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
            int mod = sum[i] % k;
#ifdef _DEBUG
            cout << "sum[i]: " << sum[i] << " mod: " << mod << " diff: " << diff << endl;
#endif
            if (modCount.count(mod) != 0)
            {
                int last = modCount[mod];
                if (i - last >= 2)
                {
                    return true;
                }
            }
            else
            {
                modCount[mod] = i;
            }
        }
        return false;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> nums1{23, 2, 4, 6, 6};
    cout << s.checkSubarraySum(nums1, 7) << endl;

    vector<int> nums2{23, 2, 6, 4, 7};
    cout << s.checkSubarraySum(nums2, 13) << endl;

    return 0;
}