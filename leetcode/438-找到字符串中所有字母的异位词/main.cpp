#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <unordered_set>
using namespace std;
#define _DEBUG
// submit
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        if (s.length() < p.length())
        {
            return ret;
        }
        int diff[26];
#ifdef _DEBUG
        cout << "s:  " << s << " p:" << p << endl;
#endif

        memset(diff, 0, sizeof(diff));
        int len = p.length();
        int largeNum = 0;
        int lessNum = 0;
        int useless = 0;
        unordered_set<int> st;

        for (int i = 0; i < len; i++)
        {
            diff[s[i] - 'a']++;
            diff[p[i] - 'a']--;
            st.insert(p[i] - 'a');
        }
        for (int i = 0; i < 26; i++)
        {
            if (diff[i] != 0)
            {

                if (st.count(i) == 0)
                {
                    useless += diff[i];
                    continue;
                }

                if (diff[i] > 0)
                {
                    largeNum += diff[i];
                }
                if (diff[i] < 0)
                {
                    lessNum += diff[i] * -1;
                }
            }
        }

        if (largeNum == 0 && lessNum == 0 && useless == 0)
        {
            ret.push_back(0);
        }
        for (int i = 1; i <= s.length() - len; i++)
        {
#ifdef _DEBUG
            cout << "pre i: " << i << " lessNum: " << lessNum << " largeNum: " << largeNum << " uselessNum: " << useless << endl;
#endif
            int pre = s[i - 1] - 'a';
            int income = s[i + len - 1] - 'a';
            bool findPre = st.count(pre) != 0;
            bool findIncome = st.count(income) != 0;
            if (findPre)
            {
                if (diff[pre] <= 0)
                {
                    lessNum++;
                }
                else if (diff[pre] > 0)
                {
                    largeNum--;
                }
            }
            else
            {
                useless--;
            }
            diff[pre]--;

            if (findIncome)
            {
                if (diff[income] < 0)
                {
                    lessNum--;
                }
                else if (diff[income] >= 0)
                {
                    largeNum++;
                }
            }
            else
            {
                useless++;
            }

            diff[income]++;
            if (lessNum == 0 && largeNum == 0 && useless == 0)
            {
                ret.push_back(i);
            }
#ifdef _DEBUG
            cout << "after i: " << i << " " << s[i - 1] << " " << s[i + len - 1] << " lessNum: " << lessNum << " largeNum: " << largeNum << " useless: " << useless << endl;
#endif
        }
        return ret;
    }
};

void printVector(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// for test
int main()
{
    Solution s;
    /*     printVector(s.findAnagrams("cbaebabacd", "abc"));
    printVector(s.findAnagrams("abab", "ab"));
    printVector(s.findAnagrams("bpaa", "aa")); */
    printVector(s.findAnagrams("dinitrophenylhydrazinetrinitrophenylmethylnitramine", "trinitrophenylmethylnitramine"));
    return 0;
}
