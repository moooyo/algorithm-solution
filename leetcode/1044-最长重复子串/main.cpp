#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <cstring>
using namespace std;
#define DEBUG
#define MAXLEN int(3 * 1e4 + 3)
class Solution
{
public:
    string ret;
    int len;
    unsigned long long h[MAXLEN];
    unsigned long long powB[MAXLEN];
    void find(int left, int right, string &str)
    {
        unordered_set<unsigned long long> uset;
        if (left > right)
        {
            return;
        }
        int subLen = (left + right) / 2;
#ifdef DEBUG
        cout << "subLen:  " << subLen << " left: " << left << " right: " << right << endl;
#endif

        for (int i = 1; i <= len - subLen + 1; i++)
        {
            unsigned long long subStrHash = h[i + subLen - 1] - h[i - 1] * powB[subLen];
#ifdef DEBUG
            cout << "subLen: " << subLen << " i: " << i << " subStr: " << str.substr(i - 1, subLen) << " subh: " << (h[i + subLen - 1] - h[i - 1] * powB[subLen]) << endl;
#endif
            // string subStr = str.substr(i, subLen);
            if (uset.count(subStrHash) != 0)
            {
                ret = str.substr(i - 1, subLen);
                find(subLen + 1, right, str);
                return;
            }
            uset.insert(subStrHash);
        }
        return find(left, subLen - 1, str);
    }
    string longestDupSubstring(string s)
    {
        ret = "";
        len = s.length();
        memset(h, 0, sizeof(h));
        unsigned long long b = 10;
        h[0] = 0;
        powB[0] = 1;
        for (unsigned long long i = 1; i <= len; i++)
        {
            powB[i] = (powB[i - 1] * b);
        }

        for (unsigned long long i = 1; i <= len; i++)
        {
            h[i] = (h[i - 1] * b + s[i - 1]);
        }

        find(1, len, s);
        return ret;
    }
};
// for test
int main()
{
    Solution s;
    cout << s.longestDupSubstring("bnanan") << endl;
    return 0;
}

// abcabc