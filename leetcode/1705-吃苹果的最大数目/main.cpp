#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
#define DEBUG
typedef struct Node
{
    Node(int b, int c)
    {
        this->end = b;
        this->count = c;
    }

    int end;
    int count;
} Node;

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.end > b.end;
    }
};

class Solution
{
public:
    int eatenApples(vector<int> &Nodes, vector<int> &days)
    {
        priority_queue<Node, vector<Node>, struct cmp> pq;
        int n = Nodes.size();
        int i = 1;
        int count = 0;
        while (i <= n || !pq.empty())
        {
            if (i <= n && days[i - 1] > 0 && Nodes[i - 1] > 0)
            {
                Node tmp(i + days[i - 1] - 1, Nodes[i - 1]);
#ifdef DEBUG
                cout << "i push: " << i << " tmp: " << tmp.end << endl;
#endif
                pq.push(tmp);
            }
            while (!pq.empty())
            {
                auto tmp = pq.top();
                pq.pop();
#ifdef DEBUG
                cout << "i: " << i << " tmp: " << tmp.end << endl;
#endif

                if (tmp.end >= i)
                {
                    count++;
                    tmp.count--;
                    if (tmp.count > 0)
                    {
                        pq.push(tmp);
                    }
                    break;
                }
            }
            i++;
        }
        return count;
    }
};

// for test
int main()
{
    Solution s;
    /*     vector<int> apples1{1, 2, 3, 5, 2};
        vector<int> days1{3, 2, 1, 4, 2};
        cout << s.eatenApples(apples1, days1) << endl; */
    vector<int> apples2{3, 0, 0, 0, 0, 2};
    vector<int> days2{3, 0, 0, 0, 0, 2};
    cout << s.eatenApples(apples2, days2) << endl;
    return 0;
}