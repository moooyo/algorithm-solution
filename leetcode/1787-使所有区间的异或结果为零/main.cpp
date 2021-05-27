#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG
// submit
class Solution
{
public:
    const long long INF = 10000000000;
#ifndef _DEBUG
    const long long MAX = 1 << 10;
#endif
#ifdef _DEBUG
    const long long MAX = 20;
#endif

    int minChanges(vector<int> &nums, int k)
    {
        map<int, vector<int>> numSplit;
        for (int i = 0; i < nums.size(); i++)
        {
            int mod = i % k;
            if (numSplit.count(mod) == 0)
            {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                numSplit[mod] = tmp;
            }
            else
            {
                numSplit[mod].push_back(nums[i]);
            }
        }
        map<int, map<int, int>> buket;
        vector<int> numInfo;
        for (int i = 0; i < k; i++)
        {
            numInfo = numSplit[i];
            for (int j = 0; j < numInfo.size(); j++)
            {
                int val = numInfo[j];
                if (buket[i].count(val) == 0)
                {
                    buket[i][val] = 0;
                }
                buket[i][val] = buket[i][val] + 1;
            }
        }

#ifdef _DEBUG
        cout << "DEBUG" << endl;
#endif
        int dp_before[MAX];
        int dp[MAX];
        memset(dp_before, 0, sizeof(dp_before));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++)
        {
            map<int, int> slot = buket[i];
#ifdef _DEBUG
            cout << "i: " << i << " slot: " << endl;
            for (auto idx = slot.begin(); idx != slot.end(); idx++)
            {
                cout << "k: " << idx->first << " v:" << idx->second << endl;
            }
#endif

            for (int target = 0; target < MAX; target++)
            {
                int min = MAX;
                for (auto idx = slot.begin(); idx != slot.end(); idx++)
                {
                    int key = idx->first;
                    int count = idx->second;
                    int val = target ^ key;
                    int t1, t2;
                    t1 = dp_before[val];
                    t2 = numSplit[i].size();
                    if (slot.count(key) != 0)
                    {
                        t2 = t2 - count;
                    }
                    if (i == 0 && val != 0)
                    {
                        t1 = INF;
                    }
                    int total = t1 + t2;
                    if (total < min)
                    {
                        min = total;
                    }

#ifdef _DEBUG
                    cout << "target: " << target << " key: " << key << " count: " << count << " val: " << val << endl;
#endif
#ifdef _DEBUG
                    if (val == 0)
                    {
                        cout << "t1: " << t1 << " t2: " << t2 << " total: " << total << endl;
                    }
#endif
                }
#ifdef _DEBUG
                cout << "target: " << target << " min: " << min << endl;
#endif
                dp[target] = min;
            }
            memcpy(dp_before, dp, sizeof(dp));
            memset(dp, 0, sizeof(dp));
#ifdef _DEBUG
            cout << "i: " << i << " data: ";
            for (int i = 0; i < MAX; i++)
            {
                cout << dp_before[i] << " ";
            }
            cout << endl;
#endif
        }
        return dp_before[0];
    }
};

// for test
int main()
{
    vector<int> test{1, 2, 0, 3, 0};
    Solution s;
    //cout << s.minChanges(test, 1) << endl;
    vector<int> test2{3, 4, 5, 2, 1, 7, 3, 4, 7};
    //cout << s.minChanges(test2, 3) << endl;
    vector<int> test3{1, 2, 4, 1, 2, 5, 1, 2, 6};
    cout << s.minChanges(test3, 3) << endl;

    return 0;
}
