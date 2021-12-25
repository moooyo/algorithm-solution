#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define DEBUG */

class Solution
{
public:
    int findSubStrIndx(string &source, string &target, int targetRepeatCount)
    {
        int lenSource = source.length();
        int lenTarget = target.length() * targetRepeatCount;
        for (int startIdx = 0; startIdx <= lenTarget - lenSource; startIdx++)
        {
            bool allMatch = true;
            for (int i = 0; i < source.length(); i++)
            {
                if (source[i] != target[(i + startIdx) % target.length()])
                {
                    allMatch = false;
                    break;
                }
            }
            if (allMatch)
            {
                return startIdx;
            }
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b)
    {
        int lenA = a.length();
        int lenB = b.length();

        int k = (lenB / lenA);
        if (lenB % lenA != 0)
        {
            k++;
        }

#ifdef DEBUG
        cout << "lenA: " << lenA << " lenB: " << lenB << " k: " << k << endl;
#endif
        int idx = findSubStrIndx(b, a, k);
#ifdef DEBUG
        cout << "idx all: " << idx << endl;
#endif
        if (idx == -1)
        {
            if (findSubStrIndx(b, a, k + 1) != -1)
            {
                return k + 1;
            }
            return -1;
        }
        return k;
        /*
                string subStr = a.substr(0, idx);
        #ifdef DEBUG
                cout << "substr left: " << subStr << endl;
        #endif
                bool matchSubStr = true;
                for (int i = 0; i < subStr.length(); i++)
                {
                    if (b[lenB - i - 1] != subStr[subStr.length() - i - 1])
                    {
                        matchSubStr = false;
                        break;
                    }
                }
                if (!matchSubStr)
                {
                    return -1;
                }

                if (idx + lenB < lenA * k)
                {
                    subStr = a.substr((idx + lenB) % lenA, lenA * k - lenB - idx);
        #ifdef DEBUG
                    cout << "substr right: " << subStr << endl;
        #endif
                    for (int i = 0; i < subStr.length(); i++)
                    {
                        if (b[i] != subStr[i])
                        {
                            matchSubStr = false;
                            break;
                        }
                    }
                    if (!matchSubStr)
                    {
                        return -1;
                    }
                } */
        return k;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << s.repeatedStringMatch("a", "aa") << endl;
    cout << s.repeatedStringMatch("abc", "bca") << endl;
    cout << s.repeatedStringMatch("abc", "cabcabca") << endl;
    cout << s.repeatedStringMatch("aa", "a") << endl;
    cout << s.repeatedStringMatch("abababaaba", "aabaaba") << endl;
    cout << s.repeatedStringMatch("abab", "aba") << endl;

    return 0;
}

// abcabc