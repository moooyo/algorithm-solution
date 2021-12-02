#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;
#define _DEBUG
class Solution
{
public:
    unordered_map<string, bool> cache;
    vector<vector<string>> partition(string s)
    {
        int len = s.length();
        bool judge[len + 1][len + 1];
        memset(judge, 0, sizeof(judge));
        for (int sublen = 1; sublen <= len; sublen++)
        {
            for (int i = 1; i <= len; i++)
            {
                int j = i + sublen - 1;
                if (j > len)
                {
                    break;
                }

                char a = s[i - 1];
                char b = s[j - 1];
                bool substrJudge = false;
                if (i + 1 > j - 1)
                {
                    substrJudge = true;
                }
                else
                {
                    substrJudge = judge[i + 1][j - 1];
                }

                if (a == b && substrJudge)
                {
                    judge[i][j] = true;
                }
            }
        }
        vector<vector<string>> dp[len + 1];
        dp[0] = vector<vector<string>>{{}};
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                string substr = s.substr(j - 1, i - j + 1); // [i,j]
#ifdef _DEBUG
                cout << "i: " << i << " j: " << j << " substr: " << substr << " judge[j][i]: " << judge[j][i] << endl;
#endif
                if (judge[j][i])
                {
                    auto vec = dp[j - 1];
                    for (int k = 0; k < vec.size(); k++)
                    {
                        vector<string> newVec = vec[k];
                        newVec.push_back(substr);
                        dp[i].push_back(newVec);
                    }
                }
            }
        }
        return dp[len];
    }
};
void printVec(vector<vector<string>> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        for (auto subIter = iter->begin(); subIter != iter->end(); subIter++)
        {
            cout << *subIter << " ";
        }
        cout << endl;
    }
}

// for test
int main()
{
    Solution s;
    /*     printVec(s.partition("aab")); */
    printVec(s.partition("efe"));
    return 0;
}