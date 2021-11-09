#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
//#define _DEBUG
typedef struct Node
{
    string val;
    int step;
    Node(string a, int b)
    {
        this->val = a;
        this->step = b;
    }
} Node;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        queue<Node> q;
        Node tmp("0000", 0);
        q.push(tmp);
        set<string> flag;
        set<string> dMap;
        for (int i = 0; i < deadends.size(); i++)
        {
            dMap.insert(deadends[i]);
        }
        while (!q.empty())
        {
            Node tmp = q.front();
            q.pop();
            string val = tmp.val;
            if (flag.count(val) == 1)
            {
                continue;
            }
            if (dMap.count(val) == 1)
            {
                continue;
            }
            if (val == target)
            {
                return tmp.step;
            }
#ifdef _DEBUG
            cout << tmp.val << " " << tmp.step << endl;
#endif

            flag.insert(val);
            auto nextVec = next(val);
            for (int i = 0; i < nextVec.size(); i++)
            {
#ifdef _DEBUG
                cout << nextVec[i] << " ";
#endif
                Node nextNode(nextVec[i], tmp.step + 1);
                q.push(nextNode);
            }
        }
        return -1;
    }
    vector<string> next(string str)
    {
        vector<string> ret;
        int times[2] = {-1, 1};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int c = str[i] - '0';
                c = c + times[j];
                if (c == 10)
                {
                    c = 0;
                }
                else if (c == -1)
                {
                    c = 9;
                }
                string tmp(str);
                tmp[i] = c + '0';
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    vector<string> d1{"0201", "0101", "0102", "1212", "2002"};

    cout << s.openLock(d1, "0202") << endl;

    return 0;
}