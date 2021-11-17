#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <map>
using namespace std;
/* #define _DEBUG */

class Solution
{
public:
    unsigned int parseStr(string str)
    {
        unsigned int ret = 0;
        for (int i = 0; i < str.length(); i++)
        {
            int num = str[i] - 'a';
            ret |= (1 << (num));
        }
        return ret;
    }

    int maxProduct(vector<string> &words)
    {
        vector<unsigned int> parse;
        for (int i = 0; i < words.size(); i++)
        {
            auto ret = parseStr(words[i]);
            parse.push_back(ret);
        }
#ifdef _DEBUG
        for (int i = 0; i < parse.size(); i++)
        {
            cout << parse[i] << " ";
        }
#endif
        int ret = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                auto a = parse[i];
                auto b = parse[j];
#ifdef _DEBUG
                cout << "i : " << i << " j: " << j << " i&j" << (a & b) << endl;
#endif
                if ((a & b) == 0)
                {
                    auto temp = words[i].length() * words[j].length();
                    if (temp > ret)
                    {
                        ret = temp;
                    }
                }
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    vector<string> test1{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(test1) << endl;

    return 0;
}