#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
//#define _DEBUG

class Solution
{
public:
    bool isNumber(string s)
    {
        int idx = -1;
        for (int i = 0; i < s.length(); i++)
        {
            int val = judge(s[i]);
            if (val == 2)
            {
                if (idx != -1)
                {
                    return false;
                }
                idx = i;
            }
        }
        if (idx != -1)
        {
            string s1 = s.substr(0, idx);
            string s2 = s.substr(idx + 1, s.length());
            bool f1, f2;
            f1 = f2 = false;
#ifdef _DEBUG
            cout << "e1: " << s1 << " e2: " << s2 << endl;
#endif
            if (!isPureNum(s1, f1) || !isPureNum(s2, f2))
            {
                return false;
            }
            if (f2)
            {
                return false;
            }
            return true;
        }
        bool f;
        return isPureNum(s, f);
    }
    bool isPureNum(string s, bool &findDot)
    {
        int idx = -1;
        for (int i = 0; i < s.length(); i++)
        {
            int val = judge(s[i]);
            if (val == 3)
            {
                if (idx != -1)
                {
                    return false;
                }
                idx = i;
            }
        }
        if (idx != -1)
        {
            findDot = true;
            string s1 = s.substr(0, idx);
            string s2 = s.substr(idx + 1, s.length());
#ifdef _DEBUG
            cout << "s1: " << s1 << " s2: " << s2 << endl;
#endif
            bool f1, f2;
            f1 = f2 = false;
            if (!isInterge(s1, false, true, f1) || !isInterge(s2, true, true, f2))
            {
                return false;
            }
            if (!f1 && !f2)
            {
                return false;
            }
            return true;
        }
        bool f;
        return isInterge(s, false, false, f);
    }

    bool isInterge(string s, bool flag, bool num, bool &findNUm)
    {
#ifdef _DEBUG
        cout << "s: " << s << endl;
#endif
        for (int i = 0; i < s.length(); i++)
        {
            int val = judge(s[i]);
#ifdef _DEBUG
            cout << "s[i]: " << s[i] << " val: " << val << endl;
#endif
            if (val == 4)
            {
                if (i != 0 || flag)
                {
                    return false;
                }
                flag = true;
            }
            else if (val != 1)
            {
                return false;
            }
            else
            {
                num = true;
                findNUm = true;
            }
        }

        return num;
    }

    int judge(char c)
    {
        if (c >= '0' && c <= '9')
        {
            // number
            return 1;
        }
        else if (c == 'e' || c == 'E')
        {
            // sc split
            return 2;
        }
        else if (c == '.')
        {
            // dot split
            return 3;
        }
        else if (c == '+' || c == '-')
        {
            // flag
            return 4;
        }
        else
        {
            return -1;
        }
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