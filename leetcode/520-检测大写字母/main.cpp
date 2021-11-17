#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.length() == 1)
        {
            return true;
        }
        bool allUpper = true;
        bool allDown = true;
        bool normal = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                allDown = false;
                if (i != 0)
                {
                    normal = false;
                }
            }
            else
            {
                allUpper = false;
            }
        }
        return allUpper || allDown || normal;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("FlaG") << endl;
    cout << s.detectCapitalUse("Flag") << endl;
    cout << s.detectCapitalUse("f") << endl;
    cout << s.detectCapitalUse("leetcode") << endl;

    return 0;
}