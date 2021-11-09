#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
//#define _DEBUG
#define MAXN 1000005
int vis[MAXN];
int dis[MAXN];
typedef struct Node
{
    int idx;
    int val;
    Node(int a, int b)
    {
        this->idx = a;
        this->val = b;
    }
    bool operator<(const Node &other) const
    {
        return this->val > other.val;
    }
} Node;
class Solution
{
public:
    const int INF = 99999;
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, unordered_set<int>> edge;

        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                for (int k = j + 1; k < routes[i].size(); k++)
                {
                    if (edge.count(routes[i][j]) == 0)
                    {
                        unordered_set<int> tmp;
                        edge[routes[i][j]] = tmp;
                    }
                    edge[routes[i][j]].insert(routes[i][k]);

                    if (edge.count(routes[i][k]) == 0)
                    {
                        unordered_set<int> tmp;
                        edge[routes[i][k]] = tmp;
                    }

                    edge[routes[i][k]].insert(routes[i][j]);
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < MAXN; i++)
        {
            dis[i] = INF;
        }

        priority_queue<Node> pq;
        pq.push(Node(source, 0));
        while (!pq.empty())
        {
            Node k = pq.top();
            pq.pop();
            if (vis[k.idx])
            {
                continue;
            }
            vis[k.idx] = 1;
            dis[k.idx] = k.val;
            auto unSet = edge[k.idx];
            for (auto iter = unSet.begin(); iter != unSet.end(); iter++)
            {
                int n1 = *iter;
                pq.push(Node(n1, k.val + 1));
            }
        }

        if (dis[target] != INF)
        {
            return dis[target];
        }

        return -1;
    }
};
// for test
int main()
{
    Solution s;

    vector<vector<int>> t1{{1, 2, 7}, {3, 6, 7}};
    cout << s.numBusesToDestination(t1, 1, 6) << endl;

    vector<vector<int>> t2{{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    cout << s.numBusesToDestination(t2, 15, 12) << endl;
    vector<vector<int>> t3{
        {25, 33}, {3, 5, 13, 22, 23, 29, 37, 45, 49}, {15, 16, 41, 47}, {5, 11, 17, 23, 33}, {10, 11, 12, 29, 30, 39, 45}, {2, 5, 23, 24, 33}, {1, 2, 9, 19, 20, 21, 23, 32, 34, 44}, {7, 18, 23, 24}, {1, 2, 7, 27, 36, 44}, {7, 14, 33}};
    cout << s.numBusesToDestination(t3, 7, 47) << endl;

    return 0;
}