#include <iostream>
#include <vector>
using namespace std;

#define _DEBUG
#define MAX 40000
int min(int x, int y)
{
    return x < y ? x : y;
}

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int minm, minn;
        minm = minn = MAX + 1;
        for (auto iter = ops.begin(); iter != ops.end(); iter++)
        {
            int a = (*iter)[0];
            int b = (*iter)[1];
            minm = min(minm, a);
            minn = min(minn, b);
        }

        int count = minm * minn;
        int max = m * n;
        return min(count, max);
    }
};
// for test
int main()
{
    Solution s;
    vector<vector<int>> test1{{2, 2}, {3, 3}};
    cout << s.maxCount(3, 3, test1) << endl;
    vector<vector<int>> test2{};
    cout << s.maxCount(3, 3, test2) << endl;

    return 0;
}