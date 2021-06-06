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
    int findMaxLength(vector<int> &nums)
    {
        int len = nums.size();
        int sum[len + 1];
        sum[0] = 0;
        map<int, int> idxMap;
        idxMap[0] = 0;
        int max = 0;
        for (int i = 1; i <= len; i++)
        {
            int num = nums[i - 1];
            if (num == 1)
            {
                sum[i] = sum[i - 1] + 1;
            }
            else
            {
                sum[i] = sum[i - 1];
            }
            int tmp = 2 * sum[i] - i;
#ifdef _DEBUG
            cout << "i: " << i << " sum[i]: " << sum[i] << " tmp: " << tmp << endl;
#endif
            if (idxMap.count(tmp) != 0)
            {
                int preIdx = idxMap[tmp];
                int subLen = i - preIdx;
                if (subLen > max)
                {
                    max = subLen;
                }
            }
            else
            {
                idxMap[tmp] = i;
            }
        }
        return max;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> nums1{0, 1};
    cout << s.findMaxLength(nums1) << endl;
    vector<int> nums2{0, 1, 0};
    cout << s.findMaxLength(nums2) << endl;
    return 0;
}