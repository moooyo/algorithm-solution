#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
//#define _DEBUG
//#define _DEBUG_1
//#define _DEBUG_2
using namespace std;
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> ret;
        string now = "";
        string q[2] = {"", ""};
        for (int i = 0; i <= text.length(); i++)
        {
            if (i == text.length() || text[i] == ' ')
            {
                if (q[0] == first && q[1] == second)
                {
                    ret.push_back(now);
                }
                q[0] = q[1];
                q[1] = now;
            }
            else
            {
                now += text[i];
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    s.findOcurrences("")
            cout
        << s.numSubmatrixSumTarget(test1, 0) << endl;
    cout << s.numSubmatrixSumTarget(test2, 0) << endl;
    cout << s.numSubmatrixSumTarget(test3, 0) << endl;

    return 0;
}