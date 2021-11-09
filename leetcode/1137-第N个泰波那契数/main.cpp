#include <iostream>
#include <vector>
using namespace std;

#define _DEBUG
#define MAXN 37

class Solution
{
public:
    int tribonacci(int n)
    {
        int trib[MAXN + 2] = {0};
        trib[0] = 0;
        trib[1] = 1;
        trib[2] = 1;
        for (int i = 3; i <= MAXN; i++)
        {
            trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];
        }
        return trib[n];
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