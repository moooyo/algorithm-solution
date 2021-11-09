#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define _DEBUG
typedef struct Node
{
    vector<vector<int>> val;
    int step;
    Node(vector<vector<int>> &a, int b)
    {
        this->val = a;
        this->step = b;
    }
    string flag()
    {
        string ret = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int v = this->val[i][j];
                ret += to_string(v) + "_";
            }
        }
        return ret;
    }
} Node;
class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        queue<Node> q;
        Node tmp(board, 0);
        q.push(tmp);
        set<string> flag;
        string targetFlag = "1_2_3_4_5_0_";
        while (!q.empty())
        {
            Node tmp = q.front();
            q.pop();
            string nodeFlag = tmp.flag();
#ifdef _DEBUG
            cout << "nodeFlag: " << nodeFlag << endl;
#endif
            if (flag.count(nodeFlag) == 1)
            {
                continue;
            }
            flag.insert(nodeFlag);

            if (nodeFlag == targetFlag)
            {
                return tmp.step;
            }

            auto nextVec = next(tmp.val);
            for (int i = 0; i < nextVec.size(); i++)
            {
                Node nextNode(nextVec[i], tmp.step + 1);
                q.push(nextNode);
            }
        }
        return -1;
    }

    vector<vector<vector<int>>> next(vector<vector<int>> &val)
    {
        int nextStep[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<vector<int>>> ret;
        int x, y;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (val[i][j] == 0)
                {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = x + nextStep[i][0];
            int ty = y + nextStep[i][1];
            if (tx >= 0 && tx < 2 && ty >= 0 && ty < 3)
            {
                vector<vector<int>> tmp = copyVec(val);
                tmp[x][y] = tmp[tx][ty];
                tmp[tx][ty] = 0;
                ret.push_back(tmp);
            }
        }

        return ret;
    }
    vector<vector<int>> copyVec(vector<vector<int>> &val)
    {
        vector<vector<int>> ret;
        for (int i = 0; i < 2; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < 3; j++)
            {
                tmp.push_back(val[i][j]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
    void printMap(vector<vector<int>> &val)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << val[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> t1{{1, 2, 3}, {4, 0, 5}};
    cout << s.slidingPuzzle(t1) << endl;
    return 0;
}