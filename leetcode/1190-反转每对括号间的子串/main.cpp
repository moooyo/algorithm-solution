#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define _NDEBUG

// submit
class Solution
{
public:
    string reverseParentheses(string s)
    {
        s = "((" + s + "))";
        stack<char> stk;
        vector<char> tmp;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
#ifdef _DEBUG
            cout << "c: " << c << endl;
#endif
            if (c == ')')
            {
                tmp.clear();
                while (true)
                {
                    char top = stk.top();
                    stk.pop();
#ifdef _DEBUG
                    cout << "top: " << top << endl;
#endif

                    if (top == '(')
                    {
                        for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
                        {
#ifdef _DEBUG
                            cout << "iter: " << *iter << endl;
#endif
                            stk.push(*iter);
                        }
                        break;
                    }
                    else
                    {
                        tmp.push_back(top);
                    }
                }
            }
            else
            {
                stk.push(c);
            }
        }
        string ret = "";
        for (auto i = tmp.begin(); i != tmp.end(); i++)
        {
            ret += *i;
        }
        return ret;
    }
};
// for test
int main()
{
    Solution s;
    string t1 = "(abcd)";
    string t2 = "(u(love)i)";
    string t3 = "(ed(et(oc))el)";
    string t4 = "a(bcdefghijkl(mno)p)q";
    string t5 = "a(bcdefghijkl(mno)p)q";
    string t6 = "abcde";

    cout << s.reverseParentheses(t1) << endl;
    cout << s.reverseParentheses(t2) << endl;
    cout << s.reverseParentheses(t3) << endl;
    cout << s.reverseParentheses(t4) << endl;
    cout << s.reverseParentheses(t5) << endl;
    cout << s.reverseParentheses(t6) << endl;
    return 0;
}