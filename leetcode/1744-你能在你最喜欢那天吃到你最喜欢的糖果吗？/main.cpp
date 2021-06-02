#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#define _DEBUG
using namespace std;
class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<bool> ret;
        int len = candiesCount.size();
        long long sum[len];
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < len; i++)
        {
            auto count = candiesCount[i];
            if (i == 0)
            {
                sum[i] = count;
            }
            else
            {
                sum[i] = sum[i - 1] + count;
            }
        }
        for (auto query = queries.begin(); query != queries.end(); query++)
        {
            auto favoriteType = (*query)[0];
            auto favoriteDay = (*query)[1];
            auto dailyCap = (*query)[2];
            long long count1, count2, max, min;
            count1 = count2 = max = min = 0;
            count2 = sum[favoriteType];
            if (favoriteType > 0)
            {
                count1 = sum[favoriteType - 1];
            }
            max = count2 - 1;
            min = (count1 / dailyCap);
#ifdef _DEBUG
            cout << "count1: " << count1 << " count2: " << count2 << " max: " << max << " min: " << min << endl;
#endif
            if (favoriteDay >= min && favoriteDay <= max)
            {
                ret.push_back(true);
            }
            else
            {
                ret.push_back(false);
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> count{16, 38, 8, 41, 30, 31, 14, 45, 3, 2, 24, 23, 38, 30, 31, 17, 35, 4, 9, 42, 28, 18, 37, 18, 14, 46, 11, 13, 19, 3, 5, 39, 24, 48, 20, 29, 4, 19, 36, 11, 28, 49, 38, 16, 23, 24, 4, 22, 29, 35, 45, 38, 37, 40, 2, 37, 8, 41, 33, 8, 40, 27, 13, 4, 33, 5, 8, 14, 19, 35, 31, 8, 8};
    vector<vector<int>> queries{
        {43, 1054, 49}};
    auto ret = s.canEat(count, queries);
    for (auto i = ret.begin(); i != ret.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}