#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define _DEBUG

class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        int dp[target + 1][10];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = -1;
        for (int i = 1; i <= target; i++)
        {
            int max[10] = {0};
            int tmp[10] = {0};
            for (int j = 0; j < cost.size(); j++)
            {
                int idx = j + 1;
                int val = cost[j];
                /*
#ifdef _DEBUG
                cout << "i: " << i << " val: " << val << " i - val :" << i - val << " dp[i-val][0]: " << dp[i - val][0] << endl;
#endif*/
                if (val <= i && dp[i - val][0] == -1)
                {
                    // 这里就是可以选
                    for (int k = 0; k < 10; k++)
                    {
                        tmp[k] = dp[i - val][k];
                    }
                    tmp[idx]++;

                    bool swap = true;
                    int cnt1, cnt2;
                    cnt1 = cnt2 = 0;

#ifdef _DEBUG
                    cout << "target: " << target << " i: " << i << " j: " << j << " val: " << val << endl;
                    for (int t = 1; t <= 9; t++)
                    {
                        cout << tmp[t] << " ";
                    }
                    cout << endl;
#endif
                    // 比较决定选还是不选
                    for (int k = 9; k >= 1; k--)
                    {
                        cnt1 += max[k];
                        cnt2 += tmp[k];
#ifdef _DEBUG
                        cout << "max[k]: " << max[k] << " tmp[k]: " << tmp[k] << " cnt1: " << cnt1 << " cnt2: " << cnt2 << endl;
#endif
                    }

#ifdef _DEBUG

                    cout << "cnt1: " << cnt1 << " cnt2: " << cnt2 << endl;
#endif

                    if (cnt1 > cnt2)
                    {
                        swap = false;
                    }
                    else if (cnt1 < cnt2)
                    {
                        swap = true;
                    }
                    else if (cnt1 == cnt2)
                    {
                        for (int k = 9; k >= 1; k--)
                        {
                            cnt1 += max[k];
                            cnt2 += tmp[k];
                            if (max[k] > tmp[k])
                            {
                                swap = false;
                                break;
                            }
                            else if (max[k] < tmp[k])
                            {
                                break;
                            }
                        }
                    }
                    if (swap)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            max[k] = tmp[k];
                        }
                    }
                    dp[i][0] = -1;
                }
            }
            for (int k = 1; k < 10; k++)
            {
                dp[i][k] = max[k];
            }
#ifdef _DEBUG
            cout << " i: " << i << endl;
            for (int t = 1; t <= 9; t++)
            {
                cout << tmp[t] << " ";
            }
            cout << endl;
            cout << endl;
#endif
        }
        string ret = "";
        for (int k = 9; k >= 1; k--)
        {
            int cnt = dp[target][k];
            for (int r = 0; r < cnt; r++)
            {
                ret += ('0' + k);
            }
        }
        if (ret == "")
        {
            ret += "0";
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{4, 3, 2, 5, 6, 7, 2, 5, 5};
    cout << s.largestNumber(t1, 9) << endl;

    return 0;
}