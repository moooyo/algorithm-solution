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
    vector<string> permutation(string s)
    {
        int len = s.length();
        int count[256] = {0};
        for (int i = 0; i < len; i++)
        {
            int idx = getCharIdx(s[i]);
            count[idx]++;
        }
        vector<string> ret;
        char tmp[len + 1];
        memset(tmp, 0, sizeof(tmp));
        solve(count, 0, s.length(), tmp, ret);
        return ret;
    }
    void solve(int count[256], int idx, int len, char *tmp, vector<string> &ret)
    {
        if (idx == 256)
        {
            ret.push_back(string(tmp));
            return;
        }
        if (count[idx] == 0)
        {
            solve(count, idx + 1, len, tmp, ret);
            return;
        }

        vector<char *> tmpVec;
        char c = idx - 128;
#ifdef _DEBUG
        cout << "c: " << c << " cnt: " << count[idx] << " tmp: " << tmp << endl;
#endif
        find(c, count[idx], 0, len, tmp, tmpVec);
        for (int i = 0; i < tmpVec.size(); i++)
        {
            char *newTmp = tmpVec[i];
#ifdef _DEBUG
            cout << "newTmp: " << newTmp << endl;
#endif
            solve(count, idx + 1, len, newTmp, ret);
            delete newTmp;
        }
        for (auto iter = tmpVec.begin(); iter != tmpVec.end(); iter++)
        {
        }
    }
    void find(char c, int cnt, int idx, int len, char *tmp, vector<char *> &ret)
    {
#ifdef _DEBUG
        cout << "c: " << c << " cnt: " << cnt << " idx: " << idx << " tmp[idx]: " << tmp[idx] << endl;
#endif
        if (cnt == 0)
        {
            char *newTmp = new char[len + 1];
            memcpy(newTmp, tmp, sizeof(newTmp));
            ret.push_back(newTmp);
            return;
        }
        if (idx >= len)
        {
            return;
        }

        if (tmp[idx] != 0)
        {
#ifdef _DEBUG
            cout << "tmp[idx]: " << tmp[idx] << " != 0" << endl;
#endif
            find(c, cnt, idx + 1, len, tmp, ret);
            return;
        }

        // not choose
        find(c, cnt, idx + 1, len, tmp, ret);

        // choose
        tmp[idx] = c;
        find(c, cnt - 1, idx + 1, len, tmp, ret);
        tmp[idx] = 0;
    }
    int getCharIdx(char c)
    {
        return 128 + int(c);
    }
};

// for test
int main()
{
    Solution s;
    vector<string> t1 = s.permutation("aab");
    for (int i = 0; i < t1.size(); i++)
    {
        cout << t1[i] << " ";
    }
    cout << endl;
    vector<string> t2 = s.permutation("abc");
    for (int i = 0; i < t2.size(); i++)
    {
        cout << t2[i] << " ";
    }
    cout << endl;

    return 0;
}