#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int cnt = 0;
        int count[26];
        int diffA[26];
        int diffB[26];
        memset(count, 0, sizeof(count));
        memset(diffA, 0, sizeof(diffA));
        memset(diffB, 0, sizeof(diffB));
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                cnt++;
                diffA[s[i] - 'a']++;
                diffB[goal[i] - 'a']++;
            }
            count[s[i] - 'a']++;
        }
        bool findRepeat = false;
        bool findEqual = true;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 1)
            {
                findRepeat = true;
            }
            if (diffA[i] != diffB[i])
            {
                findEqual = false;
            }
        }

        return cnt == 2 && findEqual || cnt == 0 && findRepeat;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.buddyStrings("abcaa", "abcbb") << endl;
    cout << s.buddyStrings("aa", "aa") << endl;
    cout << s.buddyStrings("ab", "ab") << endl;
    cout << s.buddyStrings("abc", "acb") << endl;
    cout << s.buddyStrings("ab", "babbb") << endl;
    return 0;
}