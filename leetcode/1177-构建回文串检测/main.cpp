#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#define _DEBUG
using namespace std;
class Solution
{
    const int MAX = 26;

public:
    int char2idx(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            return c - 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            return 26 + c - 'A';
        }
        return 0;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        vector<bool> ret;
        int len = s.length();
        int count[len + 1][MAX];
        memset(count, 0, sizeof(int) * (len + 1) * MAX);
        for (int i = 1; i <= len; i++)
        {
            int idx = char2idx(s[i - 1]);
            for (int j = 0; j < MAX; j++)
            {
                count[i][j] = count[i - 1][j];
            }
            count[i][idx] = count[i - 1][idx] + 1;
        }

        for (auto iter = queries.begin(); iter != queries.end(); iter++)
        {
            vector<int> q = *iter;
            int left = q[0] + 1;
            int right = q[1] + 1;
            int k = q[2];
#ifdef _DEBUG
            cout << "left: " << left << " right: " << right << " k: " << k << endl;
#endif
            int cnt = 0;
            for (int i = 0; i < MAX; i++)
            {
                int diff = count[right][i] - count[left - 1][i];
                if (diff % 2 == 1)
                {
                    cnt++;
                }
#ifdef _DEBUG
                cout << "i: " << i << " count[right][i]:" << count[right][i] << " count[left - 1][i]:" << count[left - 1][i] << " diff:" << diff << endl;
#endif
            }
            int add1 = (cnt % 2 == 1);
            cnt = cnt / 2;

            int subLen = (right - left + 1);
            int add2 = (subLen % 2 == 1);
#ifdef _DEBUG
            cout << "cnt: " << cnt << " add1: " << add1 << " add2: " << add2 << endl;
#endif

            if (cnt + add1 - add2 > k)
            {
                ret.push_back(false);
            }
            else
            {
                ret.push_back(true);
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    string t = "qzcdmvmfinetotshixuto";
    vector<vector<int>> q{{1, 5, 1}};
    vector<bool> ret = s.canMakePaliQueries(t, q);
    for (auto iter = ret.begin(); iter != ret.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}