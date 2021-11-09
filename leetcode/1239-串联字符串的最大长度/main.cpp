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
    int maxLength(vector<string> &arr)
    {
        int len = arr.size();
        int dp[len + 1][26];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++)
        {
            int choose[26] = {0};
            for (int k = 0; k < 26; k++)
            {
                choose[k] = dp[i - 1][k];
            }
            bool canChoose = true;
            string str = arr[i - 1];
            for (int j = 0; j < str.length(); j++)
            {
                char c = str[j];
                int idx = c - 'a';
                if (idx)
            }
        }
    }
};

// for test
int main()
{
    Solution s;
    /*
    vector<string> t1{"un", "iq", "ue"};
    cout << s.maxLength(t1) << endl;
    vector<string> t2{"cha", "r", "act", "ers"};
    cout << s.maxLength(t2) << endl;
    vector<string> t3{"abcdefghijklmnopqrstuvwxyz"};
    cout << s.maxLength(t3) << endl;*/
    vector<string> t4{"ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg", "ij", "ji", "kl", "lk", "mn", "nm", "op", "po"};
    cout << s.maxLength(t4) << endl;
    return 0;
}