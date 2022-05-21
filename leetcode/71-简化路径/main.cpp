#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
//#define _DEBUG

stack<string> reverseStack(stack<string> &stk)
{
    stack<string> tmp;
    while (!stk.empty())
    {
        auto val = stk.top();
        stk.pop();
        tmp.push(val);
    }
    return tmp;
}

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> vec;
        string tmp = "";
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (tmp != "")
                {
                    vec.push_back(tmp);
                    tmp = "";
                }
            }
            else
            {
                tmp = tmp + path[i];
            }
        }
        if (tmp != "")
        {
            vec.push_back(tmp);
        }
        stack<string> stk;
        for (int i = 0; i < vec.size(); i++)
        {
            string filename = vec[i];
            if (filename == ".")
            {
                continue;
            }
            if (filename == "..")
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
                continue;
            }
            stk.push(filename);
        }
        stk = reverseStack(stk);
        string ret = "";
        while (!stk.empty())
        {
            ret += '/' + stk.top();
            stk.pop();
        }


        return ret == ""?"/":ret;
    }
};
// for test
int main()
{
    Solution s;

    cout << s.isNumber(string("0")) << endl;
    cout << s.isNumber(string("e")) << endl;
    cout << s.isNumber(string(".")) << endl;
    cout << s.isNumber(string(".1")) << endl;
    cout << s.isNumber(string("3.")) << endl;

    cout << s.isNumber(string("4e+")) << endl;
    cout << s.isNumber(string("6e6.5")) << endl;
    return 0;
}