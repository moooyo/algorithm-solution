#include <iostream>
#include <vector>
using namespace std;

#define _DEBUG
#define MAXN 30

class Solution
{
public:
    int fib(int n)
    {
        int fibNum[MAXN + 2] = {0};
        fibNum[0] = 0;
        fibNum[1] = 1;
        for (int i = 2; i <= MAXN; i++)
        {
            fibNum[i] = fibNum[i - 1] + fibNum[i - 2];
        }
        return fibNum[n];
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