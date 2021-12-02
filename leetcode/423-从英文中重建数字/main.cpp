#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
#define _DEBUG
class Solution
{
public:
    unordered_map<int, string> mp{
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
    };

    string originalDigits(string s)
    {
        answer = "";
        int cnt[26];
        int numCount[10];
        memset(cnt, 0, sizeof(cnt));
        memset(numCount, 0, sizeof(numCount));
        for (int i = 0; i < s.length(); i++)
        {
            cnt[s[i] - 'a']++;
        }
        numCount[8] = cnt['g'-'a'];
        numCount[4] = cnt['u'-'a'];
        numCount[2] = cnt['w'-'a'];
        numCount[6] = cnt['x'-'a'];
        numCount[0]=cnt['z'-'a'];
        numCount[1] = cnt['o'-'a'] - numCount[0] - numCount[2] - numCount[4];
        numCount[3] = cnt['t'-'a']-numCount[0]-numCount[4];
        numCount[5] = cnt['f'-'a'] - numCount[4];
        numCount[7] = cnt['v'-'a']-numCount[5];
        numCount[9] = cnt['n'-'a'] - numCount[1] - numCount[7];
            string ret = "";
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < numCount[i]; j++)
                {
                    ret += to_string(i);
                }
            }
            answer = ret;

        return ret;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
    cout << s.originalDigits("fviefuro") << endl;
    return 0;
}