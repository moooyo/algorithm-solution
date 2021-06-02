#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define _NDEBUG
class Solution
{

    const int MAX = 32;

public:
    int totalHammingDistance(vector<int> &nums)
    {
        int len = nums.size();
        int pre[len + 1][MAX];
        memset(pre, 0, sizeof(pre));
        int ret = 0;
        for (int i = 1; i <= len; i++)
        {
            int num = nums[i - 1];
            for (int j = 0; j < MAX; j++)
            {
                pre[i][j] = pre[i - 1][j];
                int k = (num % 2 == 1);
                int cnt1 = pre[i - 1][j];
                int cnt0 = (i - 1) - pre[i - 1][j];
                if (k == 1)
                {
                    ret = ret + cnt0;
                    pre[i][j]++;
                }
                else
                {
                    ret = ret + cnt1;
                }
#ifdef _DEBUG
                cout << "i: " << i << " j: " << j << " ret: " << ret << endl;
#endif
                num = num / 2;
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{4, 14, 2};
    vector<int> t2{1337, 7331};
    //    cout << s.totalHammingDistance(t1) << endl;
    cout << s.totalHammingDistance(t2) << endl;
    return 0;
}